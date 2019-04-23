#include "mainwindow.h"
#include <time.h>

#define LCTF_INIT_WAVELENGTH 1205
#define LCTF_INIT_STEADYTIME 0.5
#define SWIRWIDTH 640
#define SWIRHEIGHT 512
SWIRCamera *cameraSWIR = new SWIRCamera;
RGBCamera *cameraRGB = new RGBCamera;
LCTF *lctf = new LCTF;

////////////////////////////////RGB����߳���////////////////////////////
WorkerRGB::WorkerRGB(QObject *parent) :
QObject(parent)
{
	//cameraRGB = new RGBCamera;
	timerIdRGB = this->startTimer(framerateRGB);//���ö�ʱ���������߳�capture
}

void WorkerRGB::timerEvent(QTimerEvent *event)
{
	if (event->timerId() == timerIdRGB)
	{
		pImageFrameRGB = cameraRGB->Capture();
		cameraRGB->GetImageSize(heightRGB, widthRGB);
		matRGB = Mat(heightRGB, widthRGB, CV_8UC3, pImageFrameRGB);
		imgRGB = QImage(matRGB.data, matRGB.cols, matRGB.rows, static_cast<int>(matRGB.step), QImage::Format_RGB888);
		imgRGB = imgRGB.rgbSwapped();//RGB->BGR

		emit sendingRGB(imgRGB);//����������֡��ʾ
		emit acquringRGB(imgRGB);//��ʱ�ɲɼ�
	}
}

WorkerRGB::~WorkerRGB()
{
}

////////////////////////////////LCTF�߳���////////////////////////////
WorkerLCTF::WorkerLCTF(QObject *parent) :
QObject(parent)
{

}
void WorkerLCTF::waveLengthChanged(int wavelengthChanged)
{
	lctf->SetWavelength(wavelengthChanged);
}
WorkerLCTF::~WorkerLCTF()
{
}

///////////////////////////////SWIR����߳���//////////////////////////////
WorkerSWIR::WorkerSWIR(QObject *parent) :
QObject(parent)
{
	//cameraSWIR = new SWIRCamera;
	timerIdSWIR = this->startTimer(framerateSWIR);//���ö�ʱ���������߳�capture
}

void WorkerSWIR::timerEvent(QTimerEvent *event)
{
	//if (event->timerId() == timerIdSWIR)
	//{
		pImageFrameSWIR = cameraSWIR->Capture();
		cameraSWIR->GetImageSize(heightSWIR, widthSWIR);
		matSWIR_16 = Mat(widthSWIR, heightSWIR, CV_16UC1, pImageFrameSWIR);
		matSWIR_16 = matSWIR_16 * 4;
		matSWIR = Mat::zeros(matSWIR_16.rows, matSWIR_16.cols, CV_8UC1);
		//16λ�Ҷ�ͼת8λ��ʾ
		for (int i = 0; i < matSWIR_16.rows; i++)
		{
			for (int j = 0; j < matSWIR_16.cols; j++)
			{
				int n = matSWIR_16.at<ushort>(i, j)/256;
				matSWIR.at<uchar>(i, j) = n;
			}
		}

		imgSWIR = QImage(matSWIR.data, matSWIR.cols, matSWIR.rows, static_cast<int>(matSWIR.step), QImage::Format_Grayscale8);//Qt�汾���

		emit sendingSWIR(imgSWIR);
		emit acquringSWIR(imgSWIR);
	//}
}

void WorkerSWIR::Scan()
{
	int i = 0;
	string path;
	clock_t startExpo, endExpo, startWrite, endWrite, start, end;
	clock_t expoTime = 0;
	clock_t WriteTime = 0;
	clock_t totalTime = 0;
	double capTime = 0;
	double wTime = 0;
	double tTime = 0;

	start = clock();
	for (i = 920; i <= 1700; i = i + 15)
	{
		startExpo = clock();
		lctf->SetWavelength(i);
		path = "E://Capture//scanSWIR//" + to_string(i) + ".tiff";
		Sleep(190);

		pImageFrameSWIR = cameraSWIR->Capture();
		endExpo = clock();
		expoTime = expoTime + (endExpo - startExpo);

		startWrite = clock();
		matSWIR_16 = Mat(widthSWIR, heightSWIR, CV_16UC1, pImageFrameSWIR);
		matSWIR_16 = matSWIR_16 * 4;
		imwrite(path, matSWIR_16);
		endWrite = clock();
		WriteTime = WriteTime + (endWrite - startWrite);

		matSWIR = Mat::zeros(matSWIR_16.rows, matSWIR_16.cols, CV_8UC1);
		for (int i = 0; i < matSWIR_16.rows; i++)
		{
			for (int j = 0; j < matSWIR_16.cols; j++)
			{
				int n = matSWIR_16.at<ushort>(i, j) / 256;
				matSWIR.at<uchar>(i, j) = n;
			}
		}
		imgSWIR = QImage(matSWIR.data, matSWIR.cols, matSWIR.rows, static_cast<int>(matSWIR.step), QImage::Format_Grayscale8);//Qt�汾���
		emit sendingSWIR(imgSWIR);
	}
	end = clock();
	capTime = ((double)expoTime) / CLOCKS_PER_SEC;
	emit sendingCollectTime(capTime);

	wTime = ((double)WriteTime) / CLOCKS_PER_SEC;
	emit sendingSaveTime(wTime);

	tTime = ((double)(expoTime + WriteTime)) / CLOCKS_PER_SEC;
	//tTime = ((double)(end - start)) / CLOCKS_PER_SEC;
	emit sendingTotalTime(tTime);

	emit scanOK();
}

WorkerSWIR::~WorkerSWIR()
{
}

///////////////////////////////�������߳�////////////////////////////////////
MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	workerRGB = new WorkerRGB;
	threadRGB = new QThread;
	workerRGB->moveToThread(threadRGB);

	workerSWIR = new WorkerSWIR;
	threadSWIR = new QThread;
	workerSWIR->moveToThread(threadSWIR);

	workerLCTF = new WorkerLCTF;
	threadLCTF = new QThread;
	workerLCTF->moveToThread(threadLCTF);

	InitializeAll();//�����ʼ��
}

MainWindow::~MainWindow()
{
}

////////////////////////////////////////////////////////////////////////////
// ������InitializeAll()
// �����������ʼ��
// ���룺Null
// �����Null
// ���أ�Null
// ��ע��
// Modified by 
////////////////////////////////////////////////////////////////////////////
void MainWindow::InitializeAll()
{
	//���������߳�
	//threadRGB->quit();
	//threadRGB->terminate();
	//threadRGB->wait();
	//threadSWIR->quit();
	//threadSWIR->terminate();
	//threadSWIR->wait();

	ui.setupUi(this);
	//������󻯣���ֹ�ı��С
	//this->setWindowFlags(this->windowFlags()&~Qt::WindowMaximizeButtonHint&~Qt::WindowMinimizeButtonHint);
	//this->setWindowState(Qt::WindowFullScreen);
	this->setFixedSize(1560, 960);
	//����ռ��ʼ�û�
	this->ui.pushButton_cap1->setEnabled(false);
	this->ui.pushButton_cap2->setEnabled(false);
	this->ui.pushButton_startacq->setEnabled(false);
	this->ui.comboBox_wavelength->setEnabled(false);
	this->ui.checkBox_preview->setEnabled(false);
	this->ui.checkBox_preview2->setEnabled(false);
	this->ui.radioButton_FW->setEnabled(false);
	this->ui.radioButton_LCTF->setEnabled(false);
	//���ý����ʼ��
	config = new Configuration(this);
	//���ò�������
	//this->workerRGB->framerateRGB = this->config->framerate;//��ʱ��ͳһ֡��
	//this->workerSWIR->framerateSWIR = this->config->framerate;
	
	//���Ⲩ��ѡ��
	QStringList fq;
	int i = 900;
	for (i = 920; i <= 1700; i += 15)
	{
		QString f = QString::number(i,10);
		fq.append(f);
	}
	this->ui.comboBox_wavelength->addItems(fq);
	this->ui.radioButton_LCTF->setChecked(false);
	this->ui.comboBox_wavelength->setCurrentText(QString::number(LCTF_INIT_WAVELENGTH,10));
	
	//�����ź����
	connect(this->ui.action_config, SIGNAL(triggered()), this, SLOT(ShowConfiguration()));
	connect(this->ui.action_initial, SIGNAL(triggered()), this, SLOT(InitializeAll()));
	connect(this->ui.checkBox_preview, SIGNAL(toggled(bool)), this, SLOT(PreviewRGB(bool)));
	connect(this->ui.checkBox_preview2, SIGNAL(toggled(bool)), this, SLOT(PreviewSWIR(bool)));	
	connect(this->ui.pushButton_startacq, SIGNAL(pressed()), this, SLOT(StartAcquisition()));
	connect(this->ui.pushButton_cap1, SIGNAL(pressed()), this, SLOT(CaptureRGB()));
	connect(this->ui.pushButton_cap2, SIGNAL(pressed()), this, SLOT(CaptureSWIR()));
	connect(this->ui.pushButton_conn1, SIGNAL(pressed()), this, SLOT(ConnectRGB()));
	connect(this->ui.pushButton_conn2, SIGNAL(pressed()), this, SLOT(ConnectSWIR()));
	connect(this->ui.pushButton_disconn1, SIGNAL(pressed()), this, SLOT(DisconnectRGB()));
	connect(this->ui.pushButton_disconn2, SIGNAL(pressed()), this, SLOT(DisconnectSWIR()));
	connect(this->ui.radioButton_FW, SIGNAL(toggled(bool)), this, SLOT(FwChecked()));
	connect(this->ui.pushButton_quit, SIGNAL(pressed()), this, SLOT(Quit()));
	connect(workerRGB, SIGNAL(sendingRGB(QImage)), this, SLOT(DisplayImageRGB(QImage)), Qt::QueuedConnection);
	connect(workerSWIR, SIGNAL(sendingSWIR(QImage)), this, SLOT(DisplayImageSWIR(QImage)), Qt::QueuedConnection);
	connect(this->ui.radioButton_LCTF, SIGNAL(toggled(bool)), this, SLOT(ConnectLCTF()));
	connect(this->ui.comboBox_wavelength, SIGNAL(currentIndexChanged(QString)), this, SLOT(WavelengthSelected()));
	connect(this, SIGNAL(sendingWavelength(int)), workerLCTF, SLOT(waveLengthChanged(int)), Qt::QueuedConnection);
	connect(workerSWIR, SIGNAL(scanOK()), this, SLOT(StopAcquisition()), Qt::QueuedConnection);
	connect(this, SIGNAL(scanPrepared()), workerSWIR, SLOT(Scan()), Qt::QueuedConnection);
	connect(workerSWIR, SIGNAL(sendingCollectTime(double)), this, SLOT(DisplayCollectTime(double)), Qt::QueuedConnection);
	connect(workerSWIR, SIGNAL(sendingSaveTime(double)), this, SLOT(DisplaySaveTime(double)), Qt::QueuedConnection);
	connect(workerSWIR, SIGNAL(sendingTotalTime(double)), this, SLOT(DisplayTotalTime(double)), Qt::QueuedConnection);
	//�رմ���ʱ�ݻ������߳�
	connect(this, &MainWindow::destroyed, this, &MainWindow::DestroyAll);
	connect(this, &MainWindow::InitializeAll, this, &MainWindow::DestroyAll);
}
////////////////////////////////////////////////////////////////////////////
// ������ConnectRGB()
// ������
// ���룺Null
// �����Null
// ���أ�Null
// ��ע��
// Modified by 
////////////////////////////////////////////////////////////////////////////
bool MainWindow::ConnectRGB()
{
	bool isConnected = cameraRGB->Init();
	if (isConnected == true)
	{
		//�����߳�
		if (!threadRGB->isRunning())
		{
			threadRGB->start();
			//workerRGB->moveToThread(threadRGB);
			this->workerRGB->framerateRGB = this->config->framerate;
		}
		else
			return false;

		//����ռ��û�
		this->ui.checkBox_preview->setEnabled(true);
		this->ui.pushButton_cap1->setEnabled(true);
		this->ui.pushButton_startacq->setEnabled(true);
	}
	else
	{
		QMessageBox::warning(NULL, "Error", "Connect Failed!", QMessageBox::Ok, QMessageBox::Ok);
		return false;
	}
	return true;
}

////////////////////////////////////////////////////////////////////////////
// ������ConnectLCTF()
// ������
// ���룺Null
// �����Null
// ���أ�Null
// ��ע��
// Modified by 
////////////////////////////////////////////////////////////////////////////
bool MainWindow::ConnectLCTF()
{
	bool isConnected = lctf->Init();

	if (isConnected == true)
	{
		//�����߳�
		if (!threadLCTF->isRunning())
		{
			threadLCTF->start();
			bool setTime = lctf->SetSteadyTime(LCTF_INIT_STEADYTIME);
			bool setWl = lctf->SetWavelength(LCTF_INIT_WAVELENGTH);
		}
		else
			return false;

		//ʹ�ò���ѡ����������Բ���
		this->ui.comboBox_wavelength->setEnabled(true);
	}
	else
	{
		QMessageBox::warning(NULL, "Error", "Connect Failed!", QMessageBox::Ok, QMessageBox::Ok);
		return false;
	}

	return true;
}

////////////////////////////////////////////////////////////////////////////
// ������ConnectSWIR()
// ������
// ���룺Null
// �����Null
// ���أ�Null
// ��ע��
// Modified by 
////////////////////////////////////////////////////////////////////////////
bool MainWindow::ConnectSWIR()
{
	bool isConnected = cameraSWIR->Init();
	if (isConnected == true)
	{
		if (!threadSWIR->isRunning())
		{
			threadSWIR->start();
			//workerSWIR->moveToThread(threadSWIR);
			this->workerSWIR->framerateSWIR = this->config->framerate;
		}
		else
			return false;

		this->ui.checkBox_preview2->setEnabled(true);
		this->ui.pushButton_cap2->setEnabled(true);
		this->ui.radioButton_FW->setEnabled(true);
		this->ui.radioButton_LCTF->setEnabled(true);
		this->ui.pushButton_startacq->setEnabled(true);
	}
	else
	{
		QMessageBox::warning(NULL, "Error", "Connect Failed!", QMessageBox::Ok, QMessageBox::Ok);
		return false;
	}
	return true;
}
////////////////////////////////////////////////////////////////////////////
// ������DisplayImageRGB
// ������
// ���룺Null
// �����Null
// ���أ�Null
// ��ע��
// Modified by 
////////////////////////////////////////////////////////////////////////////
void MainWindow::DisplayImageRGB(QImage imageRGB)
{
	qDebug() << "showing a RGB image\n";
	if (!imageRGB.isNull())
	{
		//��ͼ����QImage��ʽת��ΪQPixmap
		picRGB = QPixmap::fromImage(imageRGB);
		//picRGB = picRGB.scaled(ui.label_rgbCamera->width(), ui.label_rgbCamera->height(), Qt::KeepAspectRatio);//�����������
		picRGB = picRGB.scaled(ui.label_rgbCamera->width(), ui.label_rgbCamera->height());
		this->ui.label_rgbCamera->setPixmap(picRGB);
		this->ui.label_rgbCamera->setScaledContents(true);//�޶�qlabel��С
	}
}

////////////////////////////////////////////////////////////////////////////
// ������DisplayCollectTime
// ������
// ���룺Null
// �����Null
// ���أ�Null
// ��ע��
// Modified by 
////////////////////////////////////////////////////////////////////////////
void MainWindow::DisplayCollectTime(double time)
{
	qDebug() << "showing collect time\n";
	//��ͼ����QImage��ʽת��ΪQPixmap
	double displayTime = time;

	this->ui.label_collect->setText(QString::number(displayTime, 10, 4));
	this->ui.label_collect->setScaledContents(true);//�޶�qlabel��С
}

////////////////////////////////////////////////////////////////////////////
// ������DisplaySaveTime
// ������
// ���룺Null
// �����Null
// ���أ�Null
// ��ע��
// Modified by 
////////////////////////////////////////////////////////////////////////////
void MainWindow::DisplaySaveTime(double time)
{
	qDebug() << "showing save time\n";
	//��ͼ����QImage��ʽת��ΪQPixmap
	double displayTime = time;

	this->ui.label_save->setText(QString::number(displayTime, 10, 4));
	this->ui.label_save->setScaledContents(true);//�޶�qlabel��С
}

////////////////////////////////////////////////////////////////////////////
// ������DisplayTotalTime
// ������
// ���룺Null
// �����Null
// ���أ�Null
// ��ע��
// Modified by 
////////////////////////////////////////////////////////////////////////////
void MainWindow::DisplayTotalTime(double time)
{
	qDebug() << "showing total time\n";
	//��ͼ����QImage��ʽת��ΪQPixmap
	double displayTime = time;

	this->ui.label_total->setText(QString::number(displayTime, 10, 4));
	this->ui.label_total->setScaledContents(true);//�޶�qlabel��С
}

////////////////////////////////////////////////////////////////////////////
// ������DisplayImageSWIR
// ������
// ���룺Null
// �����Null
// ���أ�Null
// ��ע��
// Modified by 
////////////////////////////////////////////////////////////////////////////
void MainWindow::DisplayImageSWIR(QImage imageSWIR)
{
	qDebug() << "showing a SWIR image\n";
	if (!imageSWIR.isNull())
	{
		//��ͼ����QImage��ʽת��ΪQPixmap
		picSWIR = QPixmap::fromImage(imageSWIR);
		//picRGB = picRGB.scaled(ui.label_rgbCamera->width(), ui.label_rgbCamera->height(), Qt::KeepAspectRatio);//�����������
		picRGB = picRGB.scaled(ui.label_swirCamera->width(), ui.label_swirCamera->height());
		this->ui.label_swirCamera->setPixmap(picSWIR);
		this->ui.label_swirCamera->setScaledContents(true);
	}
}
////////////////////////////////////////////////////////////////////////////
// ������DisconnectRGB
// ������
// ���룺Null
// �����Null
// ���أ�Null
// ��ע��
// Modified by 
////////////////////////////////////////////////////////////////////////////
void MainWindow::DisconnectRGB()
{
	cameraRGB->Fini();
	this->ui.label_rgbCamera->setText("���δ����");
}
////////////////////////////////////////////////////////////////////////////
// ������DisconnectSWIR
// ������
// ���룺Null
// �����Null
// ���أ�Null
// ��ע��
// Modified by 
////////////////////////////////////////////////////////////////////////////
void MainWindow::DisconnectSWIR()
{
	cameraSWIR->Fini();
	this->ui.label_swirCamera->setText("���δ����");
}
////////////////////////////////////////////////////////////////////////////
// ������PreviewRGB()
// ������
// ���룺Null
// �����Null
// ���أ�Null
// ��ע��
// Modified by 
////////////////////////////////////////////////////////////////////////////
void MainWindow::PreviewRGB(bool isPreviewed)
{
	if (isPreviewed == true)
	{
		threadRGB->terminate();
	}
	else
	{
		if (!threadRGB->isRunning())
		{
			threadRGB->start();
		}
	}
}

////////////////////////////////////////////////////////////////////////////
// ������PreviewSWIR()
// ������
// ���룺Null
// �����Null
// ���أ�Null
// ��ע��
// Modified by 
////////////////////////////////////////////////////////////////////////////
void MainWindow::PreviewSWIR(bool isPreviewed)
{
	if (isPreviewed == true)
	{
		threadSWIR->terminate();
	}
	else
	{
		if (!threadSWIR->isRunning())
		{
			threadSWIR->start();
		}
	}
}
////////////////////////////////////////////////////////////////////////////
// ������CaptureRGB()
// ������
// ���룺Null
// �����Null
// ���أ�Null
// ��ע��
// Modified by 
////////////////////////////////////////////////////////////////////////////
void MainWindow::CaptureRGB()
{
	/*QString filePath = QFileDialog::getSaveFileName(this, tr("Save Capture Image"), ".", tr("PNG files(*.png)"));

	if (!filePath.isEmpty())
	{
		this->workerRGB->imgRGB.save(filePath, "PNG");
		QMessageBox::information(NULL, "Save", "Saved Successfully!", QMessageBox::Ok, QMessageBox::Ok);
	}
	else
	{
		QMessageBox::information(NULL, "Save", "Save failed!", QMessageBox::Ok, QMessageBox::Ok);
	}
	*/
	pathCom = captureRGBPath + to_string(captureRGBNum) + ".png";
	imwrite(pathCom, workerRGB->matRGB);
	captureRGBNum++;
}
////////////////////////////////////////////////////////////////////////////
// ������CaptureSWIR()
// ������
// ���룺Null
// �����Null
// ���أ�Null
// ��ע��
// Modified by 
////////////////////////////////////////////////////////////////////////////
void MainWindow::CaptureSWIR()
{
	//���������ʾ��ͼƬ��8λ��
	//QString filePath = QFileDialog::getSaveFileName(this, tr("Save Capture Image"), ".", tr("TIF files(*.tiff)"));

	//if (!filePath.isEmpty())
	//{
	//	this->workerSWIR->imgSWIR.save(filePath, "TIFF");
	//	QMessageBox::information(NULL, "Save", "Saved Successfully!", QMessageBox::Ok, QMessageBox::Ok);
	//}
	//else
	//{
	//	QMessageBox::information(NULL, "Save", "Save failed!", QMessageBox::Ok, QMessageBox::Ok);
	//}

	//pathCom = captureSWIRPath + to_string(captureSWIRNum)+".tiff";
	pathCom = captureSWIRPath + to_string(captureSWIRNum)+".tiff";
	imwrite(pathCom, workerSWIR->matSWIR_16);
	captureSWIRNum++;
}
////////////////////////////////////////////////////////////////////////////
// ������StartAcquisition()
// ������
// ���룺Null
// �����Null
// ���أ�Null
// ��ע��
// Modified by 
////////////////////////////////////////////////////////////////////////////
void MainWindow::StartAcquisition()
{
	
	threadSWIR->killTimer(workerSWIR->timerIdSWIR);
	emit scanPrepared();

	//workerSWIR->killTimer(workerSWIR->framerateSWIR);
	//connect(workerRGB, SIGNAL(acquringRGB(QImage)), this, SLOT(SaveAcqImageRGB(QImage)), Qt::QueuedConnection);
	//connect(workerRGB, SIGNAL(acquringRGB(QImage)), this, SLOT(SaveAcqImageSWIR(QImage)), Qt::QueuedConnection);
}
////////////////////////////////////////////////////////////////////////////
// ������SaveAcqImageRGB()
// ������
// ���룺Null
// �����Null
// ���أ�Null
// ��ע��
// Modified by 
////////////////////////////////////////////////////////////////////////////
void MainWindow::SaveAcqImageRGB(QImage imgRGB)
{
	//�ݲ����ǲɼ�Ƶ�ʣ�����ʾ֡����ͬ
	imgRGB.save(this->config->savepath + "/rgb", "PNG");
}
////////////////////////////////////////////////////////////////////////////
// ������SaveAcqImageSWIR()
// ������
// ���룺Null
// �����Null
// ���أ�Null
// ��ע��
// Modified by 
////////////////////////////////////////////////////////////////////////////
void MainWindow::SaveAcqImageSWIR(QImage imgSWIR)
{
	//�ݲ����ǲɼ�Ƶ�ʣ�����ʾ֡����ͬ
	imgSWIR.save(this->config->savepath + "/swir", "TIFF");
}
////////////////////////////////////////////////////////////////////////////
// ������StopAcquisition()
// ������
// ���룺Null
// �����Null
// ���أ�Null
// ��ע��
// Modified by 
////////////////////////////////////////////////////////////////////////////
void MainWindow::StopAcquisition()
{
	//threadSWIR->startTimer();
	workerSWIR->timerIdSWIR = threadSWIR->startTimer(workerSWIR->framerateSWIR);
	QMessageBox::warning(NULL, "Success", "Over", QMessageBox::Ok, QMessageBox::Ok);
	//disconnect(SIGNAL(acquringRGB(QImage)));
	//disconnect(SIGNAL(acquringRGB(QImage)));
}
////////////////////////////////////////////////////////////////////////////
// ������ShowConfiguration()
// �������򿪲������ô���
// ���룺Null
// �����Null
// ���أ�Null
// ��ע��
// Modified by 
////////////////////////////////////////////////////////////////////////////
void MainWindow::ShowConfiguration()
{
	config->show();
}
////////////////////////////////////////////////////////////////////////////
// ������WavelengthSelected()
// ������
// ���룺Null
// �����Null
// ���أ�Null
// ��ע��
// Modified by 
////////////////////////////////////////////////////////////////////////////
int MainWindow::WavelengthSelected()
{
	wavelength = this->ui.comboBox_wavelength->currentText().toInt();
	//���θ�LCTF��غ�������
	emit sendingWavelength(wavelength);

	return wavelength;
}
////////////////////////////////////////////////////////////////////////////
// ������FwChecked()
// ������ѡ����Ƭ��
// ���룺Null
// �����Null
// ���أ�Null
// ��ע��
// Modified by 
////////////////////////////////////////////////////////////////////////////
void MainWindow::FwChecked()
{
	this->ui.comboBox_wavelength->setEnabled(false);

	//emit waitingFW();
}
////////////////////////////////////////////////////////////////////////////
// ������Quit()
// �������˳�ʱ���������߳�
// ���룺Null
// �����Null
// ���أ�Null
// ��ע��
// Modified by 
////////////////////////////////////////////////////////////////////////////
void MainWindow::Quit()
{
	QApplication::exit();
}
////////////////////////////////////////////////////////////////////////////
// ������DestroyAll()
// �������˳�ʱ���������߳�
// ���룺Null
// �����Null
// ���أ�Null
// ��ע��
// Modified by 
////////////////////////////////////////////////////////////////////////////
void MainWindow::DestroyAll()
{
	if (threadRGB->isFinished())
		return;
	//�˳��߳�
	threadRGB->quit();
	threadRGB->wait();
	//�ͷŶѿռ�
	delete cameraRGB;
	cameraRGB = NULL;
	delete threadRGB;
	threadRGB = NULL;

	if (threadSWIR->isFinished())
		return;
	threadSWIR->quit();
	threadSWIR->wait();
	delete cameraSWIR;
	cameraSWIR = NULL;
	delete threadSWIR;
	threadSWIR = NULL;

	if (threadLCTF->isFinished())
		return;
	threadLCTF->quit();
	threadLCTF->wait();
	delete lctf;
	lctf = NULL;
	delete workerLCTF;
	threadLCTF = NULL;
}
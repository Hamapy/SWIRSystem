#include "mainwindow.h"
#include <time.h>

#define LCTF_INIT_WAVELENGTH 1205
#define LCTF_INIT_STEADYTIME 0.5
#define SWIRWIDTH 640
#define SWIRHEIGHT 512
SWIRCamera *cameraSWIR = new SWIRCamera;
RGBCamera *cameraRGB = new RGBCamera;
LCTF *lctf = new LCTF;

////////////////////////////////RGB相机线程类////////////////////////////
WorkerRGB::WorkerRGB(QObject *parent) :
QObject(parent)
{
	//cameraRGB = new RGBCamera;
	timerIdRGB = this->startTimer(framerateRGB);//设置定时器触发子线程capture
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

		emit sendingRGB(imgRGB);//触发界面逐帧显示
		emit acquringRGB(imgRGB);//随时可采集
	}
}

WorkerRGB::~WorkerRGB()
{
}

////////////////////////////////LCTF线程类////////////////////////////
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

///////////////////////////////SWIR相机线程类//////////////////////////////
WorkerSWIR::WorkerSWIR(QObject *parent) :
QObject(parent)
{
	//cameraSWIR = new SWIRCamera;
	timerIdSWIR = this->startTimer(framerateSWIR);//设置定时器触发子线程capture
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
		//16位灰度图转8位显示
		for (int i = 0; i < matSWIR_16.rows; i++)
		{
			for (int j = 0; j < matSWIR_16.cols; j++)
			{
				int n = matSWIR_16.at<ushort>(i, j)/256;
				matSWIR.at<uchar>(i, j) = n;
			}
		}

		imgSWIR = QImage(matSWIR.data, matSWIR.cols, matSWIR.rows, static_cast<int>(matSWIR.step), QImage::Format_Grayscale8);//Qt版本相关

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
		imgSWIR = QImage(matSWIR.data, matSWIR.cols, matSWIR.rows, static_cast<int>(matSWIR.step), QImage::Format_Grayscale8);//Qt版本相关
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

///////////////////////////////界面主线程////////////////////////////////////
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

	InitializeAll();//界面初始化
}

MainWindow::~MainWindow()
{
}

////////////////////////////////////////////////////////////////////////////
// 函数：InitializeAll()
// 描述：界面初始化
// 输入：Null
// 输出：Null
// 返回：Null
// 备注：
// Modified by 
////////////////////////////////////////////////////////////////////////////
void MainWindow::InitializeAll()
{
	//重启所有线程
	//threadRGB->quit();
	//threadRGB->terminate();
	//threadRGB->wait();
	//threadSWIR->quit();
	//threadSWIR->terminate();
	//threadSWIR->wait();

	ui.setupUi(this);
	//窗口最大化，禁止改变大小
	//this->setWindowFlags(this->windowFlags()&~Qt::WindowMaximizeButtonHint&~Qt::WindowMinimizeButtonHint);
	//this->setWindowState(Qt::WindowFullScreen);
	this->setFixedSize(1560, 960);
	//界面空间初始置灰
	this->ui.pushButton_cap1->setEnabled(false);
	this->ui.pushButton_cap2->setEnabled(false);
	this->ui.pushButton_startacq->setEnabled(false);
	this->ui.comboBox_wavelength->setEnabled(false);
	this->ui.checkBox_preview->setEnabled(false);
	this->ui.checkBox_preview2->setEnabled(false);
	this->ui.radioButton_FW->setEnabled(false);
	this->ui.radioButton_LCTF->setEnabled(false);
	//配置界面初始化
	config = new Configuration(this);
	//配置参数载入
	//this->workerRGB->framerateRGB = this->config->framerate;//暂时用统一帧率
	//this->workerSWIR->framerateSWIR = this->config->framerate;
	
	//红外波段选项
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
	
	//连接信号与槽
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
	//关闭窗口时摧毁所有线程
	connect(this, &MainWindow::destroyed, this, &MainWindow::DestroyAll);
	connect(this, &MainWindow::InitializeAll, this, &MainWindow::DestroyAll);
}
////////////////////////////////////////////////////////////////////////////
// 函数：ConnectRGB()
// 描述：
// 输入：Null
// 输出：Null
// 返回：Null
// 备注：
// Modified by 
////////////////////////////////////////////////////////////////////////////
bool MainWindow::ConnectRGB()
{
	bool isConnected = cameraRGB->Init();
	if (isConnected == true)
	{
		//打开子线程
		if (!threadRGB->isRunning())
		{
			threadRGB->start();
			//workerRGB->moveToThread(threadRGB);
			this->workerRGB->framerateRGB = this->config->framerate;
		}
		else
			return false;

		//界面空间置活
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
// 函数：ConnectLCTF()
// 描述：
// 输入：Null
// 输出：Null
// 返回：Null
// 备注：
// Modified by 
////////////////////////////////////////////////////////////////////////////
bool MainWindow::ConnectLCTF()
{
	bool isConnected = lctf->Init();

	if (isConnected == true)
	{
		//打开子线程
		if (!threadLCTF->isRunning())
		{
			threadLCTF->start();
			bool setTime = lctf->SetSteadyTime(LCTF_INIT_STEADYTIME);
			bool setWl = lctf->SetWavelength(LCTF_INIT_WAVELENGTH);
		}
		else
			return false;

		//使得波段选择下拉框可以操作
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
// 函数：ConnectSWIR()
// 描述：
// 输入：Null
// 输出：Null
// 返回：Null
// 备注：
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
// 函数：DisplayImageRGB
// 描述：
// 输入：Null
// 输出：Null
// 返回：Null
// 备注：
// Modified by 
////////////////////////////////////////////////////////////////////////////
void MainWindow::DisplayImageRGB(QImage imageRGB)
{
	qDebug() << "showing a RGB image\n";
	if (!imageRGB.isNull())
	{
		//将图像由QImage格式转换为QPixmap
		picRGB = QPixmap::fromImage(imageRGB);
		//picRGB = picRGB.scaled(ui.label_rgbCamera->width(), ui.label_rgbCamera->height(), Qt::KeepAspectRatio);//保持区域比例
		picRGB = picRGB.scaled(ui.label_rgbCamera->width(), ui.label_rgbCamera->height());
		this->ui.label_rgbCamera->setPixmap(picRGB);
		this->ui.label_rgbCamera->setScaledContents(true);//限定qlabel大小
	}
}

////////////////////////////////////////////////////////////////////////////
// 函数：DisplayCollectTime
// 描述：
// 输入：Null
// 输出：Null
// 返回：Null
// 备注：
// Modified by 
////////////////////////////////////////////////////////////////////////////
void MainWindow::DisplayCollectTime(double time)
{
	qDebug() << "showing collect time\n";
	//将图像由QImage格式转换为QPixmap
	double displayTime = time;

	this->ui.label_collect->setText(QString::number(displayTime, 10, 4));
	this->ui.label_collect->setScaledContents(true);//限定qlabel大小
}

////////////////////////////////////////////////////////////////////////////
// 函数：DisplaySaveTime
// 描述：
// 输入：Null
// 输出：Null
// 返回：Null
// 备注：
// Modified by 
////////////////////////////////////////////////////////////////////////////
void MainWindow::DisplaySaveTime(double time)
{
	qDebug() << "showing save time\n";
	//将图像由QImage格式转换为QPixmap
	double displayTime = time;

	this->ui.label_save->setText(QString::number(displayTime, 10, 4));
	this->ui.label_save->setScaledContents(true);//限定qlabel大小
}

////////////////////////////////////////////////////////////////////////////
// 函数：DisplayTotalTime
// 描述：
// 输入：Null
// 输出：Null
// 返回：Null
// 备注：
// Modified by 
////////////////////////////////////////////////////////////////////////////
void MainWindow::DisplayTotalTime(double time)
{
	qDebug() << "showing total time\n";
	//将图像由QImage格式转换为QPixmap
	double displayTime = time;

	this->ui.label_total->setText(QString::number(displayTime, 10, 4));
	this->ui.label_total->setScaledContents(true);//限定qlabel大小
}

////////////////////////////////////////////////////////////////////////////
// 函数：DisplayImageSWIR
// 描述：
// 输入：Null
// 输出：Null
// 返回：Null
// 备注：
// Modified by 
////////////////////////////////////////////////////////////////////////////
void MainWindow::DisplayImageSWIR(QImage imageSWIR)
{
	qDebug() << "showing a SWIR image\n";
	if (!imageSWIR.isNull())
	{
		//将图像由QImage格式转换为QPixmap
		picSWIR = QPixmap::fromImage(imageSWIR);
		//picRGB = picRGB.scaled(ui.label_rgbCamera->width(), ui.label_rgbCamera->height(), Qt::KeepAspectRatio);//保持区域比例
		picRGB = picRGB.scaled(ui.label_swirCamera->width(), ui.label_swirCamera->height());
		this->ui.label_swirCamera->setPixmap(picSWIR);
		this->ui.label_swirCamera->setScaledContents(true);
	}
}
////////////////////////////////////////////////////////////////////////////
// 函数：DisconnectRGB
// 描述：
// 输入：Null
// 输出：Null
// 返回：Null
// 备注：
// Modified by 
////////////////////////////////////////////////////////////////////////////
void MainWindow::DisconnectRGB()
{
	cameraRGB->Fini();
	this->ui.label_rgbCamera->setText("相机未连接");
}
////////////////////////////////////////////////////////////////////////////
// 函数：DisconnectSWIR
// 描述：
// 输入：Null
// 输出：Null
// 返回：Null
// 备注：
// Modified by 
////////////////////////////////////////////////////////////////////////////
void MainWindow::DisconnectSWIR()
{
	cameraSWIR->Fini();
	this->ui.label_swirCamera->setText("相机未连接");
}
////////////////////////////////////////////////////////////////////////////
// 函数：PreviewRGB()
// 描述：
// 输入：Null
// 输出：Null
// 返回：Null
// 备注：
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
// 函数：PreviewSWIR()
// 描述：
// 输入：Null
// 输出：Null
// 返回：Null
// 备注：
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
// 函数：CaptureRGB()
// 描述：
// 输入：Null
// 输出：Null
// 返回：Null
// 备注：
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
// 函数：CaptureSWIR()
// 描述：
// 输入：Null
// 输出：Null
// 返回：Null
// 备注：
// Modified by 
////////////////////////////////////////////////////////////////////////////
void MainWindow::CaptureSWIR()
{
	//保存界面显示的图片（8位）
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
// 函数：StartAcquisition()
// 描述：
// 输入：Null
// 输出：Null
// 返回：Null
// 备注：
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
// 函数：SaveAcqImageRGB()
// 描述：
// 输入：Null
// 输出：Null
// 返回：Null
// 备注：
// Modified by 
////////////////////////////////////////////////////////////////////////////
void MainWindow::SaveAcqImageRGB(QImage imgRGB)
{
	//暂不考虑采集频率，与显示帧率相同
	imgRGB.save(this->config->savepath + "/rgb", "PNG");
}
////////////////////////////////////////////////////////////////////////////
// 函数：SaveAcqImageSWIR()
// 描述：
// 输入：Null
// 输出：Null
// 返回：Null
// 备注：
// Modified by 
////////////////////////////////////////////////////////////////////////////
void MainWindow::SaveAcqImageSWIR(QImage imgSWIR)
{
	//暂不考虑采集频率，与显示帧率相同
	imgSWIR.save(this->config->savepath + "/swir", "TIFF");
}
////////////////////////////////////////////////////////////////////////////
// 函数：StopAcquisition()
// 描述：
// 输入：Null
// 输出：Null
// 返回：Null
// 备注：
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
// 函数：ShowConfiguration()
// 描述：打开参数设置窗口
// 输入：Null
// 输出：Null
// 返回：Null
// 备注：
// Modified by 
////////////////////////////////////////////////////////////////////////////
void MainWindow::ShowConfiguration()
{
	config->show();
}
////////////////////////////////////////////////////////////////////////////
// 函数：WavelengthSelected()
// 描述：
// 输入：Null
// 输出：Null
// 返回：Null
// 备注：
// Modified by 
////////////////////////////////////////////////////////////////////////////
int MainWindow::WavelengthSelected()
{
	wavelength = this->ui.comboBox_wavelength->currentText().toInt();
	//波段给LCTF相关函数调用
	emit sendingWavelength(wavelength);

	return wavelength;
}
////////////////////////////////////////////////////////////////////////////
// 函数：FwChecked()
// 描述：选中滤片轮
// 输入：Null
// 输出：Null
// 返回：Null
// 备注：
// Modified by 
////////////////////////////////////////////////////////////////////////////
void MainWindow::FwChecked()
{
	this->ui.comboBox_wavelength->setEnabled(false);

	//emit waitingFW();
}
////////////////////////////////////////////////////////////////////////////
// 函数：Quit()
// 描述：退出时销毁所有线程
// 输入：Null
// 输出：Null
// 返回：Null
// 备注：
// Modified by 
////////////////////////////////////////////////////////////////////////////
void MainWindow::Quit()
{
	QApplication::exit();
}
////////////////////////////////////////////////////////////////////////////
// 函数：DestroyAll()
// 描述：退出时销毁所有线程
// 输入：Null
// 输出：Null
// 返回：Null
// 备注：
// Modified by 
////////////////////////////////////////////////////////////////////////////
void MainWindow::DestroyAll()
{
	if (threadRGB->isFinished())
		return;
	//退出线程
	threadRGB->quit();
	threadRGB->wait();
	//释放堆空间
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
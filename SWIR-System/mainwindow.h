#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#define LCTF_INIT_WAVELENGTH 1205
#define LCTF_INIT_STEADYTIME 0.5
#define SWIRWIDTH 640
#define SWIRHEIGHT 512

#include <QtWidgets/QMainWindow>
#include <QThread>
#include <QDebug>
#include <QTimerEvent>
#include <QFileDialog>

#include "opencv2/opencv.hpp"
#include "ui_mainwindow.h"
#include "configuration.h"
#include "rgbcamera.h"
#include "swircamera.h"
#include "lctf.h"

using namespace cv;

////////////////////////////RGB相机线程类声明////////////////////////////
class WorkerRGB : public QObject
{
	Q_OBJECT

public:
	WorkerRGB(QObject *parent = 0);
	~WorkerRGB();
	virtual void timerEvent(QTimerEvent *event);
	//virtual void run();
	friend class MainWindow;

private:
	RGBCamera *cameraRGB;
	QImage imgRGB;
	Mat matRGB;
	int framerateRGB = 0;
	int timerIdRGB;
	unsigned char*   pImageFrameRGB;
	int heightRGB;
	int widthRGB;
	
signals:
	void sendingRGB(QImage);
	void acquringRGB(QImage);
};

////////////////////////////LCTF线程类声明////////////////////////////
class WorkerLCTF : public QObject
{
	Q_OBJECT

public:
	WorkerLCTF(QObject *parent = 0);
	~WorkerLCTF();
	friend class WorkerSWIR;
	friend class MainWindow;

private:
	LCTF *lctf;

private slots:
	void waveLengthChanged(int wavelengthChanged);

};

////////////////////////////SWIR相机线程类声明////////////////////////////
class WorkerSWIR : public QObject
{
	Q_OBJECT

public:
	WorkerSWIR(QObject *parent = 0);
	~WorkerSWIR();
	virtual void timerEvent(QTimerEvent *event);
	friend class MainWindow;

private:
	SWIRCamera *cameraSWIR;
	WorkerLCTF *workerLCTF;
	QThread *threadLCTF;
	QImage imgSWIR;
	Mat matSWIR;
	Mat matSWIR_16;
	int timerIdSWIR;
	int framerateSWIR = 0;
	unsigned short* pImageFrameSWIR;//图像指针
	int heightSWIR;
	int widthSWIR;
	
private slots:
	void Scan();

signals:
	void sendingSWIR(QImage);
	void acquringSWIR(QImage);
	void scanOK();
	void sendingCollectTime(double);
	void sendingSaveTime(double);
	void sendingTotalTime(double);
};


///////////////////////////界面主线程声明////////////////////////////
class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = 0);
	~MainWindow();

private:
	Ui::MainWindowClass ui;

	int wavelength;//在界面确定之后传回LCTF	
	unsigned char* pImageFrameRGB;
	unsigned short* pImageFrameSWIR;
	int heightRGB;
	int heightSWIR;
	int widthRGB;
	int widthSWIR;
	int captureSWIRNum = 0;
	int captureRGBNum = 0;
	int scanNum = 0;

	string pathCom;
	string captureSWIRPath = "E://Capture//captureSWIR//";
	string captureRGBPath = "E://Capture//captureRGB//";
	string scanPath = "E://Capture//scanSWIR//";

	Configuration *config;//参数设置对象
	WorkerRGB *workerRGB;
	WorkerSWIR *workerSWIR;
	//WorkerLCTF *workerLCTF;
	QThread *threadRGB;
	QThread *threadSWIR;
	//QThread *threadLCTF;

	QPixmap picRGB;
	QPixmap picSWIR;

private slots:
	void InitializeAll();
	bool ConnectRGB();
	bool ConnectSWIR();
	bool ConnectLCTF();
	void DisplayImageRGB(QImage);
	void DisplayImageSWIR(QImage);
	void DisplayCollectTime(double);
	void DisplaySaveTime(double);
	void DisplayTotalTime(double);
	//void SetWavelength();
	void DisconnectRGB();
	void DisconnectSWIR();
	void PreviewRGB(bool isPreviewed);
	void PreviewSWIR(bool isPreviewed);
	void CaptureRGB();
	void CaptureSWIR();
	void ShowConfiguration();
	int WavelengthSelected();
	//void LctfChecked();
	void FwChecked();
	void StartAcquisition();
	void SaveAcqImageRGB(QImage);
	void SaveAcqImageSWIR(QImage);
	void StopAcquisition();
	void Quit();
	void DestroyAll();

signals:
	void sendingWavelength(int);
	void scanPrepared();
};

#endif

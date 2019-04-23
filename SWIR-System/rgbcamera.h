#pragma once
//#include "MvErrorDefine.h"
//#include "CameraParams.h"
#include "MvCameraControl.h"
#include "string.h"

#define MAX_BUF_SIZE    (1920*1200*3)

using namespace std;

class RGBCamera 
{
	
public:
	RGBCamera();
	~RGBCamera();
	
	//初始化相机
	bool Init();
	//返回一帧图像
	unsigned char* Capture();
	//连续采集
	//void Acquisition();
	//关闭相机
	bool Fini();
	//设置帧率
	bool SetFrameRate(float fps);
	//返回帧率
	bool GetFrameRate(float &fps);
	//设置曝光时间
	bool SetExporeTime(float time);
	//返回曝光时间
	bool GetExporeTime(float &time);
	//设置增益
	bool SetGain(float gain);
	//返回增益
	bool GetGain(float &gain);
	//获得图像尺寸信息
	void GetImageSize(int &heightOutput, int &widthOutput);
	//返回相机是否能够采集
	bool GetImageReady();

	
private:
	int				nRet_ = -1;
	void*			RgbHandle_;
	unsigned char*	RgbBuffer_ = new unsigned char[MAX_BUF_SIZE];
	int				height_ = 0;
	int				width_ = 0;
	bool            isConnected_= false;
};

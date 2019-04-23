//swir class using c api
#pragma once

#include "VimbaC.h"
#include "VmbCommonTypes.h"

#include <windows.h>
#include <io.h>
#include<iostream>
#include <direct.h>

class SWIRCamera
{
private:
	VmbUint32_t nCount_             = 0;                     //相机数量
	VmbCameraInfo_t* pCameras_      = NULL;                  //相机信息
	VmbHandle_t hCamera_;                                    //相机句柄
	VmbFeatureInfo_t* pFeatures_;                            //相机参数（所有）
	VmbFrame_t frame_;                                       //帧结构体
	
	VmbInt64_t width_               = 0;                     //图像宽度
	VmbInt64_t height_              = 0;                     //图像高度
	double exposureTime_            = 50000;                 //曝光时间
	char* gain_                     = "Gain0";               //传感器增益

	const VmbUint32_t nTimeout_     = 2000;                  //函数超时
	VmbInt64_t nPayloadSize_        = 0;                     //图像有效载荷（用于声明帧结构体大小）
	unsigned short* pImage_         = NULL;                  //图像指针



	////Scan时使用的回调函数
	//void VMB_CALL ScanCallback(const VmbHandle_t hCamera, VmbFrame_t *pFrame)
	//{
	//	VmbError_t err = VmbFeatureCommandRun(hCamera, "AcquisitionStop");
	//	VmbCaptureFrameQueue(hCamera, pFrame, ScanCallback);
	//}

public:
	SWIRCamera();
	~SWIRCamera();

	bool Init();
	unsigned short* Capture();
	bool GetImageSize(int &heightOutput, int &widthOutput);
	bool Fini();

	bool GetExporeTime(double &time);
	bool SetExporeTime(double time);

	//bool SetSensorGain();

};
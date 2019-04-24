//swirclass using c api
#include "swircamera.h"

SWIRCamera::SWIRCamera()
{

}

SWIRCamera::~SWIRCamera()
{

}

//Capture时使用的回调函数
void VMB_CALL CaptureCallback(const VmbHandle_t hCamera, VmbFrame_t *pFrame)
{
	VmbError_t err = VmbFeatureCommandRun(hCamera, "AcquisitionStop");
	VmbCaptureFrameQueue(hCamera, pFrame, CaptureCallback);
}

////////////////////////////////////////////////////////////////////////////
// 函数：init
// 描述：初始化DCAM-API，获取设备句柄，打开设备，并获取一些该相机的基础属性，并以
//      此设置相关的结构体参数，分配图像捕获内存
// 输入：Null
// 输出：是否成功完成操作
// 返回：
// 备注：
// Modified by 
////////////////////////////////////////////////////////////////////////////
bool SWIRCamera::Init()
{
	/****************************局部参量定义**************************/
	VmbError_t err = -2;                    //错误类型
	bool bGigE = false;                     //检测gige接口

	/*****************************api初始化***************************/
	err = VmbStartup();
	if(err != VmbErrorSuccess)
	{
		//api init failed
		return false;
	}

	//调用全局Vimba句柄找寻
	err = VmbFeatureBoolGet(gVimbaHandle, "GeVTLIsPresent", &bGigE);
	if (err == VmbErrorSuccess)
	{
		if (bGigE == true)
		{
			// We use all network interfaces using the global Vimba handle
			err = VmbFeatureCommandRun(gVimbaHandle, "GeVDiscoveryAllOnce");
		}
	}
	if(err != VmbErrorSuccess)
	{
		return false;
	}

	/****************************获取相机并打开相机*********************/
	//一直寻找相机直到找到为止，获取相机数量
	do
	{
		err = VmbCamerasList(pCameras_, nCount_, &nCount_, sizeof *pCameras_);
		if(err != VmbErrorSuccess)
		{
			return false;
		}
	} while (nCount_ < 0);

	//分配空间并获取所有相机
	pCameras_ = (VmbCameraInfo_t*)malloc(nCount_ * (sizeof *pCameras_));

	err = VmbCamerasList(pCameras_, nCount_, &nCount_, sizeof *pCameras_);
	if(err != VmbErrorSuccess)
	{
		return false;
	}

	//打开相机（列表第一台相机）
	err = VmbCameraOpen(pCameras_[0].cameraIdString, VmbAccessModeFull, &hCamera_);
	if(err != VmbErrorSuccess)
	{
		return false;
	}

	/*****************************获取相机参数**************************/
	//获取图像的高和宽
	err = VmbFeatureIntGet(hCamera_, "Width", &width_);
	if(err != VmbErrorSuccess)
	{
		return false;
	}

	err = VmbFeatureIntGet(hCamera_, "Height", &height_);
	if(err != VmbErrorSuccess)
	{
		return false;
	}

	//分配图像指针
	pImage_ = new unsigned short[width_ * height_];

	//获取图像的曝光时间
	err = VmbFeatureFloatSet(hCamera_, "ExposureTime", exposureTime_);

	err = VmbFeatureEnumSet(hCamera_, "SensorGain", gain_);

	/****************************分配抓图空间**************************/
	//获取图像有效载荷
	err = VmbFeatureIntGet(hCamera_, "PayloadSize", &nPayloadSize_);
	if(err != VmbErrorSuccess)
	{
		return false;
	}

	//frame结构体空间分配及设置参数
	frame_.buffer = pImage_;
	frame_.bufferSize = (VmbUint32_t)nPayloadSize_;

	//声明存储空间
	err = VmbFrameAnnounce(hCamera_, &frame_, (VmbUint32_t)sizeof(VmbFrame_t));
	if(err != VmbErrorSuccess)
	{
		return false;
	}

	/*****************************开启api抓图*****************************/
	//抓图模式
	err = VmbFeatureEnumSet(hCamera_, "AcquisitionMode", "Continuous");//SingleFrame:可降低cpu负载
	if(err != VmbErrorSuccess)
	{
		return false;
	}

	//开启api抓图引擎
	err = VmbCaptureStart(hCamera_);
	if(err != VmbErrorSuccess)
	{
		return false;
	}

	//Frame排队
	err = VmbCaptureFrameQueue(hCamera_, &frame_, CaptureCallback);
	if (err != VmbErrorSuccess)
	{
		return false;
	}

	return true;
}

////////////////////////////////////////////////////////////////////////////
// 函数：Capture
// 描述：图片捕捉，捕获当前的一帧图像，下一帧图像覆盖当前帧
// 输入：Null
// 输出：是否成功完成操作
// 返回：
// 备注：
// Modified by 
////////////////////////////////////////////////////////////////////////////
unsigned short* SWIRCamera::Capture()
{
	/****************************局部参量定义**************************/
	VmbError_t err = -2;                    //错误类型

	/*****************************不停抓图*****************************/

	//请求图片
	err = VmbFeatureCommandRun(hCamera_, "AcquisitionStart");
	if(err != VmbErrorSuccess)
	{
		return NULL;
	}
	err = VmbCaptureFrameWait(hCamera_, &frame_, nTimeout_);

	return pImage_;
	//return ((unsigned short*)frame_.buffer);
}

////////////////////////////////////////////////////////////////////////////
// 函数：GetImageSize
// 描述：返回图像高度和宽度（像素点数）
// 输入：Null
// 输出：是否成功完成操作
// 返回：
// 备注：
// Modified by 
////////////////////////////////////////////////////////////////////////////
bool SWIRCamera::GetImageSize(int& widthOutput, int& heightOutput)
{
	if(height_ == 0 || width_ == 0)
	{
		printf("there is no image!");
		return false;
	}

	//赋值
	widthOutput = width_;
	heightOutput = height_;

	//结束操作，返回true
	return true;
}

////////////////////////////////////////////////////////////////////////////
// 函数：Fini
// 描述：先停止抓图，然后释放buffer，若存在事件等待，则销毁等待句柄，再销毁设备句
//      柄，然后接口反初始化
// 输入：Null
// 输出：是否成功完成操作
// 返回：
// 备注：
// Modified by 
////////////////////////////////////////////////////////////////////////////
bool SWIRCamera::Fini()
{
	/****************************局部参量定义**************************/
	VmbError_t err = -2;                    //错误类型

	/*******************************操作******************************/
	//停止抓图
	VmbFeatureCommandRun(hCamera_, "AcquisitionStop");

	//关闭capture引擎
	VmbCaptureEnd(hCamera_);

	//清空抓图队列
    VmbCaptureQueueFlush(hCamera_);

    //关闭相机&销毁句柄
    VmbCameraClose(hCamera_);
    hCamera_ = NULL;

    //关闭api
    VmbShutdown();

    return true;
}

////////////////////////////////////////////////////////////////////////////
// 函数：GetExporeTime
// 描述：返回相机的曝光时间
// 输入：Null
// 输出：是否成功完成操作
// 返回：
// 备注：
// Modified by 
////////////////////////////////////////////////////////////////////////////
bool SWIRCamera::GetExporeTime(double& time)
{
	if(exposureTime_ == 0)
	{
		return false;
	}

	//赋值
	time = exposureTime_;

	//结束操作，返回true
	return true;
}

////////////////////////////////////////////////////////////////////////////
// 函数：SetExporeTime
// 描述：设置相机的曝光时间
// 输入：Null
// 输出：是否成功完成操作
// 返回：
// 备注：
// Modified by 
////////////////////////////////////////////////////////////////////////////
bool SWIRCamera::SetExporeTime(double time)
{
	/****************************局部参量定义**************************/
	VmbError_t err = -2;                    //错误类型

	/*********************************操作****************************/
	exposureTime_ = time;

	err = VmbFeatureFloatGet(hCamera_, "ExposureTime", &exposureTime_);
	if(err != VmbErrorSuccess)
	{
		return false;
	}

	return true;
}

////////////////////////////////////////////////////////////////////////////
// 函数：SetExporeTime
// 描述：设置相机的曝光时间
// 输入：Null
// 输出：是否成功完成操作
// 返回：
// 备注：
// Modified by 
////////////////////////////////////////////////////////////////////////////
//bool SWIRCamera::SetSensorGain();
//{
//	/****************************局部参量定义**************************/
//	VmbError_t err = -2;                    //错误类型
//
//	/*********************************操作****************************/
//	err = VmbFeatureEnumSet(hCamera_, "SensorGain", gain_);
//
//	if(err != VmbErrorSuccess)
//	{
//		return false;
//	}
//
//	return true;
//}
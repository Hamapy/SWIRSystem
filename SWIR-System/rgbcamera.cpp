#include "rgbcamera.h"

RGBCamera::RGBCamera()
{
	//nRet = -1;
	//RgbHandle = NULL;
	//RgbBuffer = new unsigned char[MAX_BUF_SIZE];
}

RGBCamera::~RGBCamera()
{
	this->Fini();
	delete []RgbBuffer_;
}

////////////////////////////////////////////////////////////////////////////
// 函数：initialize
// 描述：相机初始化、连接、开始采集
// 输入：Null
// 输出：是否成功完成操作
// 返回：
// 备注：
// Modified by 
////////////////////////////////////////////////////////////////////////////
bool RGBCamera::Init()
{

	//枚举子网内指定的传输协议对应的所有设备
	unsigned int nTLayerType = MV_GIGE_DEVICE | MV_USB_DEVICE;
	MV_CC_DEVICE_INFO_LIST m_stDevList = { 0 };
	nRet_ = MV_CC_EnumDevices(nTLayerType, &m_stDevList); //SDK接口
	if (MV_OK != nRet_)
	{
		return false;
	}
	int i = 0;
	if (m_stDevList.nDeviceNum == 0)
	{
		return false;
	}
  
	//选择查找到的第一台在线设备，创建设备句柄
	int nDeviceIndex = 1;
	MV_CC_DEVICE_INFO m_stDevInfo = { 0 };
	memcpy(&m_stDevInfo, m_stDevList.pDeviceInfo[nDeviceIndex], sizeof(MV_CC_DEVICE_INFO));
	nRet_ = MV_CC_CreateHandle(&RgbHandle_, &m_stDevInfo);   //SDK接口
	if (MV_OK != nRet_)
	{
		return false;
	}
                                      
	//连接设备
	nRet_ = MV_CC_OpenDevice(RgbHandle_);  //SDK接口
	if (MV_OK != nRet_)
	{
		return false;
	}
                                 
	//开始采集图像
	nRet_ = MV_CC_StartGrabbing(RgbHandle_);  //SDK接口
	if (MV_OK != nRet_)
	{
		return false;
	}
	isConnected_ = true;
	return true;
}
////////////////////////////////////////////////////////////////////////////
// 函数：capture
// 描述：采集一帧RGB图像
// 输入：Null
// 输出：一帧图像
// 返回：
// 备注：
// Modified by 
////////////////////////////////////////////////////////////////////////////
unsigned char* RGBCamera::Capture()
{
	//获取一帧数据的大小
	/*MVCC_INTVALUE stIntvalue = { 0 };
	nRet = MV_CC_GetIntValue(RgbHandle, "PayloadSize", &stIntvalue);
	if (nRet != MV_OK)
	{
		return NULL;
	}
	int nBufSize = stIntvalue.nCurValue; //SDK返回的这一帧数据大小有问题
	*/
	int nBufSize = MAX_BUF_SIZE;

	//unsigned char*  pFrameBuf;
	//pFrameBuf = (unsigned char*)malloc(nBufSize);

	MV_FRAME_OUT_INFO_EX stInfo;
	memset(&stInfo, 0, sizeof(MV_FRAME_OUT_INFO_EX));

	//采集BGR数据
	nRet_ = MV_CC_GetImageForBGR(RgbHandle_, RgbBuffer_, nBufSize, &stInfo, 1000); //SDK接口
	if (nRet_ == MV_OK)
	{
		width_ = stInfo.nWidth;
		height_ = stInfo.nHeight;
		return RgbBuffer_;
	}
	else
	{
		return NULL;
	}
}
////////////////////////////////////////////////////////////////////////////
// 函数：acquisition
// 描述：
// 输入：Null
// 输出：Null
// 返回：Null
// 备注：
// Modified by 
////////////////////////////////////////////////////////////////////////////
//void RGBCamera::Acquisition()
//{
//
//}

////////////////////////////////////////////////////////////////////////////
// 函数：stop
// 描述：相机停止采集、关闭设备、释放资源
// 输入：Null
// 输出：是否正确完成操作
// 返回：
// 备注：
// Modified by 
////////////////////////////////////////////////////////////////////////////
bool RGBCamera::Fini()
{
	//停止采集图像 
	nRet_ = MV_CC_StopGrabbing(RgbHandle_);  //SDK接口
	if (MV_OK != nRet_)
	{
		return false;
	}

	//关闭设备，释放资源
	nRet_ = MV_CC_CloseDevice(RgbHandle_);  //SDK接口
	if (MV_OK != nRet_)
	{
		return false;
	}

	//销毁句柄，释放资源
	nRet_ = MV_CC_DestroyHandle(RgbHandle_);  //SDK接口
	if (MV_OK != nRet_)
	{
		return false;
	}
	isConnected_ = false;
	return true;
}

//节点参数设置
//AcquisitionFrameRate	IFloat 	≥0.0，单位fps	R/W 	Trigger Mode是off的时候该值生效
//ExposureTime			IFloat 	≥0.0，单位us		R/W 	曝光时间
//Gain[GainSelector]	IFloat 	≥0.0，单位dB		R/W 	增益值


////////////////////////////////////////////////////////////////////////////
// 函数：setFrameRate
// 描述：设置帧率
// 输入：帧率：fps
// 输出：是否成功执行
// 返回：
// 备注：
// Modified by 
////////////////////////////////////////////////////////////////////////////
bool RGBCamera::SetFrameRate(float fps)
{

	nRet_ = MV_CC_SetFloatValue(RgbHandle_, "AcquisitionFrameRate", fps);  //SDK接口
	if (MV_OK != nRet_)
	{
		return false;
	}
	return true;
}
////////////////////////////////////////////////////////////////////////////
// 函数：getFrameRate
// 描述：获得帧率
// 输入：帧率：fps
// 输出：是否成功执行
// 返回：帧率：fps
// 备注：
// Modified by 
////////////////////////////////////////////////////////////////////////////
bool RGBCamera::GetFrameRate(float &fps)
{
	//获取float型参数
	MVCC_FLOATVALUE struFloatValue = { 0 };

	nRet_ = MV_CC_GetFloatValue(RgbHandle_, "AcquisitionFrameRate", &struFloatValue);  //SDK接口
	if (MV_OK != nRet_)
	{
		return false;
	}
	fps = struFloatValue.fCurValue;
	return true;

}
////////////////////////////////////////////////////////////////////////////
// 函数：setExporeTime
// 描述：设置曝光时间
// 输入：时间：time(us)
// 输出：是否成功执行
// 返回：Null
// 备注：
// Modified by 
////////////////////////////////////////////////////////////////////////////
bool RGBCamera::SetExporeTime(float time)
{

	nRet_ = MV_CC_SetFloatValue(RgbHandle_, "ExposureTime", time);  //SDK接口
	if (MV_OK != nRet_)
	{
		return false;
	}
	return true;
}
////////////////////////////////////////////////////////////////////////////
// 函数：getExporeTime
// 描述：获得曝光时间
// 输入：时间：time(us)
// 输出：是否成功执行
// 返回：时间：time(us)
// 备注：
// Modified by 
////////////////////////////////////////////////////////////////////////////
bool RGBCamera::GetExporeTime(float &time)
{
	MVCC_FLOATVALUE struFloatValue = { 0 };

	nRet_ = MV_CC_GetFloatValue(RgbHandle_, "ExposureTime", &struFloatValue);  //SDK接口
	if (MV_OK != nRet_)
	{
		return false;
	}
	time = struFloatValue.fCurValue;
	return true;
}
////////////////////////////////////////////////////////////////////////////
// 函数：setGain
// 描述：设置增益
// 输入：增益：gain(dB)
// 输出：是否成功执行
// 返回：Null
// 备注：
// Modified by 
////////////////////////////////////////////////////////////////////////////
bool RGBCamera::SetGain(float gain)
{

	nRet_ = MV_CC_SetFloatValue(RgbHandle_, "Gain", gain);  //SDK接口
	if (MV_OK != nRet_)
	{
		return false;
	}
	return true;
}
////////////////////////////////////////////////////////////////////////////
// 函数：getGain
// 描述：获得增益
// 输入：增益：gain(dB)
// 输出：是否成功执行
// 返回：增益：gain(dB)
// 备注：
// Modified by 
////////////////////////////////////////////////////////////////////////////
bool RGBCamera::GetGain(float &gain)
{
	MVCC_FLOATVALUE struFloatValue = { 0 };

	nRet_ = MV_CC_GetFloatValue(RgbHandle_, "Gain", &struFloatValue);  //SDK接口
	if (MV_OK != nRet_)
	{
		return false;
	}
	gain = struFloatValue.fCurValue;
	return true;
}

////////////////////////////////////////////////////////////////////////////
// 函数：GetImageSize
// 描述：返回图像高度和宽度
// 输入：
// 输出：
// 返回：图像的高度heightOutput,宽度widthOutput
// 备注：
// Modified by 
////////////////////////////////////////////////////////////////////////////
void RGBCamera::GetImageSize(int& heightOutput, int& widthOutput)
{

	widthOutput = width_;
	heightOutput = height_;
}

bool RGBCamera::GetImageReady()
{
	return isConnected_;
}
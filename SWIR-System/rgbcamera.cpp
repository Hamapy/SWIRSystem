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
// ������initialize
// �����������ʼ�������ӡ���ʼ�ɼ�
// ���룺Null
// ������Ƿ�ɹ���ɲ���
// ���أ�
// ��ע��
// Modified by 
////////////////////////////////////////////////////////////////////////////
bool RGBCamera::Init()
{

	//ö��������ָ���Ĵ���Э���Ӧ�������豸
	unsigned int nTLayerType = MV_GIGE_DEVICE | MV_USB_DEVICE;
	MV_CC_DEVICE_INFO_LIST m_stDevList = { 0 };
	nRet_ = MV_CC_EnumDevices(nTLayerType, &m_stDevList); //SDK�ӿ�
	if (MV_OK != nRet_)
	{
		return false;
	}
	int i = 0;
	if (m_stDevList.nDeviceNum == 0)
	{
		return false;
	}
  
	//ѡ����ҵ��ĵ�һ̨�����豸�������豸���
	int nDeviceIndex = 1;
	MV_CC_DEVICE_INFO m_stDevInfo = { 0 };
	memcpy(&m_stDevInfo, m_stDevList.pDeviceInfo[nDeviceIndex], sizeof(MV_CC_DEVICE_INFO));
	nRet_ = MV_CC_CreateHandle(&RgbHandle_, &m_stDevInfo);   //SDK�ӿ�
	if (MV_OK != nRet_)
	{
		return false;
	}
                                      
	//�����豸
	nRet_ = MV_CC_OpenDevice(RgbHandle_);  //SDK�ӿ�
	if (MV_OK != nRet_)
	{
		return false;
	}
                                 
	//��ʼ�ɼ�ͼ��
	nRet_ = MV_CC_StartGrabbing(RgbHandle_);  //SDK�ӿ�
	if (MV_OK != nRet_)
	{
		return false;
	}
	isConnected_ = true;
	return true;
}
////////////////////////////////////////////////////////////////////////////
// ������capture
// �������ɼ�һ֡RGBͼ��
// ���룺Null
// �����һ֡ͼ��
// ���أ�
// ��ע��
// Modified by 
////////////////////////////////////////////////////////////////////////////
unsigned char* RGBCamera::Capture()
{
	//��ȡһ֡���ݵĴ�С
	/*MVCC_INTVALUE stIntvalue = { 0 };
	nRet = MV_CC_GetIntValue(RgbHandle, "PayloadSize", &stIntvalue);
	if (nRet != MV_OK)
	{
		return NULL;
	}
	int nBufSize = stIntvalue.nCurValue; //SDK���ص���һ֡���ݴ�С������
	*/
	int nBufSize = MAX_BUF_SIZE;

	//unsigned char*  pFrameBuf;
	//pFrameBuf = (unsigned char*)malloc(nBufSize);

	MV_FRAME_OUT_INFO_EX stInfo;
	memset(&stInfo, 0, sizeof(MV_FRAME_OUT_INFO_EX));

	//�ɼ�BGR����
	nRet_ = MV_CC_GetImageForBGR(RgbHandle_, RgbBuffer_, nBufSize, &stInfo, 1000); //SDK�ӿ�
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
// ������acquisition
// ������
// ���룺Null
// �����Null
// ���أ�Null
// ��ע��
// Modified by 
////////////////////////////////////////////////////////////////////////////
//void RGBCamera::Acquisition()
//{
//
//}

////////////////////////////////////////////////////////////////////////////
// ������stop
// ���������ֹͣ�ɼ����ر��豸���ͷ���Դ
// ���룺Null
// ������Ƿ���ȷ��ɲ���
// ���أ�
// ��ע��
// Modified by 
////////////////////////////////////////////////////////////////////////////
bool RGBCamera::Fini()
{
	//ֹͣ�ɼ�ͼ�� 
	nRet_ = MV_CC_StopGrabbing(RgbHandle_);  //SDK�ӿ�
	if (MV_OK != nRet_)
	{
		return false;
	}

	//�ر��豸���ͷ���Դ
	nRet_ = MV_CC_CloseDevice(RgbHandle_);  //SDK�ӿ�
	if (MV_OK != nRet_)
	{
		return false;
	}

	//���پ�����ͷ���Դ
	nRet_ = MV_CC_DestroyHandle(RgbHandle_);  //SDK�ӿ�
	if (MV_OK != nRet_)
	{
		return false;
	}
	isConnected_ = false;
	return true;
}

//�ڵ��������
//AcquisitionFrameRate	IFloat 	��0.0����λfps	R/W 	Trigger Mode��off��ʱ���ֵ��Ч
//ExposureTime			IFloat 	��0.0����λus		R/W 	�ع�ʱ��
//Gain[GainSelector]	IFloat 	��0.0����λdB		R/W 	����ֵ


////////////////////////////////////////////////////////////////////////////
// ������setFrameRate
// ����������֡��
// ���룺֡�ʣ�fps
// ������Ƿ�ɹ�ִ��
// ���أ�
// ��ע��
// Modified by 
////////////////////////////////////////////////////////////////////////////
bool RGBCamera::SetFrameRate(float fps)
{

	nRet_ = MV_CC_SetFloatValue(RgbHandle_, "AcquisitionFrameRate", fps);  //SDK�ӿ�
	if (MV_OK != nRet_)
	{
		return false;
	}
	return true;
}
////////////////////////////////////////////////////////////////////////////
// ������getFrameRate
// ���������֡��
// ���룺֡�ʣ�fps
// ������Ƿ�ɹ�ִ��
// ���أ�֡�ʣ�fps
// ��ע��
// Modified by 
////////////////////////////////////////////////////////////////////////////
bool RGBCamera::GetFrameRate(float &fps)
{
	//��ȡfloat�Ͳ���
	MVCC_FLOATVALUE struFloatValue = { 0 };

	nRet_ = MV_CC_GetFloatValue(RgbHandle_, "AcquisitionFrameRate", &struFloatValue);  //SDK�ӿ�
	if (MV_OK != nRet_)
	{
		return false;
	}
	fps = struFloatValue.fCurValue;
	return true;

}
////////////////////////////////////////////////////////////////////////////
// ������setExporeTime
// �����������ع�ʱ��
// ���룺ʱ�䣺time(us)
// ������Ƿ�ɹ�ִ��
// ���أ�Null
// ��ע��
// Modified by 
////////////////////////////////////////////////////////////////////////////
bool RGBCamera::SetExporeTime(float time)
{

	nRet_ = MV_CC_SetFloatValue(RgbHandle_, "ExposureTime", time);  //SDK�ӿ�
	if (MV_OK != nRet_)
	{
		return false;
	}
	return true;
}
////////////////////////////////////////////////////////////////////////////
// ������getExporeTime
// ����������ع�ʱ��
// ���룺ʱ�䣺time(us)
// ������Ƿ�ɹ�ִ��
// ���أ�ʱ�䣺time(us)
// ��ע��
// Modified by 
////////////////////////////////////////////////////////////////////////////
bool RGBCamera::GetExporeTime(float &time)
{
	MVCC_FLOATVALUE struFloatValue = { 0 };

	nRet_ = MV_CC_GetFloatValue(RgbHandle_, "ExposureTime", &struFloatValue);  //SDK�ӿ�
	if (MV_OK != nRet_)
	{
		return false;
	}
	time = struFloatValue.fCurValue;
	return true;
}
////////////////////////////////////////////////////////////////////////////
// ������setGain
// ��������������
// ���룺���棺gain(dB)
// ������Ƿ�ɹ�ִ��
// ���أ�Null
// ��ע��
// Modified by 
////////////////////////////////////////////////////////////////////////////
bool RGBCamera::SetGain(float gain)
{

	nRet_ = MV_CC_SetFloatValue(RgbHandle_, "Gain", gain);  //SDK�ӿ�
	if (MV_OK != nRet_)
	{
		return false;
	}
	return true;
}
////////////////////////////////////////////////////////////////////////////
// ������getGain
// �������������
// ���룺���棺gain(dB)
// ������Ƿ�ɹ�ִ��
// ���أ����棺gain(dB)
// ��ע��
// Modified by 
////////////////////////////////////////////////////////////////////////////
bool RGBCamera::GetGain(float &gain)
{
	MVCC_FLOATVALUE struFloatValue = { 0 };

	nRet_ = MV_CC_GetFloatValue(RgbHandle_, "Gain", &struFloatValue);  //SDK�ӿ�
	if (MV_OK != nRet_)
	{
		return false;
	}
	gain = struFloatValue.fCurValue;
	return true;
}

////////////////////////////////////////////////////////////////////////////
// ������GetImageSize
// ����������ͼ��߶ȺͿ��
// ���룺
// �����
// ���أ�ͼ��ĸ߶�heightOutput,���widthOutput
// ��ע��
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
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
	
	//��ʼ�����
	bool Init();
	//����һ֡ͼ��
	unsigned char* Capture();
	//�����ɼ�
	//void Acquisition();
	//�ر����
	bool Fini();
	//����֡��
	bool SetFrameRate(float fps);
	//����֡��
	bool GetFrameRate(float &fps);
	//�����ع�ʱ��
	bool SetExporeTime(float time);
	//�����ع�ʱ��
	bool GetExporeTime(float &time);
	//��������
	bool SetGain(float gain);
	//��������
	bool GetGain(float &gain);
	//���ͼ��ߴ���Ϣ
	void GetImageSize(int &heightOutput, int &widthOutput);
	//��������Ƿ��ܹ��ɼ�
	bool GetImageReady();

	
private:
	int				nRet_ = -1;
	void*			RgbHandle_;
	unsigned char*	RgbBuffer_ = new unsigned char[MAX_BUF_SIZE];
	int				height_ = 0;
	int				width_ = 0;
	bool            isConnected_= false;
};

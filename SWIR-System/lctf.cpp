#include "lctf.h"
#include<iostream>
#include<string>


LCTF::LCTF()
{
}

LCTF::~LCTF()
{
}

////////////////////////////////////////////////////////////////////////////
// 函数：Init
// 描述：刷新模块，获取LCTF的序列号，然后初始化LCTF模块
// 输入：Null
// 输出：是否成功完成操作
// 返回：
// 备注：
// Modified by SY
////////////////////////////////////////////////////////////////////////////
bool LCTF::Init()
{
	//LCTF sn 中间结构体
	tLCTF    tlctf_;
	// LCTF_SDK_Cplusplus CLR class
	LCTF_SDK_Cplusplus ^lctf = gcnew LCTF_SDK_Cplusplus();
	//刷新模块，并获得模块数量
	lctf->Refresh_LCTF_Modules();
	int sz = lctf->get_Lctf_Sn_Size();
	//获取当前lctf序列号
    sn_ = lctf->get_Lctf_SN_at(0);
	//根据序列号打开所对应的设备
	lctfcon_ = lctf->Lct_init(tlctf_, sn_);
	return lctfcon_;	
}

////////////////////////////////////////////////////////////////////////////
// 函数：SetWavelength
// 描述：调整波长,输出
// 输入：想设置的波长
// 输出：是否成功完成操作
// 返回：
// 备注：
// Modified by SY
////////////////////////////////////////////////////////////////////////////
bool LCTF::SetWavelength(int wavelength)
{
	eErr err = eErr::eErrTimeOut;
	double iTemp = 0;              //传感器温度
	double Real_Wavelength = 0;    //输出的实际波长
	LCTF_SDK_Cplusplus ^lctf = gcnew LCTF_SDK_Cplusplus(); 
	//波长设置，返回成功与否
	err = lctf->Lct_Set_LCTF_Waveform(wavelength, (unsigned short)steadyTime_, 0, 0, Real_Wavelength, iTemp);

	if (err == (eErr)0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

////////////////////////////////////////////////////////////////////////////
// 函数：SetWavelength
// 描述：调整波长,输出
// 输入：想设置的波长
// 输出：实际设置的波长
// 返回：
// 备注：
// Modified by SY
////////////////////////////////////////////////////////////////////////////
double LCTF::SetWavelength(int wavelength,int wavelenth2)
{
	eErr err = eErr::eErrTimeOut;
	double iTemp = 0;              //传感器温度
	double Real_Wavelength = 0;    //输出的实际波长
	LCTF_SDK_Cplusplus ^lctf = gcnew LCTF_SDK_Cplusplus();
	err = lctf->Lct_Set_LCTF_Waveform(wavelength, (unsigned short)steadyTime_, 0, 0, Real_Wavelength, iTemp);

	if (err == (eErr)0)
	{
		return Real_Wavelength;
	}
	else
	{
		return false;
	}
}
////////////////////////////////////////////////////////////////////////////
// 函数：SetSteadyTime
// 描述：设置持续时间
// 输入：持续时间（s）
// 输出：是否修改成功
// 返回：
// 备注：
// Modified by SY
////////////////////////////////////////////////////////////////////////////
bool LCTF::SetSteadyTime(double time)
{
	if (time >= 0.2&&time < 60)
	{
		steadyTime_ = (int)time * 1000;
		return 1;
	}
	else
		return 0 ;
}
////////////////////////////////////////////////////////////////////////////
// 函数：Fini
// 描述：关闭设备
// 输入：Null
// 输出：是否成功完成操作
// 返回：
// 备注：
// Modified by SY
////////////////////////////////////////////////////////////////////////////
bool LCTF::Fini()
{
	LCTF_SDK_Cplusplus ^lctf = gcnew LCTF_SDK_Cplusplus();
	return (lctf->Lct_Uninit());
}
// lctf.h: interface for the LCTF class.
//
//////////////////////////////////////////////////////////////////////
#pragma once

#include "LCTF_SDK_Cplusplus.h"


/************************************************************
  FileName: lctf.h
  Author: Vernon        Version :          Date:2019/2/27
  Description:   
  Version:       
  Function List:   
    1. connect():
    打开设备

    2. set_waveform(int wavelength):
    将波长调至wavelength

    3. scan():
    波段扫描

    4. close():
    关闭设备

  History:         // 历史修改记录
      <author>  <time>   <version >   <desc>
***********************************************************/

class LCTF
{
private:
	string             sn_;               //lctf96位序列号
	tTemp              temperature_;       //lctf温度结构体
	int                steadyTime_ = 60000;   //持续时间
	bool               lctfcon_    = false;
public:
	LCTF();
	~LCTF();

	bool Init();
	bool SetWavelength(int wavelength);
	double SetWavelength(int wavelength, int wavelength2);
	bool SetSteadyTime(double time);
	bool Fini();
};
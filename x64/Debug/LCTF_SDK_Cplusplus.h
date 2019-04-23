#ifndef _LCTF_SDK_Cplusplus_H_
#define _LCTF_SDK_Cplusplus_H_
//
//filename: LCTF_SDK_Cplusplus.h
//
//
//

#using "LCTF/LcNET.dll"
using namespace LcNET;
using namespace std;

 
#include <tchar.h>
#include <vcclr.h>
 #include <iostream>
#include <Windows.h> 
#using <mscorlib.dll>
#include <comdef.h>



inline string SysStringToString( System::String^ str )
{  
	pin_ptr<const WCHAR> str_ptr = PtrToStringChars( str );
	_bstr_t mystring( str_ptr );
	char *lpstring = (char *)mystring;
	if( NULL == lpstring )
		return string();
	string my_string ( (char *)mystring );
	return my_string;
}



ref class LCTF_SDK_Cplusplus
{
public:
	LCTF_SDK_Cplusplus()
	{
		a = gcnew Lct_10V();  
	}
	~LCTF_SDK_Cplusplus()
	{
	}
public:
	int Refresh_LCTF_Modules()  //ok
	{
		return a->Refresh_LCTF_Modules();
	}
        /**
         * @brief   反初始化LCTF控制器
         * 该函数关闭被LCTF占用的端口
         * @param    无
         * @return  true 成功,false 失败
         */
     bool Lct_Uninit()
     {
         return a->Lct_Uninit();
     }
	
	eErr Lct_Set_LCTF_Waveform( unsigned short wavelen, unsigned short lctf_steadyTime, unsigned short extDelay1,
								unsigned short extDelay2 ,
								double & iReal_WaveLen, double & iTemp) //ok
	{
		int tmOv = 5000;
		return a->Lct_Set_LCTF_Waveform( wavelen, lctf_steadyTime, extDelay1,
                                           extDelay2 , iReal_WaveLen, iTemp, tmOv );
	}

	eErr Lct_Read_NM_TableInfo( Lct_10V::TNM_STRU^ &stru_Info ) //ok
	{
		int tmOv = 3000;
		return a->Lct_Read_NM_TableInfo( stru_Info , tmOv );		
	}
 
	/**
	 * @brief   获取LCTF控制器的序列号
	 * 该函数获取LCTF控制器的序列号,此序列号是一个96bit的值,生产时保证此值不会重复
     * @param   sn 引用类型的字符串值,已经将12字节转换后得到的字符,转换格式为printf("%02d%02d...",byte1,byte2.....)
     * @return  eErr类型
     */
	eErr Lct_get_sn( string & sn ) //ok
	{
		System::String ^str = gcnew System::String("");
		eErr err= a->Lct_get_sn( str );  
		sn = SysStringToString(str);
		return err;
	}

	/**
	 * @brief   获取LCTF传感器温度以及状态
     * 该函数获取LCTF各个传感器温度和状态
 	 * @param    st 欲获取的传感器
	 * @param    temper   温度值以及状态
	 * @param    tmOv  超时时间,单位ms,默认为3s
	 * @return  eErr类型
 	 */
	eErr Lct_get_temper( LcNET::eSensor stype, LcNET::tTemp &tt ) //ok
	{
		int tmOv = 3000;
		return a->Lct_get_temper( stype , tt );  
	}

	bool Lct_init( LcNET::tLCTF &lct , string strLctf_SN ) //ok
	{
		int tmOV = 50;
		System::String ^str = gcnew System::String( strLctf_SN.data() );
		return a->Lct_init( lct , str , tmOV );
	}
 
	int get_Lctf_Sn_Size() //ok
	{
		int i=0;
		System::Collections::Generic::List<System::String ^> ^pList = a->pListLctf_sn;
 		return a->get_Lctf_size();
	}
    
	string get_Lctf_SN_at( unsigned int i) //ok
	{
		System::UInt32^ index = gcnew System::UInt32( i );
		System::String^ str = gcnew System::String("");
		str = a->get_Lctf_SN_at( i ); 
		string my_string = SysStringToString( str );
 		return my_string;
	}
	bool Has_DB_file()
	{
		return a->Has_db_file;
	}
	bool Lct_Close_Port()
	{
		return a->Lct_Close_Port();
	}
	eErr Lct_Set_LCTF_Waveform(int iTemp, int iWaveLength, unsigned int lctf_delay_ms)
	{
		return a->Lct_Set_LCTF_Waveform( iTemp , iWaveLength , lctf_delay_ms );  
	}

private:
	Lct_10V ^a;  
};



#endif
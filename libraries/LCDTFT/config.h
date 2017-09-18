/*
welcome use this file! 
Please visit kedei.taobao.com
qq310953417
vision 1.1 2015/4/21

*/
#ifndef 	_CONFIG_H_
#define		_CONFIG_H_


#define  H_SCREEM		//Horizontal screen
//#define  V_SCREEM		//Vertical screen

//LCD GPIO
#define		RST	A4
#define		CS	A3
#define		RS	A2
#define		WR	A1
#define		RD	A0

#define		D0	2
#define		D1	3
#define		D2	4
#define		D3	5
#define		D4	6
#define		D5	7
#define		D6	8
#define		D7	9


//TS  GPIO
#define		XP	A1	
#define		XM	5	
#define		YP	A2	
#define		YM	6

#define _cmd(x)		cmd(~x)
#define ww_data(x)	w_data(~x)

#ifdef H_SCREEM
	#define		XXX	320
	#define		YYY	240
#endif

#ifdef V_SCREEM
	#define		XXX	240
	#define		YYY	320
#endif

#endif
/*
welcome use this file! 
Please visit kedei.taobao.com
qq310953417
vision 1.1 2015/4/21
*/
#include	"LCDTP.h"


/*****************************************
 *函数名 ： get_xy
 *作 用  ： 获取触摸的坐标
 *输 入  ： none
 *输出   ： none
 *作者   ： KeDei
 *时间   ：2015/4/21
 ****************************************/
void TP::get_xy(void)
{
	tp_x	= 0;
	tp_y	= 0;
	y_val	= 1;
	x_val	= 1;
	pinMode(XP,OUTPUT);
//	DDRC|=4;
	digitalWrite(XP,HIGH);
//	PORTC|=4;

	pinMode(XM,OUTPUT);
//	DDRB|=1;
	digitalWrite(XM,LOW);
//	PORTB&=0XFE;
	
	pinMode(YM,INPUT);
	pinMode(YP,INPUT);
//	DDRB&=0XFD;
//	DDRC&=0XFD;
	

 //   delay(1);
	tp_max=analogRead(YP);
	tp_min=tp_max;
	for(tp_i = 0;tp_i < 12;tp_i++)
	{
		temp_x=analogRead(YP);
		if(temp_x > tp_max) tp_max=temp_x;
		if(temp_x < tp_min) tp_min=temp_x;
		tp_x+=temp_x;
	}
	if((tp_max-tp_min)>=50) 
		x_val = 0;

	tp_x=(tp_x-tp_max-tp_min)/10;
#ifdef  H_SCREEM
	x=-(tp_x-120)*32/77+320;
#endif
#ifdef  V_SCREEM
	y=-(tp_x-120)*32/77+320;
#endif

	
	
	pinMode(YP,OUTPUT);
//	DDRC|=2;
	digitalWrite(YP,HIGH);
//	PORTC|=2;

	pinMode(YM,OUTPUT);
//	DDRB|=2;

	digitalWrite(YM,LOW);
//	PORTB&=0XFD;

	pinMode(XM,INPUT);
//	DDRB&=0XFE;

	pinMode(XP,INPUT);
//	DDRC&=0XFB;
//	delay(1);
	//tp_max=analogRead(XP);
	
	tp_max=analogRead(XP);
	tp_min=tp_max;
	for(tp_i = 0;tp_i < 12;tp_i++)
	{
		temp_y=analogRead(XP);
		if(temp_y > tp_max) tp_max=temp_y;
		if(temp_y < tp_min) tp_min=temp_y;
		tp_y+=temp_y;
	}
	if((tp_max-tp_min)>=50) 
		y_val = 0;
	

	tp_y=(tp_y-tp_max-tp_min)/10;
#ifdef  H_SCREEM
	y=(tp_y-125)*24/75;
#endif
#ifdef  V_SCREEM
	x=-(tp_y-125)*24/75+240;
#endif

	/*	Serial.print(x);
		Serial.print("  ");
		Serial.print(y);
		Serial.print("  ");
		Serial.print(x_val);
		Serial.print("  ");
		Serial.print(y_val);
		Serial.print("  ");
		Serial.print(flag);
		Serial.print("  ");
			Serial.print("\n");*/
}


/*****************************************
 *函数名 ： pen_down
 *作 用  ： 检测当前触摸的状态
 *输 入  ： none
 *输出   ： none
 *作者   ： KeDei
 *时间   ：2015/4/21
 ****************************************/
void TP::pen_down()
{
	pinMode(XP,INPUT_PULLUP);
	pinMode(XM,INPUT);
//	DDRB&=0XFE;
	pinMode(YP,INPUT);
//	DDRC&=0XFD;

	pinMode(YM,OUTPUT);
//	DDRB|=2;
	digitalWrite(YM,LOW);
	digitalWrite(YP,LOW);
//	PORTB&=0XFD;
//	delay(1);

	if(200 > analogRead(XP))
	{
		flag = 1;
		get_xy();
	}
	else flag = 0;
//	DDRB|=3;
//	DDRC|=6;
	pinMode(XP,OUTPUT);
	pinMode(XM,OUTPUT);
	pinMode(YP,OUTPUT);
}

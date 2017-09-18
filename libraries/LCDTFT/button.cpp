/*
welcome use this file! 
Please visit kedei.taobao.com
qq310953417
vision 1.1 2015/4/21
*/
#include	"button.h"
#include    "string.h"

/*****************************************
 *函数名 ： drawButton
 *作 用  ： 在左上角坐标为(_x,_y)画按钮，如果_botton_moder为true（1）则为圆角按钮，否则为方形按钮，
			按钮的文字内容为*str；
 *输 入  ： 坐标(_x,_y),按钮类型_botton_moder,按钮内容*str
 *输出   ： none
 *作者   ： KeDei
 *时间   ： 2015/4/21
 ****************************************/
void Button::drawButton(unsigned short _x,unsigned short _y,bool _botton_moder, char *str)
{
//	the  botton moder 0--cube_button  1--circle_button
	x				= _x;
	y				= _y;
	botton_moder	= _botton_moder;
	if(_botton_moder)
	{
		TFT.draw_buttom(x,y,x+x_size,y+y_size,10,button_color);
		TFT.draw_buttom_edge(x,y,x+x_size,y+y_size,10,edge_up_color);
		

	}
	else
	{
		TFT.draw_area(x,y,x+x_size,y+y_size,button_color);
		TFT.draw_edge(x,y,x+x_size,y+y_size,2,edge_up_color);
	}
	len = strlen(str);
	font.set_txt(x+x_size/2-9*len/2,y+y_size/2-8,x+x_size-2,y+y_size-2,NULL);

    font.set_fontcolor(font_color);
    font.lcd_string(str);
	
   //set_txt(112,117,170,140,0x00f0);
  // set_fontcolor(0xffff);
   //lcd_string("Button");*/
}

/*****************************************
 *函数名 ： istouch
 *作 用  ： 判断按钮是否被按下,如果按下 返回true，否则false
 *输 入  ： 坐标(_x,_y)
 *输出   ： none
 *作者   ： KeDei
 *时间   ： 2015/4/21
 ****************************************/
bool Button::istouch(unsigned short _x,unsigned short _y)
{
	if(x<_x&&_x<x+x_size)
		if(y<_y&&_y<y+y_size)
		{
			pendown();
			return true;
		}
	return false;
}

/*****************************************
 *函数名 ： pendown
 *作 用  ： 使能按钮按下
 *输 入  ： none
 *输出   ： none
 *作者   ： KeDei
 *时间   ： 2015/4/21
 ****************************************/
void Button::pendown(void)
{
	if(botton_moder)
	{
		TFT.draw_buttom_edge(x,y,x+x_size,y+y_size,10,edge_down_color);
	}
	else
	{
		
		TFT.draw_edge(x,y,x+x_size,y+y_size,2,edge_down_color);
	}
}

/*****************************************
 *函数名 ： pendown
 *作 用  ： 使能按钮弹起
 *输 入  ： none
 *输出   ： none
 *作者   ： KeDei
 *时间   ： 2015/4/21
 ****************************************/
void Button::penup(void)
{
	if(botton_moder)
	{
		TFT.draw_buttom_edge(x,y,x+x_size,y+y_size,10,edge_up_color);
	}
	else
	{
		
		TFT.draw_edge(x,y,x+x_size,y+y_size,2,edge_up_color);
	}
}

/*if you want  to change the button size or the color,you can use  the  follow function to achieve your purpose,
but you  must do it before use the Button() function*/
/*****************************************
 *函数名 ： resetsize
 *作 用  ： 设定个人按钮的大小，不使用默认大小
 *输 入  ： _x_size,_y_size
 *输出   ： none
 *作者   ： KeDei
 *时间   ： 2015/4/21
 ****************************************/
void Button::resetsize(unsigned char _x_size,unsigned char _y_size)
{
	x_size = _x_size;
	y_size = _y_size;
}

/*****************************************
 *函数名 ： resetsize
 *作 用  ： 设定个人按钮的颜色属性，不使用默认颜色
 *输 入  ： _edge_up_color, _edge_down_color,_button_color,_font_color
 *输出   ： none
 *作者   ： KeDei
 *时间   ： 2015/4/21
 ****************************************/
void Button::resetcolor(unsigned short _edge_up_color,unsigned short _edge_down_color,unsigned short _button_color,unsigned short _font_color)
{
	edge_up_color		= _edge_up_color;
	edge_down_color		= _edge_down_color;
	button_color		= _button_color;
	font_color			= _font_color;
}


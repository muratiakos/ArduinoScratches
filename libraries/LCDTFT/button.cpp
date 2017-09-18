/*
welcome use this file! 
Please visit kedei.taobao.com
qq310953417
vision 1.1 2015/4/21
*/
#include	"button.h"
#include    "string.h"

/*****************************************
 *������ �� drawButton
 *�� ��  �� �����Ͻ�����Ϊ(_x,_y)����ť�����_botton_moderΪtrue��1����ΪԲ�ǰ�ť������Ϊ���ΰ�ť��
			��ť����������Ϊ*str��
 *�� ��  �� ����(_x,_y),��ť����_botton_moder,��ť����*str
 *���   �� none
 *����   �� KeDei
 *ʱ��   �� 2015/4/21
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
 *������ �� istouch
 *�� ��  �� �жϰ�ť�Ƿ񱻰���,������� ����true������false
 *�� ��  �� ����(_x,_y)
 *���   �� none
 *����   �� KeDei
 *ʱ��   �� 2015/4/21
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
 *������ �� pendown
 *�� ��  �� ʹ�ܰ�ť����
 *�� ��  �� none
 *���   �� none
 *����   �� KeDei
 *ʱ��   �� 2015/4/21
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
 *������ �� pendown
 *�� ��  �� ʹ�ܰ�ť����
 *�� ��  �� none
 *���   �� none
 *����   �� KeDei
 *ʱ��   �� 2015/4/21
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
 *������ �� resetsize
 *�� ��  �� �趨���˰�ť�Ĵ�С����ʹ��Ĭ�ϴ�С
 *�� ��  �� _x_size,_y_size
 *���   �� none
 *����   �� KeDei
 *ʱ��   �� 2015/4/21
 ****************************************/
void Button::resetsize(unsigned char _x_size,unsigned char _y_size)
{
	x_size = _x_size;
	y_size = _y_size;
}

/*****************************************
 *������ �� resetsize
 *�� ��  �� �趨���˰�ť����ɫ���ԣ���ʹ��Ĭ����ɫ
 *�� ��  �� _edge_up_color, _edge_down_color,_button_color,_font_color
 *���   �� none
 *����   �� KeDei
 *ʱ��   �� 2015/4/21
 ****************************************/
void Button::resetcolor(unsigned short _edge_up_color,unsigned short _edge_down_color,unsigned short _button_color,unsigned short _font_color)
{
	edge_up_color		= _edge_up_color;
	edge_down_color		= _edge_down_color;
	button_color		= _button_color;
	font_color			= _font_color;
}


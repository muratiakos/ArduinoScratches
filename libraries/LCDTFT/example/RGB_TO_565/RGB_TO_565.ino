#include <LCDTFT.h>
#include <LCDTP.h>
#include "font.h"
#include "button.h"

#define backcolor 0XDDDD
//lcd的类对象为TFT
//LCD class object is TFT
TFTLCD TFT;
//字体的类对象为font
//Font class object is font
Font  font;
//触摸TP的类对象为tp
//Touchuscreem TP class object is tp
TP tp;

int value =1688;
void setup() {
  //TFT初始化
  //TFT initialization
   TFT.begin();
   
   //lcd清屏  颜色为backcolor
   //LCD Clear the screen, backcolor
   TFT.clear(backcolor);
   
   //设置文本区域 左上角为(50，10)，右下角(240，200)，区域的颜色为0XDDDD，如果颜色为NULL或者为R0 G0 B0，即为黑色 也不刷新文本颜色 
   //Set the text area for the upper left corner (50, 10), the lower right corner (240,200), the color 0XDDDD, if the color is NULL or R0 G0 B0(black), is also not set text color 
   font.set_txt(50,10,240,200,0XDDDD);
   
   //设置文本内字体的颜色
   //Set the text font color
   font.set_fontcolor(TFT.RGB_TO_565(0,0,255));
   //显示字符串
   //Displays a string
   font.lcd_string("kedei.taobao.com");
   font.lcd_string("qq 310953417");
   font.lcd_string("show RGB to 565");
   
   font.set_txt(10,80,50,120,TFT.RGB_TO_565(255,0,0));
   font.set_txt(60,80,100,120,TFT.RGB_TO_565(255,156,0));
   font.set_txt(110,80,150,120,TFT.RGB_TO_565(255,255,0));
   font.set_txt(160,80,200,120,TFT.RGB_TO_565(0,255,0));
   font.set_txt(210,80,250,120,TFT.RGB_TO_565(0,255,156));
   font.set_txt(260,80,300,120,TFT.RGB_TO_565(0,255,255));
   font.set_txt(10,130,50,170,TFT.RGB_TO_565(0,0,255));
   font.set_txt(60,130,100,170,TFT.RGB_TO_565(0,156,0));
   font.set_txt(110,130,150,170,TFT.RGB_TO_565(255,0,156));
   font.set_txt(160,130,200,170,TFT.RGB_TO_565(255,0,255));
   font.set_txt(210,130,250,170,TFT.RGB_TO_565(156,156,156));
   font.set_txt(260,130,300,170,TFT.RGB_TO_565(255,255,255));

  
}

void loop() {
  
  
      
}

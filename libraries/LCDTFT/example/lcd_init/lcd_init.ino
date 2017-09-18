#include <LCDTFT.h>
#include <LCDTP.h>
#include "font.h"
#include "button.h"

#define backcolor 0xf800

//lcd的类对象为TFT
//LCD class object is TFT
TFTLCD TFT;

//字体的类对象为font
//Object of FONT class type is font
Font  font;

void setup() {
  
  //TFT初始化
  //TFT initialization
   TFT.begin();
   
   //lcd清屏  颜色为backcolor
   //LCD Clear the screen, backcolor
   TFT.clear(backcolor);
   
   //设置文本区域 左上角为(10，10)，右下角(200，200)，区域的颜色为红色，如果颜色为NULL或者为R0 G0 B0，即为黑色 也不刷新文本颜色 
   //Set the text area for the upper left corner (10, 10), the lower right corner (200,200), the color red, if the color is NULL or R0 G0 B0(black), is also not set text color 
   font.set_txt(10,10,200,200,TFT.RGB_TO_565(255,0,0));
   
   //设置文本内字体的颜色
   //Set the text font color
   font.set_fontcolor(TFT.RGB_TO_565(0,0,255));
   //显示字符串
   //Displays a string
   font.lcd_string("kedei.taobao.com");
   //显示字符串
   //Displays a string
   font.lcd_string("qq 310953417");
   //显示字符串
   //Displays a string
   font.lcd_string("lcd init");
}

void loop() {
     
}

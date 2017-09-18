#include <LCDTFT.h>
#include <LCDTP.h>
#include "font.h"
#include "button.h"

#define backcolor 0xf800

//lcd的类对象为TFT
//LCD class object is TFT
TFTLCD TFT;
//字体的类对象为font
//Font class object is font
Font  font;
//触摸TP的类对象为tp
//Touchuscreem TP class object is tp
TP tp;
//声明两个按钮对象 Button1,Button2
//Two Button class object is  Button1,Button2
Button  Button1,Button2;
void setup() {
   //TFT初始化
  //TFT initialization
   TFT.begin();
   //lcd清屏  颜色为backcolor
   //LCD Clear the screen, backcolor
   TFT.clear(backcolor);
   
   //设置文本区域 左上角为(10，10)，右下角(240，200)，区域的颜色为红色，如果颜色为NULL或者为R0 G0 B0，即为黑色 也不刷新文本颜色 
   //Set the text area for the upper left corner (10, 10), the lower right corner (240,200), the color red, if the color is NULL or R0 G0 B0(black), is also not set text color 
   font.set_txt(10,10,240,200,TFT.RGB_TO_565(255,0,0));
   
   //设置文本内字体的颜色
   //Set the text font color
   font.set_fontcolor(TFT.RGB_TO_565(0,0,255));
   
   //显示字符串
   //Displays a string
   font.lcd_string("kedei.taobao.com");
   font.lcd_string("qq 310953417");
   font.lcd_string("Please draw by yourself");

}

void loop() {
      //检测触摸当前的状态
     //check Touch current state detection
      tp.pen_down();
      
       //触摸屏被触摸
      //The touch screen is touch
      if(tp.flag&&tp.y_val&&tp.x_val)
          //draw  pixel
         TFT.set_pixl(tp.x,tp.y,TFT.RGB_TO_565(255,255,255));
}

#include <LCDTFT.h>
#include <LCDTP.h>
#include "font.h"
#include "button.h"

#define backcolor 0xf800
TFTLCD TFT;
Font  font;

void setup() {
   TFT.begin();
   TFT.clear(backcolor);
   
   font.set_txt(10,10,200,200,TFT.RGB_TO_565(255,0,0));
   font.set_fontcolor(TFT.RGB_TO_565(0,0,255));
   font.lcd_string("kedei.taobao.com");
   font.lcd_string("qq 310953417");
   font.lcd_string("draw circle ");
   
   TFT.draw_circle(40,116,40,TFT.RGB_TO_565(255,255,255));
   TFT.draw_ring(185,110,40,35,TFT.RGB_TO_565(255,255,255));
   TFT.FillCircle(125,200,40,TFT.RGB_TO_565(255,255,255));
}

void loop() {
     
}

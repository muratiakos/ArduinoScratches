#include <LCDTFT.h>
#include <SD.h>

#define backcolor 0xf800
TFTLCD TFT;
File bmpFile;
int bmpWidth, bmpHeight;
uint8_t bmpDepth, bmpImageoffset;

#define backcolor 0xf800
#define SD_CS 10

void setup() {
  Serial.begin(9600);
   TFT.begin();
   TFT.clear(backcolor);
   
   pinMode(10, OUTPUT);

  if (!SD.begin(10)) {
    Serial.println("failed!");
    return;
  }
  Serial.println("SD OK!");

#ifdef  H_SCREEM
  bmpFile = SD.open("woof.bmp");
  if (! bmpFile) {
    Serial.println("didnt find image");
    while (1);
  }
  
  if (! bmpReadHeader(bmpFile)) { 
     Serial.println("bad bmp");
     return;
  }
    bmpFile.close();
    
    
  bmpFile = SD.open("pic1.bmp");
  Serial.print("image size "); 
  Serial.print(bmpWidth, DEC);
  Serial.print(", ");
  Serial.println(bmpHeight, DEC);
  TFT.set_area(0,0,319,240);
  bmpdraw(bmpFile, 0, 0);
  delay(1000);
  bmpFile.close();
  
  bmpFile = SD.open("pic2.bmp");
  TFT.set_area(0,0,319,240);
  bmpdraw(bmpFile, 0, 0);
  delay(1000);
  bmpFile.close();
#endif

#ifdef  V_SCREEM
  bmpFile = SD.open("wooff.bmp");
  if (! bmpFile) {
    Serial.println("didnt find image");
    while (1);
  }
  
  if (! bmpReadHeader(bmpFile)) { 
     Serial.println("bad bmp");
     return;
  }
    bmpFile.close();
    
    
  bmpFile = SD.open("pic11.bmp");
  Serial.print("image size "); 
  Serial.print(bmpWidth, DEC);
  Serial.print(", ");
  Serial.println(bmpHeight, DEC);
  TFT.set_area(0,0,239,320);
  bmpdraw(bmpFile, 0, 0);
  delay(1000);
  bmpFile.close();
  
  bmpFile = SD.open("pic22.bmp");
  TFT.set_area(0,0,239,320);
  bmpdraw(bmpFile, 0, 0);
  delay(1000);
  bmpFile.close();
#endif

}

void loop() {
     
}


#define BUFFPIXEL 20
void bmpdraw(File f, int x, int y) {
  bmpFile.seek(bmpImageoffset);
  uint32_t time = millis();
  uint16_t p;
  uint8_t g, b;
  int i, j;
  
  uint8_t sdbuffer[3 * BUFFPIXEL];  // 3 * pixels to buffer
  uint8_t buffidx = 3*BUFFPIXEL;
  
  for (i=0; i< bmpHeight; i++) {
    // bitmaps are stored with the BOTTOM line first so we have to move 'up'
/*
    if (tft.getRotation() == 3) {
      tft.goTo(x, y+bmpHeight-i); 
    } else if  (tft.getRotation() == 2) {
      tft.goTo(x+i, y);
    } else if  (tft.getRotation() == 1) {
        tft.goTo(x+bmpWidth-i, y+bmpHeight); 
    } else if  (tft.getRotation() == 0) {
      tft.goTo(x+bmpWidth, y+i); 
    }
    */
    
    for (j=0; j<bmpWidth; j++) {
      // read more pixels
      if (buffidx >= 3*BUFFPIXEL) {
        bmpFile.read(sdbuffer, 3*BUFFPIXEL);
        buffidx = 0;
      }
      
      // convert pixel from 888 to 565
      b = sdbuffer[buffidx++];     // blue
      g = sdbuffer[buffidx++];     // green
      p = sdbuffer[buffidx++];     // red
      
      p >>= 3;
      p <<= 6;
      
      g >>= 2;
      p |= g;
      p <<= 5;
      
      b >>= 3;
      p |= b;
     
       // write out the 16 bits of color
      TFT.w_data(p>>8);
      TFT.w_data(p);
    }
  }
  Serial.print(millis() - time, DEC);
  Serial.println(" ms");
}

boolean bmpReadHeader(File f) {
   // read header
  uint32_t tmp;
  
  if (read16(f) != 0x4D42) {
    // magic bytes missing
    return false;
  }
 
  // read file size
  tmp = read32(f);  
  Serial.print("size 0x"); Serial.println(tmp, HEX);
  
  // read and ignore creator bytes
  read32(f);
  
  bmpImageoffset = read32(f);  
  Serial.print("offset "); Serial.println(bmpImageoffset, DEC);
  
  // read DIB header
  tmp = read32(f);
  Serial.print("header size "); Serial.println(tmp, DEC);
  bmpWidth = read32(f);
  bmpHeight = read32(f);

  
  if (read16(f) != 1)
    return false;
    
  bmpDepth = read16(f);
  Serial.print("bitdepth "); Serial.println(bmpDepth, DEC);

  if (read32(f) != 0) {
    // compression not supported!
    return false;
  }

  Serial.print("compression "); Serial.println(tmp, DEC);

  return true;
}



// These read data from the SD card file and convert them to big endian 
// (the data is stored in little endian format!)

// LITTLE ENDIAN!
uint16_t read16(File f) {
  uint16_t d;
  uint8_t b;
  b = f.read();
  d = f.read();
  d <<= 8;
  d |= b;
  return d;
}


// LITTLE ENDIAN!
uint32_t read32(File f) {
  uint32_t d;
  uint16_t b;
 
  b = read16(f);
  d = read16(f);
  d <<= 16;
  d |= b;
  return d;
}

  


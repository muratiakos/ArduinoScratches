/*
welcome use this file! 
Please visit kedei.taobao.com
qq310953417
vision 1.1 2015/4/21
*/
#include	"LCDTFT.h"


void TFTLCD::begin(void)
{
	tft_init();
}

/*****************************************
 *������ �� cmd
 *�� ��  �� ��lcd���������Ϳ���ָ��
 *�� ��  �� LCDָ��
 *���   �� none
 *����   ��KeDei
 *ʱ��   ��2015/4/21
 ****************************************/
void  TFTLCD::cmd(unsigned char cmd)
{
	PORTC=PORTC&0Xf0|0x01;

	PORTB=(0xfc&PORTB)|(0x03&cmd);
	PORTD=(0x03&PORTD)|(0xfc&cmd);
	PORTC|=0x02;
	PORTC|=0x08;
}

/*****************************************
 *������ �� w_data
 *�� ��  �� ��lcd��������������
 *�� ��  �� data
 *���   �� none
 *����   �� KeDei
 *ʱ��   �� 2015/4/21
 ****************************************/
void  TFTLCD::w_data(unsigned char data)
{
	PORTC=PORTC&0Xf0|0x05;
	PORTB=(0xfc&PORTB)|(0x03&data);
	PORTD=(0x03&PORTD)|(0xfc&data);
	PORTC|=0x02;
	PORTC|=0x08;
}

/*****************************************
 *������ �� lcd_clear
 *�� ��  �� lcdȫ��ˢ��Ϊcolor��ɫ
 *�� ��  �� color
 *���   �� none
 *����   �� KeDei
 *ʱ��   �� 2015/4/21
 ****************************************/
void TFTLCD::clear(unsigned short color)
{
	int i=320,j=240;
	
	cmd(0x2a);    //Set Gamma 
#ifdef  V_SCREEM
	w_data(0x00); 
	w_data(0x00); 
	w_data(0x00); 
	w_data(0xef);

	cmd(0x2b);    
	w_data(0x00); 
	w_data(0x00); 
	w_data(0x01); 
	w_data(0x3f);
#endif

#ifdef  H_SCREEM
	w_data(0x00); 
	w_data(0x00); 
	w_data(0x01); 
	w_data(0x3f);

	cmd(0x2b);   
	w_data(0x00); 
	w_data(0x00); 
	w_data(0x00); 
	w_data(0xef);
	
#endif



	cmd(0x2c); 

	for(i = YYY;i > 0;i--)
		for(j = XXX;j > 0;j--)
	{
			w_data(color>>8);
			w_data(color);
	}
}

void TFTLCD::gpio_init()
{
	pinMode(RST, OUTPUT);
	pinMode(CS, OUTPUT);
	pinMode(RS, OUTPUT);
	pinMode(WR, OUTPUT);
	pinMode(RD, OUTPUT);
	pinMode(D0, OUTPUT);
	pinMode(D1, OUTPUT);
	pinMode(D2, OUTPUT);
	pinMode(D3, OUTPUT);
	pinMode(D4, OUTPUT);
	pinMode(D5, OUTPUT);
	pinMode(D6, OUTPUT);
	pinMode(D7, OUTPUT);

}

/*****************************************
 *������ �� tft_init
 *�� ��  �� lcd���Ƴ�ʼ��
 *�� ��  �� none
 *���   �� none
 *����   �� KeDei
 *ʱ��   �� 2015/4/21
 ****************************************/
void TFTLCD::tft_init()
{
	gpio_init();

	digitalWrite(RST,HIGH);
	delay(50);
	digitalWrite(RST,LOW);
	delay(100);
	
	digitalWrite(RST,HIGH);
	delay(50);
	digitalWrite(CS,HIGH);
	digitalWrite(RD,HIGH);
	digitalWrite(WR,HIGH);
	delay(10);



	cmd(0x00CF);  
	w_data(0x0000); 
	w_data(0x00C1); 
	w_data(0x0030); 

	cmd(0x00ED);  
	w_data(0x0064); 
	w_data(0x0003); 
	w_data(0x0012); 
	w_data(0x0081); 

	cmd(0x00E8);  
	w_data(0x0085); 
	w_data(0x0000); 
	w_data(0x0078); 

	cmd(0x00CB);  
	w_data(0x0039); 
	w_data(0x002C); 
	w_data(0x0000); 
	w_data(0x0034); 
	w_data(0x0002); 

	cmd(0x00F7);  
	w_data(0x0020); 

	cmd(0x00EA);  
	w_data(0x0000); 
	w_data(0x0000); 

	cmd(0x00C0);    //Power control 
	w_data(0x0018);   //VRH[5:0] 

	cmd(0x00C1);    //Power control 
	w_data(0x0012);   //SAP[2:0];BT[3:0] 

	cmd(0x00C5);    //VCM control 
	w_data(0x0031); 
	w_data(0x003C); 

	cmd(0x00C7);    //VCM control2 
	w_data(0x0099); 

	cmd(0x0036);    // Memory Access Control 
#ifdef V_SCREEM	
	w_data(0x004a); 
#endif

#ifdef H_SCREEM	
	w_data(0x2a); 
#endif


	cmd(0x003A);   
	w_data(0x0055); 

	cmd(0x00B1);   
	w_data(0x0000);   
	w_data(0x0016); 

	cmd(0x00B6);    // Display Function Control 
	w_data(0x000A); 
	w_data(0x00A2); 

	cmd(0x00F6);    
	w_data(0x0001); 
	w_data(0x0030); 

	cmd(0x00F2);    // 3Gamma Function Disable 
	w_data(0x0000); 

	cmd(0x0026);    //Gamma curve selected 
	w_data(0x0002); 

	cmd(0x00E0);    //Set Gamma 
	w_data(0x000F); 
	w_data(0x001D); 
	w_data(0x001A); 
	w_data(0x000A); 
	w_data(0x000D); 
	w_data(0x0007); 
	w_data(0x0049); 
	w_data(0x0066); 
	w_data(0x003B); 
	w_data(0x0007); 
	w_data(0x0011); 
	w_data(0x0001); 
	w_data(0x0009); 
	w_data(0x0005); 
	w_data(0x0004); 

	cmd(0x00E1);    //Set Gamma 
	w_data(0x0000); 
	w_data(0x0018); 
	w_data(0x001D); 
	w_data(0x0002); 
	w_data(0x000F); 
	w_data(0x0004); 
	w_data(0x0036); 
	w_data(0x0013); 
	w_data(0x004C); 
	w_data(0x0007); 
	w_data(0x0013); 
	w_data(0x000F); 
	w_data(0x002E); 
	w_data(0x002F); 
	w_data(0x0005);
  

	cmd(0x0011);    //Exit Sleep 
	delay(120); 
	cmd(0x0029);    //Display on 
	
	cmd(0x002a);    //Set Gamma 
	w_data(0x0000); 
	w_data(0x0000); 
	w_data(0x0000); 
	w_data(0x00ef);

	cmd(0x002b);    //Set Gamma 
	w_data(0x0000); 
	w_data(0x0000); 
	w_data(0x0001); 
	w_data(0x003f);
	cmd(0x002c); 

//lcd_clear(0xf800);

}

/*****************************************
 *������ �� set_area
 *�� ��  �� ѡ��lcd��ˢ�µ���Ч������������Ͻ�Ϊ��x0,y0��,
			���½�Ϊ��x1,y1��
 *�� ��  �� ��x0,y0��  ��x1,y1��
 *�� ��  �� none
 *�� ��  �� KeDei
 *ʱ ��  �� 2015/4/21
 ****************************************/
void TFTLCD::set_area(unsigned short x0,unsigned short y0,unsigned short x1,unsigned short y1)
{
	cmd(0x2a);    //Set Gamma 
	w_data(x0>>8); 
	w_data(x0); 
	w_data(x1>>8); 
	w_data(x1); 

	cmd(0x2b);    //Set Gamma 
	w_data(y0>>8); 
	w_data(y0); 
	w_data(y1>>8); 
	w_data(y1); 
	cmd(0x2c);  
}

/*****************************************
 *������ �� v_line
 *�� ��  �� ��lcd���꣨x,y����ˮƽ��len���ȵ��߶Σ��߶���ɫΪcolor
			����߶γ�����ˮƽ�ĳ��ȣ����Զ����ü�
 *�� ��  �� ���꣨x,y�� ����len  ��ɫcolor
 *�� ��  �� none
 *�� ��  �� KeDei
 *ʱ ��  �� 2015/4/21
 ****************************************/
void TFTLCD::v_line(unsigned short x,unsigned short y,unsigned short len,unsigned short color)
{

	if((y+len)>YYY) len=YYY-y;
	set_area(x,y,x,y+len);

	for(len;len > 0;len--)
	{
			w_data(color>>8);
			w_data(color);
	}
}

/*****************************************
 *������ �� h_line
 *�� ��  �� ��lcd���꣨x,y���ϴ�ֱ��len���ȵ��߶Σ��߶���ɫΪcolor
			����߶γ�������ֱ�ĳ��ȣ����Զ����ü�
 *�� ��  �� ���꣨x,y�� ����len  ��ɫcolor
 *�� ��  �� none
 *�� ��  �� KeDei
 *ʱ ��  �� 2015/4/21
 ****************************************/
void TFTLCD::h_line(unsigned short x,unsigned short y,unsigned short len,unsigned short color)
{

	if((x+len)>XXX) len=XXX-y;
	set_area(x,y,x+len,y);

	for(len;len > 0;len--)
	{
			w_data(color>>8);
			w_data(color);
	}
}

/*****************************************
 *������ �� draw_area
 *�� ��  �� ѡ��lcd��Ч������������Ͻ�Ϊ��x0,y0��,���½�Ϊ��x1,y1����
			ˢ��һ��color����ɫ�����������󽫲�ˢ����ɫ
 *�� ��  �� ���꣨x,y�� ��x1,y1�� ��ɫcolor
 *�� ��  �� none
 *�� ��  �� KeDei
 *ʱ ��  �� 2015/4/21
 ****************************************/
void TFTLCD::draw_area(unsigned short x0,unsigned short y0,unsigned short x1,unsigned short y1,unsigned short color)
{
		unsigned short i,j;
		if(x0 > x1)	return;
		if(y0 > y1) return;
		set_area(x0,y0,x1,y1);
	
		for(i=x1-x0+1;i > 0;i--)
			for(j=y1-y0+1;j > 0;j--)
			{
				w_data(color>>8);
				w_data(color);
			}
}

/*****************************************
 *������ �� draw_edge
 *�� ��  �� ѡ��lcd��Ч������������Ͻ�Ϊ��x0,y0��,���½�Ϊ��x1,y1����
			������ı�Եˢ�±߿��СΪsize��color��ɫ
 *�� ��  �� ���꣨x,y�� ��x1,y1�� ��Ե��Сsize  ��ɫcolor
 *�� ��  �� none
 *�� ��  �� KeDei
 *ʱ ��  �� 2015/4/21
 ****************************************/
void TFTLCD::draw_edge(unsigned short x0,unsigned short y0,unsigned short x1,unsigned short y1,unsigned short size,unsigned short color)
{
	draw_area(x0,y0,x1,y0+size,color);
	draw_area(x0,y1-size,x1,y1,color);
	draw_area(x0,y0,x0+size,y1,color);
	draw_area(x1-size,y0,x1,y1,color);
}

/*****************************************
 *������ �� set_pixl
 *�� ��  �� ��lcd�����꣨x,y���ϻ�һ�㡣�����ɫΪcolor
 *�� ��  �� ���꣨x,y�� ��ɫcolor
 *�� ��  �� none
 *�� ��  �� KeDei
 *ʱ ��  �� 2015/4/21
 ****************************************/
void   TFTLCD::set_pixl(unsigned short x,unsigned short y,unsigned short color)
{
	set_area(x,y,x,y);
	w_data(color>>8);
	w_data(color);
}

/*****************************************
 *������ �� draw_buttom
 *�� ��  �� ��lcd���������꣨x0,y0�����������꣨x1,y1����Բ�ǰ뾶Ϊcircular_size��
			��һ��Բ�ǰ�ť����ɫΪcolor��
 *�� ��  �� �������꣨x0,y0�����������꣨x1,y1����Բ�ǰ뾶circular_size����ɫcolor
 *�� ��  �� none
 *�� ��  �� KeDei
 *ʱ ��  �� 2015/4/21
 ****************************************/
void TFTLCD::draw_buttom(unsigned short x0,unsigned short y0,unsigned short x1,unsigned short y1,unsigned short circular_size,unsigned short color)
{
	if(circular_size)
	{	
		int dx = 0,dy = circular_size;
		int d = 1 - circular_size;                  
		for(;dy >= dx;)                    
		{
			 draw_area(-dy+x0+circular_size,-dx+y0+circular_size,dy+x1-circular_size,-dx+y0+circular_size,color);
			 draw_area(-dy+x0+circular_size,dx+y1-circular_size,dy+x1-circular_size,dx+y1-circular_size,color);
		
			 
		if(d < 0)
			d = d + 2 * dx + 3;                       
		else
		{
			d = d + 2 * (dx - dy) + 5;                  
			dy--;
			draw_area(-dx+x0+circular_size,-dy+y0+circular_size,dx+x1-circular_size,-dy+y0+circular_size,color);
			draw_area(-dx+x0+circular_size,dy+y1-circular_size,dx+x1-circular_size,dy+y1-circular_size,color);

		}
		dx++;                                         
		}
		draw_area(x0,y0+circular_size,x1,y1-circular_size,color);
	}

}

/*****************************************
 *������ �� draw_buttom_edge
 *�� ��  �� ��lcd���������꣨x0,y0�����������꣨x1,y1����Բ�ǰ뾶Ϊcircular_size��
			��һ��Բ�ǰ�ť���أ���ɫΪcolor��
 *�� ��  ��  �������꣨x0,y0�����������꣨x1,y1����Բ�ǰ뾶circular_size����ɫcolor
 *�� ��  �� none
 *�� ��  �� KeDei
 *ʱ ��  �� 2015/4/21
 ****************************************/
void TFTLCD::draw_buttom_edge(unsigned short x0,unsigned short y0,unsigned short x1,unsigned short y1,unsigned short circular_size,unsigned short color)
{
	if(circular_size)
	{	
		int dx = 0,dy = circular_size;
		int d = 1 - circular_size;                  
		for(;dy >= dx;)                    
		{
			set_pixl(-dy+x0+circular_size,-dx+y0+circular_size,color);
			set_pixl(dy+x1-circular_size,-dx+y0+circular_size,color);
			set_pixl(-dy+x0+circular_size,dx+y1-circular_size,color);
			set_pixl(dy+x1-circular_size,dx+y1-circular_size,color);
			set_pixl(-dx+x0+circular_size,-dy+y0+circular_size,color);
			set_pixl(dx+x1-circular_size,-dy+y0+circular_size,color);
			set_pixl(-dx+x0+circular_size,dy+y1-circular_size,color);
			set_pixl(dx+x1-circular_size,dy+y1-circular_size,color);
			 
		if(d < 0)
			d = d + 2 * dx + 3;                       
		else
		{
			d = d + 2 * (dx - dy) + 5;                  
			dy--;
		

		}
		dx++;                                         
		}
		draw_area(x0+circular_size,y0,x1-circular_size,y0,color);
		draw_area(x0+circular_size,y1,x1-circular_size,y1,color);
		draw_area(x0,y0+circular_size,x0,y1-circular_size,color);
		draw_area(x1,y0+circular_size,x1,y1-circular_size,color);
	}

}

/*****************************************
 *������ �� RGB_TO_565
 *�� ��  �� ��24λ��RGB��ɫת��Ϊ16λ��LCD���ɫ
 *�� ��  �� ����ɫR G B
 *�� ��  �� 16λ�����ɫ
 *�� ��  �� KeDei
 *ʱ ��  �� 2015/4/21
 ****************************************/
unsigned short   TFTLCD::RGB_TO_565(unsigned char r,unsigned char g,unsigned char b)
{
 unsigned short _RGB = ((unsigned short)r>>3)<<11;
 
 _RGB |= ((unsigned short)g>>2)<<5;
 
 _RGB |= ((unsigned short)b>>3);
 return _RGB;

}

/*****************************************
 *������ �� draw_circle
 *�� ��  �� ��lcd�����꣨x,y���ϻ��뾶ΪR��һ������Բ��Բ���ĵ���ɫΪcolor
 *�� ��  �� ���꣨x,y�� �뾶R ��ɫcolor
 *�� ��  �� none
 *�� ��  �� KeDei
 *ʱ ��  �� 2015/4/21
 ****************************************/
void TFTLCD::draw_circle(unsigned short x,unsigned short y,unsigned short R,unsigned short color)
{
	int x0 = 0,y0 = R;
	int d = 1 - R;                  
	for(;y0 >= x0;)                    
	{
	set_pixl(x0+x,y0+y,color);        
	set_pixl(y0+x,x0+y,color);        
	set_pixl(-x0+x,y0+y,color);      
	set_pixl(-y0+x,x0+y,color);       
	set_pixl(-x0+x,-y0+y,color);      
	set_pixl(-y0+x,-x0+y,color);       
	set_pixl(x0+x,-y0+y,color); 
	set_pixl(y0+x,-x0+y,color);  
	if(d < 0)
		d = d + 2 * x0 + 3;                       
	else
	{
		d = d + 2 * (x0 - y0) + 5;                  
		y0--;
		
	}
	x0++;                                         
	}
}


/*****************************************
 *������ �� draw_ring
 *�� ��  �� ��lcd�����꣨x,y���ϻ��ڰ뾶ΪIR����뾶ΪOR��һ��Բ����Բ������ɫΪcolor
 *�� ��  �� ���꣨x,y�� �ڰ뾶IR ��뾶OR ��ɫcolor
 *�� ��  �� none
 *�� ��  �� KeDei
 *ʱ ��  �� 2015/4/21
 ****************************************/
void TFTLCD::draw_ring(unsigned short x,unsigned short y,unsigned short OR,unsigned short IR,unsigned short color)
{
	int i;
	for(i = IR;i <= OR;i++)
		draw_circle(x,y,i,color);
}

/*****************************************
 *������ �� FillCircle
 *�� ��  �� ��lcd�����꣨x,y���ϻ��뾶R��һ��ʵ��Բ��ʵ��Բ����ɫΪcolor
 *�� ��  �� ���꣨x,y�� �뾶R ��ɫcolor
 *�� ��  �� none
 *�� ��  �� KeDei
 *ʱ ��  �� 2015/4/21
 ****************************************/
void TFTLCD::FillCircle(unsigned short x,unsigned short y,unsigned short R,unsigned short color)
{	int x0 = 0,y0 = R;
	int d = 1 - R;                  
	for(;y0 >= x0;)                    
	{
		 draw_area(-y0+x,x0+y,y0+x,x0+y,color);
		 draw_area(-y0+x,-x0+y,y0+x,-x0+y,color);
		 
	if(d < 0)
		d = d + 2 * x0 + 3;                       
	else
	{
		d = d + 2 * (x0 - y0) + 5;                  
		y0--;
		draw_area(-x0+x,-y0+y,x0+x,-y0+y,color);
		draw_area(-x0+x,y0+y,x0+x,y0+y,color);

	}
	x0++;                                         
	}

}


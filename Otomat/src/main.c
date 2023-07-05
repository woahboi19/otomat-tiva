#include "inc/hw_ints.h"
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "stdbool.h"
#include "Button.h"
#include "inc/lm4f120h5qr.h"
#include "Lcd.h"
#include <sys/time.h>
#include <stdlib.h>
#include "string.h"
#include "time.h"

int Urunler[6][3]={{20,20,10},{1,30,50},{2,20,100},{3,15,150},{4,50,175},{5,100,200}};



int main(void) {
	int count_ceyreklik;
	int count_yarimlik;
	int count_tam;
	int toplam;
	Button1_init();
	Button2_init();
	Button3_init();
	Button4_init();
	Button5_init();
	Button6_init();
	Button7_init();
	Button8_init();
	Button9_init();
	int button_onay;
	Lcd_init();
    SysCtlClockSet(SYSCTL_SYSDIV_4 | SYSCTL_USE_PLL | SYSCTL_XTAL_16MHZ | SYSCTL_OSC_MAIN);
	volatile unsigned long delay;
	volatile unsigned long delay1;
	SYSCTL_RCGC2_R |= SYSCTL_RCGC2_GPIOF;
	delay = SYSCTL_RCGC2_R;
	GPIO_PORTF_LOCK_R = 0x4C4F434B;
	GPIO_PORTF_CR_R = 0x01;
	GPIO_PORTF_DIR_R = 0x0E;
	GPIO_PORTF_PUR_R = 0x11;
	GPIO_PORTF_DEN_R = 0x1F;

	/*int fl = 1;
	do{
			for (delay1 = 0 ; delay1 < 100000 ; delay1++);
	        Lcd_Goto(1,1);
	        for (delay1 = 0 ; delay1 < 1000000 ; delay1++);
	        Lcd_Puts("Para atiniz.");
	        for (delay1 = 0 ; delay1 < 1000000 ; delay1++);
	}while(fl == 0);*/

	button_onay = GPIO_PORTF_DATA_R &0b00001;
	int c = 0, y = 0, t = 0;
	int atilan = 0;
	char at[5];
	while(button_onay != 0){
		if(Button1Pressed()) {
			GPIO_PORTF_DATA_R |= 0b00000100;
			for (delay1 = 0 ; delay1 < 1000000 ; delay1++);
			GPIO_PORTF_DATA_R &= ~(0b00000100);
			for (delay1 = 0 ; delay1 < 1000000 ; delay1++);
			c++;
		}

		else if(Button2Pressed()){
			GPIO_PORTF_DATA_R |= 0b00000100;
			for (delay1 = 0 ; delay1 < 1000000 ; delay1++);
			GPIO_PORTF_DATA_R &= ~(0b00000100);
			for (delay1 = 0 ; delay1 < 1000000 ; delay1++);
			y++;
		}

		else if(Button3Pressed()){
			GPIO_PORTF_DATA_R |= 0b00000100;
			for (delay1 = 0 ; delay1 < 1000000 ; delay1++);
			GPIO_PORTF_DATA_R &= ~(0b00000100);
			for (delay1 = 0 ; delay1 < 1000000 ; delay1++);
			t++;
		}

		else if(Button6Pressed()){
			GPIO_PORTF_DATA_R |= 0b00000100;
			for (delay1 = 0 ; delay1 < 1000000 ; delay1++);
			GPIO_PORTF_DATA_R &= ~(0b00000100);
			for (delay1 = 0 ; delay1 < 1000000 ; delay1++);
			c = 0, y = 0, t = 0;
		}
		button_onay = GPIO_PORTF_DATA_R &0b00001;
	}
	atilan = (c*25 + y*50 + t*100);
	int atilan1 = atilan;
	int yzlr = 0, onlar = 0, brlr = 0;
	yzlr = atilan % 10;
	atilan = atilan / 10;
	onlar = atilan % 10;
	atilan = atilan / 10;
	brlr = atilan % 10;
	for (delay1 = 0 ; delay1 < 1000000 ; delay1++);
	itoa(brlr,at,10);
	Lcd_Goto(1,1);
	for (delay1 = 0 ; delay1 < 1000000 ; delay1++);
	Lcd_Puts(at);
	for (delay1 = 0 ; delay1 < 1000000 ; delay1++);
	Lcd_Puts(".");
	itoa(onlar,at,10);
	Lcd_Puts(at);
	for (delay1 = 0 ; delay1 < 1000000 ; delay1++);
	itoa(yzlr,at,10);
	Lcd_Puts(at);
    for (delay1 = 0 ; delay1 < 1000000 ; delay1++);
	Lcd_Puts(" TL Attiniz.");
	for (delay1 = 0 ; delay1 < 10000000 ; delay1++);

	Lcd_Temizle();
	for (delay1 = 0 ; delay1 < 100000 ; delay1++);
	Lcd_Goto(1,1);
	for (delay1 = 0 ; delay1 < 1000000 ; delay1++);
	Lcd_Puts("1-Su 2-Cay 3-Bis");
	for (delay1 = 0 ; delay1 < 1000000 ; delay1++);
	Lcd_Goto(2,1);
	for (delay1 = 0 ; delay1 < 1000000 ; delay1++);
	Lcd_Puts("4-Ciko 5-Kahve");

	int su = 0, cay = 0, biskuvi = 0, cikolata = 0, kahve = 0;
	int odenecek = 0;
	button_onay = 1;
	while(button_onay != 0){
			if(Button1Pressed()){
				GPIO_PORTF_DATA_R |= 0b00000100;
				for (delay1 = 0 ; delay1 < 1000000 ; delay1++);
				GPIO_PORTF_DATA_R &= ~(0b00000100);
				for (delay1 = 0 ; delay1 < 1000000 ; delay1++);
				su++;
			}

			if(Button2Pressed()){
				GPIO_PORTF_DATA_R |= 0b00000100;
				for (delay1 = 0 ; delay1 < 1000000 ; delay1++);
				GPIO_PORTF_DATA_R &= ~(0b00000100);
				for (delay1 = 0 ; delay1 < 1000000 ; delay1++);
				cay++;
			}

			if(Button3Pressed()){
				GPIO_PORTF_DATA_R |= 0b00000100;
				for (delay1 = 0 ; delay1 < 1000000 ; delay1++);
				GPIO_PORTF_DATA_R &= ~(0b00000100);
				for (delay1 = 0 ; delay1 < 1000000 ; delay1++);
				biskuvi++;
			}

			if(Button4Pressed()){
				GPIO_PORTF_DATA_R |= 0b00000100;
				for (delay1 = 0 ; delay1 < 1000000 ; delay1++);
				GPIO_PORTF_DATA_R &= ~(0b00000100);
				for (delay1 = 0 ; delay1 < 1000000 ; delay1++);
				cikolata++;
			}

			if(Button5Pressed()){
				GPIO_PORTF_DATA_R |= 0b00000100;
				for (delay1 = 0 ; delay1 < 1000000 ; delay1++);
				GPIO_PORTF_DATA_R &= ~(0b00000100);
				for (delay1 = 0 ; delay1 < 1000000 ; delay1++);
				kahve++;
			}

			if(Button6Pressed()){
				GPIO_PORTF_DATA_R |= 0b00000100;
				for (delay1 = 0 ; delay1 < 1000000 ; delay1++);
				GPIO_PORTF_DATA_R &= ~(0b00000100);
				for (delay1 = 0 ; delay1 < 1000000 ; delay1++);
				su = 0, cay = 0, biskuvi = 0, cikolata = 0, kahve = 0;
			}
			button_onay = GPIO_PORTF_DATA_R &0b00001;
	}
	odenecek = su*50 + cay*100 + biskuvi*150 + cikolata*175 + kahve*200 ;
	if(odenecek > atilan1){
		Lcd_Temizle();
		for (delay1 = 0 ; delay1 < 1000000 ; delay1++);
		Lcd_Goto(1,1);
	    for (delay1 = 0 ; delay1 < 1000000 ; delay1++);
	    Lcd_Puts("Eksik para");
	    for (delay1 = 0 ; delay1 < 1000000 ; delay1++);
	    Lcd_Goto(2,1);
	    for (delay1 = 0 ; delay1 < 1000000 ; delay1++);
	    Lcd_Puts("Tekrar atiniz");
	    while(1){

	    }
	}
	/*srand(time(NULL));*/
	int hata;
	hata = ((c + y + t + su + cay + biskuvi + cikolata + kahve) % 4) + 1;
	if(hata == 2){
		Lcd_Temizle();
		for (delay1 = 0 ; delay1 < 1000000 ; delay1++);
		Lcd_Goto(1,1);
		for (delay1 = 0 ; delay1 < 1000000 ; delay1++);
		Lcd_Puts("Para Takildi");
		while(1){
			GPIO_PORTF_DATA_R |= 0b00000010;
		}
	}
	else if(hata != 2){
		GPIO_PORTF_DATA_R |= 0b00001000;
		for (delay1 = 0 ; delay1 < 2000000 ; delay1++);
		GPIO_PORTF_DATA_R &= ~(0b00001000);
		for (delay1 = 0 ; delay1 < 1000000 ; delay1++);
	}
	int urun[6]={};
	urun[1] = su;
	urun[2] = cay;
	urun[3] = biskuvi;
	urun[4] = cikolata;
	urun[5] = kahve;

	for(int a = 1 ; a < 6 ;a++){
		if (Urunler[a][1] < urun[a]){
			Lcd_Temizle();
			for (delay1 = 0 ; delay1 < 1000000 ; delay1++);
				Lcd_Goto(1,1);
				for (delay1 = 0 ; delay1 < 1000000 ; delay1++);
				Lcd_Puts("Yeterli urun yok");
			    for (delay1 = 0 ; delay1 < 1000000 ; delay1++);
			    while(1){

			    }
		}
	}
    int artan;
    artan = atilan1 - odenecek;
	int vc = 0;
	int vy = 0;
	int vt = 0;
	if(artan >= 100){
		vt = artan/100;
		artan = artan % 100;
	}
	if(artan >= 50){
		vy = artan/50;
		artan = artan % 50;
	}
	if(artan >=25){
		vc = artan/25;
		artan = artan % 25;
	}

	if(vt > Urunler[0][2]){
	        vt = vt - Urunler[0][2];
	        Urunler[0][2] = 0;
	        vy = vy + vt*2;
	        vt = 0;
	}
	if(vy > Urunler[0][1]){
		vy = vy - Urunler[0][1];
	    Urunler[0][1] = 0;
	    vc = vc + vy*2;
	    vy = 0;
	}
	if(vc > Urunler[0][0]){
		Lcd_Temizle();
		for (delay1 = 0 ; delay1 < 1000000 ; delay1++);
		Lcd_Goto(1,1);
		for (delay1 = 0 ; delay1 < 1000000 ; delay1++);
		Lcd_Puts("Kasada yeterli");
		for (delay1 = 0 ; delay1 < 1000000 ; delay1++);
		Lcd_Goto(2,1);
	    for (delay1 = 0 ; delay1 < 1000000 ; delay1++);
	    Lcd_Puts("para yok.");
		while(1){

		}
	}
	Urunler[0][2] = Urunler[0][2] - vt + t;
	Urunler[0][1] = Urunler[0][1] - vy + y;
	Urunler[0][0] = Urunler[0][0] - vc + c;

	Lcd_Temizle();
	for (delay1 = 0 ; delay1 < 1000000 ; delay1++);
	int ustu;
	ustu = atilan1 - odenecek;
	char ver[5];
	yzlr = 0, onlar = 0, brlr = 0;
    yzlr = ustu % 10;
	ustu = ustu / 10;
	onlar = ustu % 10;
	ustu = ustu / 10;
	brlr = ustu % 10;
	for (delay1 = 0 ; delay1 < 1000000 ; delay1++);
	itoa(brlr,ver,10);
	Lcd_Goto(1,1);
	for (delay1 = 0 ; delay1 < 1000000 ; delay1++);
	Lcd_Puts(ver);
	for (delay1 = 0 ; delay1 < 1000000 ; delay1++);
	Lcd_Puts(".");
	itoa(onlar,ver,10);
	Lcd_Puts(ver);
	for (delay1 = 0 ; delay1 < 1000000 ; delay1++);
	itoa(yzlr,ver,10);
	Lcd_Puts(ver);
	for (delay1 = 0 ; delay1 < 1000000 ; delay1++);
	Lcd_Puts(" TL");
	for (delay1 = 0 ; delay1 < 5000000 ; delay1++);
	Lcd_Goto(2,1);
	for (delay1 = 0 ; delay1 < 5000000 ; delay1++);
	Lcd_Puts("Para Ustu");

}

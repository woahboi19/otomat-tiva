#include "inc/hw_ints.h"
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "Button.h"
#include "inc/lm4f120h5qr.h"
void Button1_init(void){
	volatile unsigned long delay;
		  SYSCTL_RCGC2_R |= 0x00000008;     // 1) activate clock for Port D
		  delay = SYSCTL_RCGC2_R;

		  GPIO_PORTD_AMSEL_R &= ~0x40;      // 3) disable analog on PD6
		  GPIO_PORTD_PCTL_R &= ~0x0F000000; // 4) PCTL GPIO on
		  GPIO_PORTD_DIR_R &= ~0x40;        // 5) direction  input
		  GPIO_PORTD_AFSEL_R &= ~0x40;      // 6) regular port function
		  GPIO_PORTD_DEN_R |= 0x40;         // 7) enable  digital port
 }
void Button2_init(void){
	  volatile unsigned long delay;
	  SYSCTL_RCGC2_R |= 0x00000008;     // 1) activate clock for Port D
	  delay = SYSCTL_RCGC2_R;

	  GPIO_PORTD_AMSEL_R &= ~0x02;      // 3) disable analog on PD1
	  GPIO_PORTD_PCTL_R &= ~0x000000F0; // 4) PCTL GPIO on PD1
	  GPIO_PORTD_DIR_R &= ~0x02;        // 5) direction PD1 input
	  GPIO_PORTD_AFSEL_R &= ~0x02;      // 6) PD1 regular port function
	  GPIO_PORTD_DEN_R |= 0x02;         // 7) enable PD1 digital port
 }

void Button3_init(void){
	  volatile unsigned long delay;
	  SYSCTL_RCGC2_R |= 0x00000008;     // 1) activate clock for Port D
	  delay = SYSCTL_RCGC2_R;

	  GPIO_PORTD_AMSEL_R &= ~0x04;      // 3) disable analog on PD2
	  GPIO_PORTD_PCTL_R &= ~0x00000F00; // 4) PCTL GPIO on PD2
	  GPIO_PORTD_DIR_R &= ~0x04;        // 5) direction PD2 input
	  GPIO_PORTD_AFSEL_R &= ~0x04;      // 6) PD2 regular port function
	  GPIO_PORTD_DEN_R |= 0x04;         // 7) enable PD2 digital port
 }

void  Button4_init(void){
	  volatile unsigned long delay;
	  SYSCTL_RCGC2_R |= 0x00000008;     // 1) activate clock for Port D
	  delay = SYSCTL_RCGC2_R;

	  GPIO_PORTD_AMSEL_R &= ~0x08;      // 3) disable analog on PD3
	  GPIO_PORTD_PCTL_R &= ~0x0000F000; // 4) PCTL GPIO on PD3
	  GPIO_PORTD_DIR_R &= ~0x08;        // 5) direction PD3 input
	  GPIO_PORTD_AFSEL_R &= ~0x08;      // 6) PD3 regular port function
	  GPIO_PORTD_DEN_R |= 0x08;         // 7) enable PD3 digital port
 }



void Button5_init(void){
	  volatile unsigned long delay;
	  SYSCTL_RCGC2_R |= 0x00000004;     // 1) activate clock for Port C
	  delay = SYSCTL_RCGC2_R;

	  GPIO_PORTC_AMSEL_R &= ~0x010;      // 3) disable analog on PC4
	  GPIO_PORTC_PCTL_R &= ~0x000F0000; // 4) PCTL GPIO on PC4
	  GPIO_PORTC_DIR_R &= ~0x10;        // 5) direction PC4 input
	  GPIO_PORTC_AFSEL_R &= ~0x10;      // 6) PC4 regular port function
	  GPIO_PORTC_DEN_R |= 0x10;         // 7) enable PC4 digital port
  }
void Button6_init(void){
	  volatile unsigned long delay;
		  SYSCTL_RCGC2_R |= 0x00000004;     // 1) activate clock for Port C
		  delay = SYSCTL_RCGC2_R;

		  GPIO_PORTC_AMSEL_R &= ~0x20;      // 3) disable analog on PC5
		  GPIO_PORTC_PCTL_R &= ~0x00F00000; // 4) PCTL GPIO on PC5
		  GPIO_PORTC_DIR_R &= ~0x20;        // 5) direction PC5 input
		  GPIO_PORTC_AFSEL_R &= ~0x20;      // 6) PC5 regular port function
		  GPIO_PORTC_DEN_R |= 0x20;         // 7) enable PC5 digital port
}
void Button7_init(void){
	  	  volatile unsigned long delay;
	  	SYSCTL_RCGC2_R |= 0x00000004;     // 1) activate clock for Port C
	  	delay = SYSCTL_RCGC2_R;
	  	GPIO_PORTC_AMSEL_R &= ~0x80;      // 3) disable analog on PC6
	  	GPIO_PORTC_PCTL_R &= ~0xF0000000; // 4) PCTL GPIO on
	  	GPIO_PORTC_DIR_R &= ~0x80;        // 5) direction  input
	  	GPIO_PORTC_AFSEL_R &= ~0x80;      // 6)  regular port function
	  	GPIO_PORTC_DEN_R |= 0x80;         // 7) enable digital port

}
void Button8_init(void){
	 	  volatile unsigned long delay;
		  SYSCTL_RCGC2_R |= 0x00000001;      // 1) activate clock for Port A
		  delay = SYSCTL_RCGC2_R;           // allow time for clock to start
		                                    // 2) no need to unlock
		  GPIO_PORTA_AMSEL_R &= ~0x20;      // 4) disable analog function on PA5
		  GPIO_PORTA_PCTL_R &= ~0x00F00000; // 3) regular GPIO

		  GPIO_PORTA_DIR_R |= 0x20;         // 5) set direction to output
		  GPIO_PORTA_AFSEL_R &= ~0x20;      // 6) regular port function
		  GPIO_PORTA_DEN_R |= 0x20;         // 7) enable digital port
}
void Button9_init(void){
	  volatile unsigned long delay;
		  SYSCTL_RCGC2_R |= 0x00000001;      // 1) activate clock for Port A
		  delay = SYSCTL_RCGC2_R;           // allow time for clock to start
		                                    // 2) no need to unlock
		  GPIO_PORTA_AMSEL_R &= ~0x40;      // 4) disable analog function on PA6
		  GPIO_PORTA_PCTL_R &= ~0x0F000000; // 3) regular GPIO

		  GPIO_PORTA_DIR_R |= 0x40;         // 5) set direction to output
		  GPIO_PORTA_AFSEL_R &= ~0x40;      // 6) regular port function
		  GPIO_PORTA_DEN_R |= 0x40;         // 7) enable digital port
}
/*




*/
unsigned long Button1Pressed(){return GPIO_PORTD_DATA_R&0x40;}
unsigned long Button2Pressed(){return GPIO_PORTD_DATA_R&0x02;}
unsigned long Button3Pressed(){return GPIO_PORTD_DATA_R&0x04;}
unsigned long Button4Pressed(){return GPIO_PORTD_DATA_R&0x08;}
unsigned long Button5Pressed(){return GPIO_PORTC_DATA_R&0x10;}

unsigned long Button6Pressed(){return GPIO_PORTC_DATA_R&0x20;}
unsigned long Button7Pressed(){return GPIO_PORTC_DATA_R&0x80;}

unsigned long Button8Pressed(){return GPIO_PORTA_DATA_R&0x20;}
unsigned long Button9Pressed(){return GPIO_PORTA_DATA_R&0x40;}

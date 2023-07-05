#ifndef BUTTON_H_
#define BUTTON_H_


#define PD6   (GPIO_PORTD_DATA_R&0x40) //Button1
#define PD1   (GPIO_PORTD_DATA_R&0x02) //Button2
#define PD2   (GPIO_PORTD_DATA_R&0x04) //Button3
#define PD3   (GPIO_PORTD_DATA_R&0x08) //Button4
#define PC4  (GPIO_PORTC_DATA_R&0x10)  //Button5
#define PC5   (GPIO_PORTC_DATA_R&0x20) //Button6
#define PC7   (GPIO_PORTC_DATA_R&0x80) //Button7
#define PA5  (GPIO_PORTA_DATA_R&0x20) //Button8
#define PA6   (GPIO_PORTA_DATA_R&0x40) //Button9

unsigned long Button1Pressed(void);
unsigned long Button2Pressed(void);
unsigned long Button3Pressed(void);
unsigned long Button4Pressed(void);
unsigned long Button5Pressed(void);
unsigned long Button6Pressed(void);
unsigned long Button7Pressed(void);

unsigned long Button8Pressed(void);
unsigned long Button9Pressed(void);

#endif

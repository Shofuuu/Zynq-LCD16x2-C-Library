#ifndef ZYNQ_LCD_H
#define ZYNQ_LCD_H

#include <stdint.h>
#include "sleep.h"

#define LCD_DATA0		0
#define LCD_DATA1		1
#define LCD_DATA2		2
#define LCD_DATA3		3
#define LCD_RS			4
#define LCD_EN			5

// function set
#define LCD_2LINE		0x08
#define LCD_5x8DOTS		0x00
#define LCD_4BITMODE	0x00

// commands
#define LCD_CLEARDISPLAY	0x01
#define LCD_RETURNHOME		0x02
#define LCD_ENTRYMODESET	0x04
#define LCD_DISPLAYCONTROL	0x08
#define LCD_CURSORSHIFT		0x10
#define LCD_FUNCTIONSET		0x20
#define LCD_SETCGRAMADDR	0x40
#define LCD_SETDDRAMADDR	0x80

// LCD for display on/off control
#define LCD_DISPLAYON		0x04
#define LCD_DISPLAYOFF		0x00
#define LCD_CURSORON		0x02
#define LCD_CURSOROFF		0x00
#define LCD_BLINKON			0x01
#define LCD_BLINKOFF		0x00

// Display entry mode
#define LCD_ENTRYRIGHT		    0x00
#define LCD_ENTRYLEFT		    0x02
#define LCD_ENTRYSHIFTINCREMENT	0x01
#define LCD_ENTRYSHIFTDECREMENT	0x00

// register write
#define GPIO	*(__base_addr_gpio + 0)

static uint32_t* __base_addr_gpio = (uint32_t*)0x41200000;
static uint8_t __lcd_functions = 0;
static uint8_t __lcd_displaycontrol = 0;
static uint8_t __lcd_modeset = 0;

/*** Abstraction LCD Functions ***/
void lcd_init (void);
void lcd_clear (void);
void lcd_print (uint8_t *str, uint8_t len);
void lcd_write (uint8_t str);
void lcd_move (uint8_t rows, uint8_t cols);
void lcd_create_char (uint8_t location, uint8_t charmap[]);

void __display (void);
void __command (uint8_t command);
void __send (uint8_t value, uint8_t mode);
void __write4bits (uint8_t data);
void __pulse_en (void);

#endif // ZYNQ_LCD_H

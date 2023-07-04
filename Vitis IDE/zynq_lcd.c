#include "zynq_lcd.h"

void lcd_init (void) {
	__lcd_functions = LCD_2LINE | LCD_5x8DOTS | LCD_4BITMODE;
	usleep(50000);

#ifdef USE_LCD_RW
	GPIO_LCD &= ~(1 << LCD_RW);
#endif

	GPIO_LCD &= ~(1 << LCD_RS);
	GPIO_LCD &= ~(1 << LCD_EN);

	// start 8 bit mode, try to set 4 bit mode
	__write4bits(0x03);
	usleep(4500); // wait 4.1ms

	// second try
	__write4bits(0x03);
	usleep(4500); // wait 4.1ms

	// third (last)
	__write4bits(0x03);
	usleep(150);

	// set to 4-bit interface
	__write4bits(0x02);

	// set lines
	__command(LCD_FUNCTIONSET | __lcd_functions);

	__lcd_displaycontrol = LCD_DISPLAYON | LCD_CURSOROFF | LCD_BLINKOFF;
	__display();

	lcd_clear();

	__lcd_modeset = LCD_ENTRYLEFT | LCD_ENTRYSHIFTDECREMENT;
	__command(LCD_ENTRYMODESET | __lcd_modeset);
}

void lcd_clear (void) {
	__command(LCD_CLEARDISPLAY);
	usleep(2000);
}

void lcd_print (uint8_t *str, uint8_t len) {
	for (uint8_t i = 0; i < len; i++) {
		__send(str[i], 1);
	}
}

void lcd_write (uint8_t str) {
	__send(str, 1);
}

void lcd_move (uint8_t cols, uint8_t rows) {
	const uint8_t row_array[2] = {0, 0x40};

	if (rows > 1) {
		rows = 1;
	}

	__command(LCD_SETDDRAMADDR | (cols + row_array[rows]));
}

void lcd_create_char (uint8_t location, uint8_t charmap[]) {
	location &= 0x7;
	__command(LCD_SETCGRAMADDR | (location << 3));

	for (uint8_t i = 0; i < 8; i++) {
		__send(charmap[i], 1);
	}
}

void __display (void) {
	__lcd_displaycontrol |= LCD_DISPLAYON;
	__command(LCD_DISPLAYCONTROL | __lcd_displaycontrol);
}

void __command (uint8_t command) {
	__send(command, 0);
}

void __send (uint8_t value, uint8_t mode) {
	if (mode) {
		GPIO_LCD |= (1 << LCD_RS);
	} else {
		GPIO_LCD &= ~(1 << LCD_RS);
	}

	__write4bits(value >> 4);
	__write4bits(value);
}

void __write4bits (uint8_t data) {
	for (uint8_t i = 0; i < 4; i++) {
		if (data & (1 << i)) {
			GPIO_LCD |= (1 << (i));
		} else {
			GPIO_LCD &= ~(1 << (i));
		}
	}

	__pulse_en();
}

void __pulse_en (void) {
	GPIO_LCD &= ~(1 << LCD_EN);
	usleep(1);
	GPIO_LCD |= (1 << LCD_EN);
	usleep(1);
	GPIO_LCD &= ~(1 << LCD_EN);
	usleep(100);
}

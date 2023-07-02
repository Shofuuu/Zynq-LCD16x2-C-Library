#include <stdio.h>
#include "zynq_lcd.h"

int main() {
	lcd_init();

	uint8_t smile0[8] = {
		0b00000,
		0b11011,
		0b11011,
		0b00000,
		0b00000,
		0b10001,
		0b01110,
		0b00000
	};

	uint8_t smile1[8] = {
		0b00000,
		0b11011,
		0b11011,
		0b00000,
		0b11111,
		0b10001,
		0b01110,
		0b00000
	};

	lcd_create_char(0, smile0);
	lcd_create_char(1, smile1);

	lcd_clear();
	lcd_move(0,0);
	lcd_print((uint8_t*)"Shofuwan", 8);

	while (1) {
		lcd_move(0,1);
		lcd_print((uint8_t*)"Zynq Processor ", 15);
		lcd_write(0);
		sleep(1);

		lcd_move(0,1);
		lcd_print((uint8_t*)"Zynq Processor ", 15);
		lcd_write(1);
		sleep(1);
	}

	return 0;
}



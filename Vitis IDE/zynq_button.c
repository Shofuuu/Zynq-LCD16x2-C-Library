#include "zynq_button.h"

uint8_t button_read (uint8_t button) {
	uint8_t data;

	if ((GPIO_BTN & (1 << button)))
		data = 1;
	else
		data = 0;

	return data;
}

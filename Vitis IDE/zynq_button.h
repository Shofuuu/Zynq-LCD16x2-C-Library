#ifndef ZYNQ_BUTTON
#define ZYNQ_BUTTON

#include <stdint.h>

#define GPIO_BTN	*(__base_addr_button + 0)
#define BUTTON0		0
#define BUTTON1		1
#define	BUTTON2		2
#define BUTTON3		3

static uint32_t* __base_addr_button = (uint32_t*)0x41210000;

uint8_t button_read (uint8_t button);

#endif // ZYNQ_BUTTON

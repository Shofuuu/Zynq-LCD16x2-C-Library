#include <stdio.h>
#include "zynq_lcd.h"
#include "zynq_button.h"

enum state_t{
	DASHBOARD,
	MAIN_MENU,
	MENU1,
	MENU2
};

void dashboard (enum state_t *current_state);
void main_menu (enum state_t *current_state);
void menu1 (enum state_t *current_state);
void menu2 (enum state_t *current_state);

int main() {
	lcd_init();

	enum state_t state_menu = DASHBOARD;

	while (1) {
		switch (state_menu) {
			case DASHBOARD :
				dashboard(&state_menu);
			break;

			case MAIN_MENU :
				main_menu(&state_menu);
			break;

			case MENU1 :
				menu1(&state_menu);
			break;

			case MENU2 :
				menu2(&state_menu);
			break;

			default :
				state_menu = DASHBOARD;
			break;
		}
	}

	return 0;
}

void dashboard (enum state_t *current_state) {
	lcd_move(3, 0);
	lcd_print((uint8_t*)"DASHBOARD", 9);

	if (button_read(BUTTON0)){
		printf("Move to next state\n");
		lcd_clear();
		*current_state = MAIN_MENU;
		while(button_read(BUTTON0));
	}
}

void main_menu (enum state_t *current_state) {
	lcd_move(3, 0);
	lcd_print((uint8_t*)"MAIN_MENU", 9);

	if (button_read(BUTTON0)){
		printf("Move to next state\n");
		lcd_clear();
		*current_state = MENU1;
		while(button_read(BUTTON0));
	}
}

void menu1 (enum state_t *current_state) {
	lcd_move(5, 0);
	lcd_print((uint8_t*)"MENU1", 5);

	if (button_read(BUTTON0)){
		printf("Move to next state\n");
		lcd_clear();
		*current_state = MENU2;
		while(button_read(BUTTON0));
	}
}

void menu2 (enum state_t *current_state) {
	lcd_move(5, 0);
	lcd_print((uint8_t*)"MENU2", 5);

	if (button_read(BUTTON0)){
		printf("Move to next state\n");
		lcd_clear();
		*current_state = DASHBOARD;
		while(button_read(BUTTON0));
	}
}



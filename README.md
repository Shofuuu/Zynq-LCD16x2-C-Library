# Zynq LCD 16x2 Library

The Zynq LCD 16x2 Library is a C programming library developed to simplify the interaction with a 16x2 character LCD (Liquid Crystal Display) module using a Zynq processor.

## Features

- Initialization: Initialize the LCD module with configurable display mode and cursor settings.
- Text Display: Write text to the LCD screen at specific positions.
- Clearing the Display: Clear the LCD screen and reset the cursor position.
- Cursor Control: Control the cursor position on the screen, including movement and hiding.

## Requirements

- Zynq processor
- 16x2 character LCD module
- Development environment with C compiler

## Usage

```c
#include <zynq_lcd.h>

int main() {
    lcd_init();
    lcd_clear();

    lcd_print((uint8_t*)"Hello World!", 12);

    return 0;
}
```
![](https://github.com/Shofuuu/Zynq-LCD16x2-C-Library/blob/main/Zynq_LCD_demo.gif)

feel free to contact me: muhshofuwananwar@gmail.com or LinkedIn Muhammad Shofuwan Anwar


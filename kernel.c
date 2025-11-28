#include <stdint.h>

volatile uint16_t* vga = (volatile uint16_t*)0xB8000;
uint16_t cursor_pos = 0;

// Print a single character at current cursor position
void print_char(char c) {
    vga[cursor_pos++] = c | (0x0F << 8); // white on black
}

// Print a string
void print(const char* s) {
    while (*s) print_char(*s++);
}

// Read a key from keyboard port
char kbd_getchar() {
    char c;
    asm volatile (
        "inb $0x60, %0"
        : "=a"(c)
    );
    return c;
}

void kernel_main() {
    print("Day 2 OS: Type something!\n");

    while (1) {
        char c = kbd_getchar();
        if (c) {
            print_char(c); // Echo typed character
        }
    }
}

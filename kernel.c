// kernel.c — minimal C kernel

#include <stdint.h>

void print(const char *s) {
    volatile uint8_t *vga = (uint8_t*)0xB8000;
    int i = 0;

    while (*s) {
        vga[i++] = *s++;
        vga[i++] = 0x0F; // white on black
    }
}

void kernel_main() {
    print("Hello OS!");
    while (1);
}

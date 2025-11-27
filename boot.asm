; boot.asm — simple 32-bit bootloader using multiboot

MULTIBOOT_MAGIC  equ 0x1BADB002
FLAGS            equ 0x0
CHECKSUM         equ -(MULTIBOOT_MAGIC + FLAGS)

section .multiboot
    dd MULTIBOOT_MAGIC
    dd FLAGS
    dd CHECKSUM

section .text
global _start

_start:
    call kernel_main

.hang:
    jmp .hang

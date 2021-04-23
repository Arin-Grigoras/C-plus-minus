;so this is supposed to be the same equivelent to the main.cpm file in assembly

global _start

section .text

_start:
    mov rax, 1
    mov rbx, 10
    add rax, rbx
    
    ;exit command
    mov rax, 1
    int 0x80


section .data
    

;MP2 assembly code
section .text
bits 64
default rel
global asmsdot
asmsdot:
    L1:
        mov rax, [rdx] ;vec a
        mov rbx, [r8]  ;vec b
        IMUL rax, rbx
        add [r9], rax
        add rdx, 4
        add r8, 4
        loop L1
    ret
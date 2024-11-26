;MP2 assembly code
section .text
bits 64
default rel
global asmsdot
asmsdot:
    L1:
        movss xmm6, [rdx] ;vec a
        movss xmm5, [r8]  ;vec b
        mulss xmm6, xmm5
        add dword[r9], 1
        add rdx, 32
        add r8, 32
        loop L1
    ret
; MP Assembly
section .data
zero dd 0
section .text
bits 64
default rel
global asmsdot
asmsdot:
    movss xmm0, [zero] ; need to initialize to 0 since ASM gives it garbage value 
    L1:
        movss xmm1, [rdx] ;vec a []
        movss xmm2, [r8]  ;vec b []
        mulss xmm1, xmm2 ; multiply elements together
        addss xmm0, xmm1 ; add to the sdot
        add rdx, 4 ; increment by 4 bytes to next element
        add r8, 4  ; increment by 4 bytes to next element
        loop L1   
    movss [r9], xmm0 ; entire sdot moved to sdot memory location
    ret
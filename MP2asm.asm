; MP Assembly
section .text
bits 64
default rel
global asmsdot
asmsdot:
    MOV r10, rcx
    L1:
        movss xmm1, [rdx] ;vec a []
        movss xmm2, [r8]  ;vec b []
        mulss xmm1, xmm2 ; multiply elements together
        addss xmm0, xmm1 ; add to the sdot
        add rdx, 4 ; increment by 4 bytes to next element
        add r8, 4  ; increment by 4 bytes to next element
        dec r10    ; used to check looping
        cmp r10, 0
        jne L1    
    movss [r9], xmm0 ; entire sdot moved to sdot memory location
    ret
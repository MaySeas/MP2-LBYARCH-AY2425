;MP2 assembly code

section .text
bits 64
default rel
global asmsdot
asmsdot:

    MOV r10, rcx

    L1:
        movss xmm1, [rdx] ;vec a []
        movss xmm2, [r8]  ;vec b []
        mulss xmm1, xmm2
        addss xmm0, xmm1
        add rdx, 4 
        add r8, 4
        
        dec r10
        cmp r10, 0
        jne L1 
          
    movss [r9], xmm0
    
    ret
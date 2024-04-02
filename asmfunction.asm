; S17 Mary Erika Culala & Gleezell Vina Uy
; assembly part using x86-64
section .data
ZERO dq 0.0

section .text
bits 64
default rel ; to handle address relocation
global asmhello

asmhello:

	MOV R10, 0					;  x index counter	
	MOV R12, 0					;  y index counter

CHECK1:
	MOV RAX, -3
	ADD RAX, R10				; index
	CMP RAX, 0
	JGE CHECK2

	INC R10
	JMP CHECK1

CHECK2:
	MOV RAX, 3
	ADD RAX, R10
	CMP RAX, RCX
	JL FUNC
	JMP END

FUNC:
	MOV R11, R10				; Store the Index
	MOV RAX, -3
	movsd xmm2, [ZERO]			; initialize sum to 0
	ADD R11, RAX


ADD:
	addsd xmm2, [RDX + R11*8]
	INC R11
	INC RAX
	CMP RAX, 4
	JNE ADD
	movsd [R8 + R12*8], xmm2
	INC R12
	INC R10
	JMP CHECK1

END: 
	MOV [R9], R12
	NOP
	; movsd xmm0, [RDX + 0*8]
    ; addsd xmm0, [RDX + 1*8]
    ; movsd [R8 + 0*8], xmm0
	RET
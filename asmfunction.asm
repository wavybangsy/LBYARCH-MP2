; assembly part using x86-64
section .data

section .text
bits 64
default rel ; to handle address relocation
global asmhello

asmhello:
	XOR RAX, RAX
	SUB R12, RDX

	MOV R10, 0					;  loop counter						

CHECK1:
	MOV RAX, -3
	ADD RAX, R10				; index
	CMP RAX, 0
	JGE CHECK2

	INC R10
	JMP CHECK1

CHECK2:
	MOV RBX, 3
	ADD RBX, R10
	CMP RBX, R12				;compare index to n (xmm1)
	JL FUNC
	JMP END

FUNC:
	MOV RAX, -3					; -3 to 3
	MOV R15, 0					; index of Y

	MOV R14, R10				;backup index of pumasang index
	ADD R14, RAX				;index + looper of inner loop (-3 to 3)
	MOVSD XMM0, [RCX + R14*8]   ; current element based on index
	ADDSD XMM7, XMM0				; compile sum


	INC RAX
	CMP RAX, 4
	JE StoreY     ;print
	JMP FUNC


StoreY:
	MOVSD [R8 + R15*8], XMM7		; mov current element to Y
	INC R15
	JMP CHECK1

END: 
	NOP 
	RET
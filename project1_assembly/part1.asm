;;  BLG413 - System Programming
;;  Project 1 - Part 1
;;  Project Group 14
;;  Members:
;;	  I. Burak Caglar ------ 150120057
;;	  Omer Pala ------------ 150120043
;;	  O. Taylan Yildirim --- 150130063

section .data
rule dd    0

segment .text
global part1

part1:
	push ebp
	mov  ebp,esp

	mov  ebx,[ebp+8]
	add  ebx,dword 4

	mov  ecx,[ebp+12]
	sub  ecx,2

	mov  edx,[ebp+16]

	mov  eax,[ebp+20]
	mov  [rule],eax

loop:
	xor  eax,eax
	add  eax,dword [ebx-4]
	shl  eax,1
	add  eax,dword [ebx]
	shl  eax,1
	add  eax,dword [ebx+4]
	add  eax,eax
	add  eax,eax
	add  eax,[rule]
	mov  eax,dword [eax]

	mov  dword [edx],eax

	add  ebx,dword 4
	add  edx,dword 4
	dec  ecx
	cmp  ecx,0
	jne  loop

	pop ebp
	ret						;

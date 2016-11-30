segment .data
msg db "yazi yazildi!",10
len equ 14

segment .text
global repeat

repeat:
	push ebp
	mov  ebp,esp
	
	mov  ecx,[ebp+8]
	xor  eax,eax
again:
	sub  ecx,1
	push ecx
	mov  eax,4
	mov  ebx,1
	mov  ecx,msg
	mov  edx,len
	int  80h
	pop  ecx
	cmp  ecx,0
	jne  again
	
	pop ebp
	ret
	

;;  BLG413 - System Programming
;;  Project 1 - Part 2
;;  Project Group 14
;;  Members:
;;	  I. Burak Caglar ------ 150120057
;;	  Omer Pala ------------ 150120043
;;	  O. Taylan Yildirim --- 150130063

section  .data
 rule dd  0
 en   dd  0
 boy  dd  0
 en2  dd  0
 boy2 dd  0
 dort dd  4
 
 segment  .text
 global   part2
 
 part2:
 	push ebp
 	mov  ebp,esp
 	sub  esp,12
 	
 	mov  eax,[ebp+20]
 	mov  [rule],eax
 	
 	mov  eax,[ebp+12]
 	mov  eax,[eax]
 	mov  [en],eax
 	add  eax,dword 2
 	mul  dword [dort]
 	mov  [en2],eax
 	mov  eax,[ebp+12]
 	add  eax,dword 4
 	mov  eax,[eax]
 	mov  [boy],eax
 	add  eax,dword 2
 	mul  dword [dort]
 	mov  [boy2],eax
 	
 	mov  ecx,[ebp+8]
 	add  ecx,dword 4
 	add  ecx,[en2]
 	mov  edx,[ebp+16]	
 	add  edx,dword 4
 	add  edx,[en2]
	mov  [ebp-4],dword 0
	mov  [ebp-8],dword 0
	mov  [ebp-12],dword 0

loop:
 	xor  ebx,ebx
 	
 	mov  eax,[en2]
 	push edx
 	mul  dword [ebp-4]
 	pop  edx
 	add  eax,[ebp-8]
 	add  eax,[ebp-8]
 	add  eax,[ebp-8]
 	add  eax,[ebp-8]
 	mov  dword [ebp-12],eax
 	add  eax,ecx
 	
 	add  ebx,dword [eax]
 	shl  ebx,1

	sub  eax,[en2]
 	add  ebx,[eax]
 	add  eax,[en2]
 	shl  ebx,1

 	add  ebx,dword [eax+4]
 	shl  ebx,1
 	
 	add  eax,[en2]
 	add  ebx,[eax]
 	sub  eax,[en2]
 	shl  ebx,1
 	
	add  ebx,dword [eax-4]

	add  ebx,ebx
	add  ebx,ebx
	add  ebx,[rule]
	mov  ebx,dword [ebx]

	add  edx,[ebp-12]
 	mov  dword [edx],ebx
 	sub  edx,[ebp-12]
	mov  eax,[ebp-8]
	inc  eax
	mov  dword [ebp-8],eax
	mov  ebx,[en]
	cmp  eax,ebx
	jne  loop
	mov  dword [ebp-8],0
	mov  eax, [ebp-4]
	inc  eax
	mov  dword [ebp-4],eax
	mov  ebx,[boy]
	cmp  eax,ebx
	jne  loop
	
	mov  esp,ebp
 	pop  ebp
 	ret

section .data
section .text
	global _start

_start:
	mov rdi, 8
 	call intToAscii

	;exit system call
	mov rax,60
	mov rdi, 0
	syscall
intToAscii:
	mov rax, rdi
	add rax, '0'
	ret

	

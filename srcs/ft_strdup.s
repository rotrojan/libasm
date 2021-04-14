BITS 64

global ft_strdup
extern malloc
extern ft_strlen
extern ft_strcpy

section .text
	ft_strdup:
		push rbp
		mov rbp, rsp
		push rdi
		call ft_strlen
		inc rax
		mov rdi, rax
		call malloc
		mov rdi, rax
		pop rsi
		call ft_strcpy
		mov rax, rdi
		mov rsp, rbp
		pop rbp
		ret

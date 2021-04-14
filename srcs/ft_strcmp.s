BITS 64

global ft_strcmp

section .text
	ft_strcmp:
		push rbp
		mov rbp, rsp
		xor rcx, rcx
	loop:
		mov al, byte rsi[rcx]
		cmp byte rdi[rcx], al
		jne end
		cmp byte rdi[rcx], 0
		jz end
		cmp byte rsi[rcx], 0
		jz end
		inc rcx
		jmp loop
	end:
		mov al, byte rdi[rcx]
		movzx rax, al
		mov bl, byte rsi[rcx]
		movzx rbx, bl
		sub rax, rbx
		mov rsp, rbp
		pop rbp
		ret

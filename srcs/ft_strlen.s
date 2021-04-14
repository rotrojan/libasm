BITS 64

global ft_strlen

section .text
	ft_strlen:
		push rbp				; Function
		mov rbp, rsp			; prologue.
		xor rcx, rcx			; i = 0
	loop:
		cmp BYTE rdi[rcx], 0	; if (str[i] == '\0')
		je end					; exit loop
		inc rcx					; i++
		jmp loop				; keep on looping
	end:
		mov rax, rcx			; return (i)
		mov rsp, rbp			; Function
		pop rbp					; epilogue.
		ret

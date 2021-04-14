BITS 64

global ft_strcpy

section .text
	ft_strcpy:
		push rbp				; Function
		mov rbp, rsp			; prologue.
		xor rcx, rcx			; i = 0
	loop:						; while
		cmp byte rsi[rcx], 0	; if src[i] == '\0'
		je end					; then, jump to "end"
		mov al, byte rsi[rcx]	; else al = src[i]
		mov byte rdi[rcx], al	; dest[i] = al
		inc rcx					; i++
		jmp loop				; jump to "loop"
	end:
		mov al, byte rsi[rcx]	; al = src[i]
		mov byte rdi[rcx], al	; dest[i] = al[i]
		mov rax, [rdi]			; return [dest]
		mov rsp, rbp			; Function
		pop rbp					; epilogue.
		ret


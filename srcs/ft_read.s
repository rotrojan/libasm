BITS 64

SYS_READ equ 0x02
extern __errno_location

global ft_read				; Function must be accessed from outside.

section .text
	ft_read:
		push rbp				; Function
		mov rbp, rsp			; prologue.
		mov rax, SYS_READ		; Code for read system call.
		; No need to set rbx, rcx and rdx (fd, buffer and length) since they
		; already correspond to the ft_read function parameters.
		syscall					; Perform the syscall.
		cmp rax, 0
		jl error
		jmp end
	error:
		neg rax
		mov rdx, rax
		call __errno_location
		mov [rax], rdx
		mov rax, -1
		jmp end
	end:
		mov rsp, rbp			; Function
		pop rbp					; epilogue.
		ret

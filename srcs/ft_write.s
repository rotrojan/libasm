BITS 64

SYS_WRITE equ 0x01
extern __errno_location

global ft_write				; Function must be accessed from outside.

section .text
	ft_write:
		push rbp				; Function
		mov rbp, rsp			; prologue.
		mov rax, SYS_WRITE		; Code for write system call.
		; No need to set rbx, rcx and rdx (fd, buffer and length) since they
		; already correspond to the ft_write function parameters.
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
	end:
		mov rsp, rbp			; Function
		pop rbp					; epilogue.
		ret

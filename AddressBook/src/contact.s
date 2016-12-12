	.file	"contact.c"
	.section	.rodata
.LC0:
	.string	"%s, %s, %s, %s\n"
	.text
	.globl	printcon
	.type	printcon, @function
printcon:
.LFB2:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	40(%rbp), %rsi
	movq	32(%rbp), %rcx
	movq	16(%rbp), %rdx
	movq	24(%rbp), %rax
	movq	%rsi, %r8
	movq	%rax, %rsi
	movl	$.LC0, %edi
	movl	$0, %eax
	call	printf
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	printcon, .-printcon
	.ident	"GCC: (Ubuntu 5.2.1-22ubuntu2) 5.2.1 20151010"
	.section	.note.GNU-stack,"",@progbits

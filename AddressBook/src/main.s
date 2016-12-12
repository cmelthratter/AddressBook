	.file	"main.c"
	.section	.rodata
.LC0:
	.string	"contacts.txt"
.LC1:
	.string	"opening %s ...\n"
.LC2:
	.string	"r+"
	.align 8
.LC3:
	.string	"%s does not exist, creating file ...\n"
.LC4:
	.string	"w+"
.LC5:
	.string	"loading data ..."
.LC6:
	.string	"allocating memory ..."
.LC7:
	.string	"%s %s %s %s\n"
.LC8:
	.string	"loaded contact: "
.LC9:
	.string	"Successful"
.LC10:
	.string	"%s"
.LC11:
	.string	"q"
.LC12:
	.string	"bye."
.LC13:
	.string	"new"
.LC14:
	.string	"find"
	.align 8
.LC15:
	.string	"input a first and last name to search for: "
.LC16:
	.string	"%s %s"
.LC17:
	.string	"update"
.LC18:
	.string	"remove"
.LC19:
	.string	"unrecognized command"
	.text
	.globl	main
	.type	main, @function
main:
.LFB2:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$3568, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movl	$0, -3560(%rbp)
	movl	$.LC0, %esi
	movl	$.LC1, %edi
	movl	$0, %eax
	call	printf
	movl	$.LC2, %esi
	movl	$.LC0, %edi
	call	fopen
	movq	%rax, -3552(%rbp)
	cmpq	$0, -3552(%rbp)
	jne	.L2
	movl	$.LC0, %esi
	movl	$.LC3, %edi
	movl	$0, %eax
	call	printf
	movl	$.LC4, %esi
	movl	$.LC0, %edi
	call	fopen
	movq	%rax, -3552(%rbp)
	jmp	.L3
.L2:
	movl	$0, -3564(%rbp)
	movl	$.LC5, %edi
	call	puts
	movl	$.LC6, %edi
	call	puts
	jmp	.L4
.L6:
	movq	-3552(%rbp), %rdx
	leaq	-272(%rbp), %rax
	movl	$256, %esi
	movq	%rax, %rdi
	call	fgets
	movl	-3564(%rbp), %eax
	cltq
	salq	$5, %rax
	addq	%rbp, %rax
	subq	$3512, %rax
	movq	(%rax), %rdi
	movl	-3564(%rbp), %eax
	cltq
	salq	$5, %rax
	addq	%rbp, %rax
	subq	$3520, %rax
	movq	(%rax), %rsi
	movl	-3564(%rbp), %eax
	cltq
	salq	$5, %rax
	addq	%rbp, %rax
	subq	$3528, %rax
	movq	(%rax), %rcx
	movl	-3564(%rbp), %eax
	cltq
	salq	$5, %rax
	addq	%rbp, %rax
	subq	$3536, %rax
	movq	(%rax), %rdx
	leaq	-272(%rbp), %rax
	movq	%rdi, %r9
	movq	%rsi, %r8
	movl	$.LC7, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	__isoc99_sscanf
	movl	$.LC8, %edi
	movl	$0, %eax
	call	printf
	movl	-3564(%rbp), %eax
	cltq
	salq	$5, %rax
	addq	%rbp, %rax
	subq	$3536, %rax
	pushq	24(%rax)
	pushq	16(%rax)
	pushq	8(%rax)
	pushq	(%rax)
	call	printcon
	addq	$32, %rsp
	addl	$1, -3564(%rbp)
	movq	-3552(%rbp), %rax
	movq	%rax, %rdi
	call	feof
	cmpl	$-1, %eax
	je	.L17
.L4:
	movq	-3552(%rbp), %rax
	movq	%rax, %rdi
	call	feof
	testl	%eax, %eax
	je	.L6
	jmp	.L3
.L17:
	nop
.L3:
	movl	$.LC9, %edi
	call	puts
.L14:
	movl	$10, %edi
	call	malloc
	movq	%rax, -3544(%rbp)
	movq	-3544(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC10, %edi
	movl	$0, %eax
	call	__isoc99_scanf
	movq	-3544(%rbp), %rax
	movl	$.LC11, %esi
	movq	%rax, %rdi
	call	strcmp
	testl	%eax, %eax
	jne	.L7
	movl	$.LC12, %edi
	call	puts
	movl	$0, %eax
	movq	-8(%rbp), %rcx
	xorq	%fs:40, %rcx
	je	.L15
	jmp	.L16
.L7:
	movq	-3544(%rbp), %rax
	movl	$.LC13, %esi
	movq	%rax, %rdi
	call	strcmp
	testl	%eax, %eax
	jne	.L9
	movl	-3560(%rbp), %edx
	leaq	-3536(%rbp), %rcx
	movq	-3552(%rbp), %rax
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	newContact
	jmp	.L14
.L9:
	movq	-3544(%rbp), %rax
	movl	$.LC14, %esi
	movq	%rax, %rdi
	call	strcmp
	testl	%eax, %eax
	jne	.L11
	movl	$.LC15, %edi
	call	puts
	leaq	-272(%rbp), %rdx
	leaq	-336(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC16, %edi
	movl	$0, %eax
	call	__isoc99_scanf
	movl	-3556(%rbp), %eax
	cltq
	salq	$5, %rax
	addq	%rbp, %rax
	subq	$3536, %rax
	pushq	24(%rax)
	pushq	16(%rax)
	pushq	8(%rax)
	pushq	(%rax)
	call	printcon
	addq	$32, %rsp
	jmp	.L14
.L11:
	movq	-3544(%rbp), %rax
	movl	$.LC17, %esi
	movq	%rax, %rdi
	call	strcmp
	testl	%eax, %eax
	jne	.L12
	movl	-3560(%rbp), %edx
	leaq	-3536(%rbp), %rcx
	movq	-3552(%rbp), %rax
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	updateRecord
	jmp	.L14
.L12:
	movq	-3544(%rbp), %rax
	movl	$.LC18, %esi
	movq	%rax, %rdi
	call	strcmp
	testl	%eax, %eax
	jne	.L13
	movl	-3560(%rbp), %edx
	leaq	-3536(%rbp), %rax
	movl	%edx, %esi
	movq	%rax, %rdi
	call	deleteRecord
	jmp	.L14
.L13:
	movl	$.LC19, %edi
	call	puts
	jmp	.L14
.L16:
	call	__stack_chk_fail
.L15:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	main, .-main
	.section	.rodata
	.align 8
.LC20:
	.string	"enter contact information [LAST NAME] [FIRST NAME] [9 DIGIT PHONE NUMBER] [EMAIL]:"
.LC21:
	.string	"%s %s %s %s"
.LC22:
	.string	"new contact "
	.text
	.globl	newContact
	.type	newContact, @function
newContact:
.LFB3:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$160, %rsp
	movq	%rdi, -136(%rbp)
	movq	%rsi, -144(%rbp)
	movl	%edx, -148(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movl	$.LC20, %edi
	call	puts
	leaq	-32(%rbp), %rsi
	leaq	-64(%rbp), %rcx
	leaq	-128(%rbp), %rdx
	leaq	-96(%rbp), %rax
	movq	%rsi, %r8
	movq	%rax, %rsi
	movl	$.LC21, %edi
	movl	$0, %eax
	call	__isoc99_scanf
	movl	-148(%rbp), %eax
	cltq
	salq	$5, %rax
	movq	%rax, %rdx
	movq	-144(%rbp), %rax
	addq	%rax, %rdx
	leaq	-96(%rbp), %rax
	movq	%rax, (%rdx)
	movl	-148(%rbp), %eax
	cltq
	salq	$5, %rax
	movq	%rax, %rdx
	movq	-144(%rbp), %rax
	addq	%rax, %rdx
	leaq	-128(%rbp), %rax
	movq	%rax, 8(%rdx)
	movl	-148(%rbp), %eax
	cltq
	salq	$5, %rax
	movq	%rax, %rdx
	movq	-144(%rbp), %rax
	addq	%rax, %rdx
	leaq	-64(%rbp), %rax
	movq	%rax, 16(%rdx)
	movl	-148(%rbp), %eax
	cltq
	salq	$5, %rax
	movq	%rax, %rdx
	movq	-144(%rbp), %rax
	addq	%rax, %rdx
	leaq	-32(%rbp), %rax
	movq	%rax, 24(%rdx)
	movl	$.LC22, %edi
	movl	$0, %eax
	call	printf
	movl	-148(%rbp), %eax
	cltq
	salq	$5, %rax
	movq	%rax, %rdx
	movq	-144(%rbp), %rax
	addq	%rdx, %rax
	pushq	24(%rax)
	pushq	16(%rax)
	pushq	8(%rax)
	pushq	(%rax)
	call	printcon
	addq	$32, %rsp
	movl	-148(%rbp), %edx
	movq	-144(%rbp), %rcx
	movq	-136(%rbp), %rax
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	save
	addl	$1, -148(%rbp)
	nop
	movq	-8(%rbp), %rax
	xorq	%fs:40, %rax
	je	.L19
	call	__stack_chk_fail
.L19:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3:
	.size	newContact, .-newContact
	.section	.rodata
.LC23:
	.string	"who would you like to update?"
.LC24:
	.string	" %s %s"
.LC25:
	.string	"%s, %s\n"
	.align 8
.LC26:
	.string	"What would like to update? (1 - first name, 2 - last name, 3 - phone number, 4 - email)"
.LC27:
	.string	"%u"
.LC28:
	.string	"Enter first name"
.LC29:
	.string	"Enter last name"
.LC30:
	.string	"Enter a new phone number"
.LC31:
	.string	"Enter a new email"
	.text
	.globl	updateRecord
	.type	updateRecord, @function
updateRecord:
.LFB4:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$304, %rsp
	movq	%rdi, -280(%rbp)
	movq	%rsi, -288(%rbp)
	movl	%edx, -292(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movl	$.LC23, %edi
	call	puts
	leaq	-112(%rbp), %rdx
	leaq	-224(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC24, %edi
	movl	$0, %eax
	call	__isoc99_scanf
	leaq	-112(%rbp), %rdx
	leaq	-224(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC25, %edi
	movl	$0, %eax
	call	printf
	movl	$0, -268(%rbp)
	movl	-292(%rbp), %ecx
	movq	-288(%rbp), %rdx
	leaq	-112(%rbp), %rsi
	leaq	-224(%rbp), %rax
	movq	%rax, %rdi
	call	find
	movl	%eax, -268(%rbp)
	movl	$.LC26, %edi
	call	puts
	movq	-264(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC27, %edi
	movl	$0, %eax
	call	__isoc99_scanf
	movq	-264(%rbp), %rax
	movl	(%rax), %eax
	cmpl	$2, %eax
	je	.L22
	cmpl	$2, %eax
	ja	.L23
	cmpl	$1, %eax
	je	.L24
	jmp	.L27
.L23:
	cmpl	$3, %eax
	je	.L25
	cmpl	$4, %eax
	je	.L26
	jmp	.L27
.L24:
	movl	$.LC28, %edi
	movl	$0, %eax
	call	printf
	leaq	-256(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC10, %edi
	movl	$0, %eax
	call	__isoc99_scanf
	movl	-268(%rbp), %eax
	cltq
	salq	$5, %rax
	movq	%rax, %rdx
	movq	-288(%rbp), %rax
	addq	%rax, %rdx
	leaq	-256(%rbp), %rax
	movq	%rax, (%rdx)
	jmp	.L27
.L22:
	movl	$.LC29, %edi
	movl	$0, %eax
	call	printf
	leaq	-256(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC10, %edi
	movl	$0, %eax
	call	__isoc99_scanf
	movl	-268(%rbp), %eax
	cltq
	salq	$5, %rax
	movq	%rax, %rdx
	movq	-288(%rbp), %rax
	addq	%rax, %rdx
	leaq	-256(%rbp), %rax
	movq	%rax, 8(%rdx)
	jmp	.L27
.L25:
	movl	$.LC30, %edi
	movl	$0, %eax
	call	printf
	leaq	-256(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC10, %edi
	movl	$0, %eax
	call	__isoc99_scanf
	movl	-268(%rbp), %eax
	cltq
	salq	$5, %rax
	movq	%rax, %rdx
	movq	-288(%rbp), %rax
	addq	%rax, %rdx
	leaq	-256(%rbp), %rax
	movq	%rax, 16(%rdx)
	jmp	.L27
.L26:
	movl	$.LC31, %edi
	call	puts
	leaq	-256(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC10, %edi
	movl	$0, %eax
	call	__isoc99_scanf
	movl	-268(%rbp), %eax
	cltq
	salq	$5, %rax
	movq	%rax, %rdx
	movq	-288(%rbp), %rax
	addq	%rax, %rdx
	leaq	-256(%rbp), %rax
	movq	%rax, 24(%rdx)
	nop
.L27:
	movl	-292(%rbp), %edx
	movq	-288(%rbp), %rcx
	movq	-280(%rbp), %rax
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	save
	nop
	movq	-8(%rbp), %rax
	xorq	%fs:40, %rax
	je	.L28
	call	__stack_chk_fail
.L28:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4:
	.size	updateRecord, .-updateRecord
	.section	.rodata
.LC32:
	.string	"%s, %s"
.LC33:
	.string	"contact not found."
	.text
	.globl	find
	.type	find, @function
find:
.LFB5:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movq	%rdx, -40(%rbp)
	movl	%ecx, -44(%rbp)
	movl	$0, -4(%rbp)
	jmp	.L30
.L33:
	movl	-4(%rbp), %eax
	cltq
	salq	$5, %rax
	movq	%rax, %rdx
	movq	-40(%rbp), %rax
	addq	%rdx, %rax
	movq	(%rax), %rdx
	movl	-4(%rbp), %eax
	cltq
	salq	$5, %rax
	movq	%rax, %rcx
	movq	-40(%rbp), %rax
	addq	%rcx, %rax
	movq	8(%rax), %rax
	movq	%rax, %rsi
	movl	$.LC32, %edi
	movl	$0, %eax
	call	printf
	movl	-4(%rbp), %eax
	cltq
	salq	$5, %rax
	movq	%rax, %rdx
	movq	-40(%rbp), %rax
	addq	%rdx, %rax
	movq	(%rax), %rax
	movq	-24(%rbp), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	strcmp
	testl	%eax, %eax
	jne	.L31
	movl	-4(%rbp), %eax
	cltq
	salq	$5, %rax
	movq	%rax, %rdx
	movq	-40(%rbp), %rax
	addq	%rdx, %rax
	movq	8(%rax), %rax
	movq	-32(%rbp), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	strcmp
	testl	%eax, %eax
	jne	.L31
	movl	-4(%rbp), %eax
	jmp	.L32
.L31:
	addl	$1, -4(%rbp)
.L30:
	movl	-4(%rbp), %eax
	cmpl	-44(%rbp), %eax
	jle	.L33
	movl	$.LC33, %edi
	call	puts
	movl	$-1, %eax
.L32:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE5:
	.size	find, .-find
	.section	.rodata
	.align 8
.LC34:
	.string	"Enter the name of the contact to delete:"
.LC35:
	.string	""
	.text
	.globl	deleteRecord
	.type	deleteRecord, @function
deleteRecord:
.LFB6:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$96, %rsp
	movq	%rdi, -88(%rbp)
	movl	%esi, -92(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movl	$.LC34, %edi
	call	puts
	leaq	-32(%rbp), %rdx
	leaq	-64(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC16, %edi
	movl	$0, %eax
	call	__isoc99_scanf
	movl	-92(%rbp), %ecx
	movq	-88(%rbp), %rdx
	leaq	-32(%rbp), %rsi
	leaq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	find
	movl	%eax, -68(%rbp)
	movl	-68(%rbp), %eax
	cltq
	salq	$5, %rax
	movq	%rax, %rdx
	movq	-88(%rbp), %rax
	addq	%rdx, %rax
	movq	$.LC35, (%rax)
	movl	-68(%rbp), %eax
	cltq
	salq	$5, %rax
	movq	%rax, %rdx
	movq	-88(%rbp), %rax
	addq	%rdx, %rax
	movq	$.LC35, 8(%rax)
	movl	-68(%rbp), %eax
	cltq
	salq	$5, %rax
	movq	%rax, %rdx
	movq	-88(%rbp), %rax
	addq	%rdx, %rax
	movq	$.LC35, 16(%rax)
	movl	-68(%rbp), %eax
	cltq
	salq	$5, %rax
	movq	%rax, %rdx
	movq	-88(%rbp), %rax
	addq	%rdx, %rax
	movq	$.LC35, 24(%rax)
	nop
	movq	-8(%rbp), %rax
	xorq	%fs:40, %rax
	je	.L35
	call	__stack_chk_fail
.L35:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	deleteRecord, .-deleteRecord
	.section	.rodata
.LC36:
	.string	"writing to file .."
.LC37:
	.string	"done."
	.text
	.globl	save
	.type	save, @function
save:
.LFB7:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movl	%edx, -36(%rbp)
	movl	$.LC36, %edi
	call	puts
	movl	$0, -4(%rbp)
	jmp	.L37
.L38:
	movl	-4(%rbp), %eax
	cltq
	salq	$5, %rax
	movq	%rax, %rdx
	movq	-32(%rbp), %rax
	addq	%rdx, %rax
	movq	24(%rax), %rdi
	movl	-4(%rbp), %eax
	cltq
	salq	$5, %rax
	movq	%rax, %rdx
	movq	-32(%rbp), %rax
	addq	%rdx, %rax
	movq	16(%rax), %rsi
	movl	-4(%rbp), %eax
	cltq
	salq	$5, %rax
	movq	%rax, %rdx
	movq	-32(%rbp), %rax
	addq	%rdx, %rax
	movq	8(%rax), %rcx
	movl	-4(%rbp), %eax
	cltq
	salq	$5, %rax
	movq	%rax, %rdx
	movq	-32(%rbp), %rax
	addq	%rdx, %rax
	movq	(%rax), %rdx
	movq	-24(%rbp), %rax
	movq	%rdi, %r9
	movq	%rsi, %r8
	movl	$.LC7, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	fprintf
	addl	$1, -4(%rbp)
.L37:
	movl	-4(%rbp), %eax
	cmpl	-36(%rbp), %eax
	jle	.L38
	movl	$.LC37, %edi
	call	puts
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7:
	.size	save, .-save
	.ident	"GCC: (Ubuntu 5.2.1-22ubuntu2) 5.2.1 20151010"
	.section	.note.GNU-stack,"",@progbits

	.file	"main.adb"
	.text
	.section	.rodata
.LC3:
.LC4:
	.ascii	"fizz"
.LC5:
	.ascii	"buzz"
.LC6:
	.ascii	"main.adb"
	.zero	1
	.align 8
.LC0:
	.long	1
	.long	11
	.align 8
.LC1:
	.long	1
	.long	0
	.align 8
.LC2:
	.long	1
	.long	4
	.text
	.align 2
	.globl	_ada_main
	.type	_ada_main, @function
_ada_main:
.LFB1:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%r15
	pushq	%r14
	pushq	%r13
	pushq	%r12
	pushq	%rbx
	subq	$232, %rsp
	.cfi_offset 15, -24
	.cfi_offset 14, -32
	.cfi_offset 13, -40
	.cfi_offset 12, -48
	.cfi_offset 3, -56
	movl	$0, -52(%rbp)
.L6:
	cmpl	$100, -52(%rbp)
	jg	.L8
	movq	%rsp, %rax
	movq	%rax, -216(%rbp)
	leaq	-112(%rbp), %rax
	movq	%rax, -192(%rbp)
	movq	$.LC0, -184(%rbp)
	movq	-192(%rbp), %rax
	movq	-184(%rbp), %rdx
	movq	%rax, %rcx
	movq	%rdx, %rbx
	movl	-52(%rbp), %eax
	movq	%rcx, %rsi
	movl	%eax, %edi
	call	system__img_int__image_integer
	movl	%eax, %ecx
	testl	%ecx, %ecx
	movl	$0, %eax
	testl	%ecx, %ecx
	cmovns	%ecx, %eax
	cltq
	movq	%rax, -208(%rbp)
	movq	$0, -200(%rbp)
	testl	%ecx, %ecx
	testl	%ecx, %ecx
	movl	$0, %eax
	testl	%ecx, %ecx
	cmovns	%ecx, %eax
	cltq
	movq	%rax, -240(%rbp)
	movq	$0, -232(%rbp)
	testl	%ecx, %ecx
	movl	$0, %eax
	testl	%ecx, %ecx
	cmovns	%ecx, %eax
	movl	%eax, -56(%rbp)
	movl	$0, %eax
	cmpl	$0, -56(%rbp)
	cmovns	-56(%rbp), %eax
	cltq
	movq	%rax, -64(%rbp)
	movl	$0, %eax
	cmpl	$0, -56(%rbp)
	cmovns	-56(%rbp), %eax
	cltq
	movq	%rax, -256(%rbp)
	movq	$0, -248(%rbp)
	cmpl	$0, -56(%rbp)
	movl	$0, %eax
	cmpl	$0, -56(%rbp)
	cmovns	-56(%rbp), %eax
	cltq
	movq	%rax, -272(%rbp)
	movq	$0, -264(%rbp)
	movl	$0, %eax
	cmpl	$0, -56(%rbp)
	cmovns	-56(%rbp), %eax
	movslq	%eax, %rdx
	movl	$16, %eax
	subq	$1, %rax
	addq	%rdx, %rax
	movl	$16, %ebx
	movl	$0, %edx
	divq	%rbx
	imulq	$16, %rax, %rax
	subq	%rax, %rsp
	movq	%rsp, %rax
	addq	$0, %rax
	movq	%rax, -72(%rbp)
	movq	$.LC3, -176(%rbp)
	movq	$.LC1, -168(%rbp)
	leaq	-112(%rbp), %rax
	movq	%rax, -160(%rbp)
	movl	$1, -96(%rbp)
	movl	%ecx, -92(%rbp)
	leaq	-96(%rbp), %rax
	movq	%rax, -152(%rbp)
	movq	-72(%rbp), %r14
	movl	$1, -88(%rbp)
	movl	-56(%rbp), %eax
	movl	%eax, -84(%rbp)
	leaq	-88(%rbp), %rax
	movq	%rax, %r15
	movq	%r14, %rcx
	movq	%r15, %rbx
	movq	%r14, %rax
	movq	%r15, %rdx
	movq	%rcx, %rsi
	movq	%rdx, %rax
	movq	-176(%rbp), %r8
	movq	-168(%rbp), %r9
	movq	-160(%rbp), %rdx
	movq	-152(%rbp), %rcx
	movq	%rsi, %rdi
	movq	%rax, %rsi
	call	system__concat_2__str_concat_2
	movq	-72(%rbp), %r12
	movl	$1, -80(%rbp)
	movl	-56(%rbp), %eax
	movl	%eax, -76(%rbp)
	leaq	-80(%rbp), %rax
	movq	%rax, %r13
	movq	%r12, %rcx
	movq	%r13, %rbx
	movq	%r12, %rax
	movq	%r13, %rdx
	movq	%rdx, %rax
	movq	%rcx, %rdi
	movq	%rax, %rsi
	call	ada__text_io__put_line__2
	movq	-216(%rbp), %rsp
	movl	-52(%rbp), %ecx
	movl	%ecx, %edx
	sarl	$31, %edx
	movl	%ecx, %eax
	xorl	%edx, %eax
	movl	%eax, %eax
	imulq	$1431655766, %rax, %rax
	shrq	$32, %rax
	xorl	%edx, %eax
	movl	%eax, %edx
	addl	%edx, %edx
	addl	%eax, %edx
	movl	%ecx, %eax
	subl	%edx, %eax
	testl	%eax, %eax
	jne	.L3
	movq	$.LC4, -144(%rbp)
	movq	$.LC2, -136(%rbp)
	movq	-144(%rbp), %rax
	movq	-136(%rbp), %rdx
	movq	%rax, %rcx
	movq	%rdx, %rbx
	movq	%rdx, %rax
	movq	%rcx, %rdi
	movq	%rax, %rsi
	call	ada__text_io__put_line__2
.L3:
	movl	-52(%rbp), %ecx
	movl	%ecx, %edx
	sarl	$31, %edx
	movl	%ecx, %eax
	xorl	%edx, %eax
	movl	%eax, %eax
	imulq	$1717986919, %rax, %rax
	shrq	$32, %rax
	shrl	%eax
	xorl	%edx, %eax
	movl	%eax, %edx
	sall	$2, %edx
	addl	%eax, %edx
	movl	%ecx, %eax
	subl	%edx, %eax
	testl	%eax, %eax
	jne	.L4
	movq	$.LC5, -128(%rbp)
	movq	$.LC2, -120(%rbp)
	movq	-128(%rbp), %rax
	movq	-120(%rbp), %rdx
	movq	%rax, %rcx
	movq	%rdx, %rbx
	movq	%rdx, %rax
	movq	%rcx, %rdi
	movq	%rax, %rsi
	call	ada__text_io__put_line__2
.L4:
	movl	$1, %edi
	call	ada__text_io__new_line__2
	cmpl	$2147483647, -52(%rbp)
	jne	.L5
	movl	$15, %esi
	movl	$.LC6, %edi
	call	__gnat_rcheck_CE_Overflow_Check
.L5:
	movl	-52(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -52(%rbp)
	jmp	.L6
.L8:
	nop
	leaq	-40(%rbp), %rsp
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	_ada_main, .-_ada_main
	.ident	"GCC: (GNU) 10.2.1 20201125 (Red Hat 10.2.1-9)"
	.section	.note.GNU-stack,"",@progbits

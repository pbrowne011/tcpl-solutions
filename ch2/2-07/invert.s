	.file	"invert.c"
	.text
	.section	.rodata
.LC0:
	.string	"invert x"
.LC1:
	.string	"\n--------------------"
.LC2:
	.string	"invert first 2 bytes"
.LC3:
	.string	"invert last 2 bytes"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$96, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movl	$0, -64(%rbp)
	movl	$-256, -60(%rbp)
	movl	$-4096, -56(%rbp)
	movl	$-1, -52(%rbp)
	movl	$65535, -48(%rbp)
	movl	$255, -44(%rbp)
	movl	$7, -40(%rbp)
	movl	$15, -36(%rbp)
	movl	$1, -32(%rbp)
	movl	$-1, -28(%rbp)
	movl	$-559038737, -24(%rbp)
	movl	$0, -84(%rbp)
	movl	-84(%rbp), %eax
	movl	%eax, -80(%rbp)
	jmp	.L2
.L3:
	addl	$1, -80(%rbp)
.L2:
	movl	-84(%rbp), %eax
	leal	1(%rax), %edx
	movl	%edx, -84(%rbp)
	cltq
	movl	-64(%rbp,%rax,4), %eax
	cmpl	$-559038737, %eax
	jne	.L3
	leaq	.LC0(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	movl	$0, -84(%rbp)
	jmp	.L4
.L5:
	movl	-84(%rbp), %eax
	cltq
	movl	-64(%rbp,%rax,4), %eax
	movl	%eax, -76(%rbp)
	movl	$31, -72(%rbp)
	movl	$32, -68(%rbp)
	movl	-68(%rbp), %edx
	movl	-72(%rbp), %ecx
	movl	-76(%rbp), %eax
	movl	%ecx, %esi
	movl	%eax, %edi
	call	print_case
	addl	$1, -84(%rbp)
.L4:
	movl	-84(%rbp), %eax
	cmpl	-80(%rbp), %eax
	jl	.L5
	leaq	.LC1(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	leaq	.LC2(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	movl	$0, -84(%rbp)
	jmp	.L6
.L7:
	movl	-84(%rbp), %eax
	cltq
	movl	-64(%rbp,%rax,4), %eax
	movl	%eax, -76(%rbp)
	movl	$31, -72(%rbp)
	movl	$16, -68(%rbp)
	movl	-68(%rbp), %edx
	movl	-72(%rbp), %ecx
	movl	-76(%rbp), %eax
	movl	%ecx, %esi
	movl	%eax, %edi
	call	print_case
	addl	$1, -84(%rbp)
.L6:
	movl	-84(%rbp), %eax
	cmpl	-80(%rbp), %eax
	jl	.L7
	leaq	.LC1(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	leaq	.LC3(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	movl	$0, -84(%rbp)
	jmp	.L8
.L9:
	movl	-84(%rbp), %eax
	cltq
	movl	-64(%rbp,%rax,4), %eax
	movl	%eax, -76(%rbp)
	movl	$15, -72(%rbp)
	movl	$16, -68(%rbp)
	movl	-68(%rbp), %edx
	movl	-72(%rbp), %ecx
	movl	-76(%rbp), %eax
	movl	%ecx, %esi
	movl	%eax, %edi
	call	print_case
	addl	$1, -84(%rbp)
.L8:
	movl	-84(%rbp), %eax
	cmpl	-80(%rbp), %eax
	jl	.L9
	movl	$0, %eax
	movq	-8(%rbp), %rdx
	subq	%fs:40, %rdx
	je	.L11
	call	__stack_chk_fail@PLT
.L11:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.section	.rodata
	.align 8
.LC4:
	.string	"Error: position (%d) smaller than number of bits -1 (%d)\n"
	.text
	.globl	invert
	.type	invert, @function
invert:
.LFB1:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movl	%edi, -20(%rbp)
	movl	%esi, -24(%rbp)
	movl	%edx, -28(%rbp)
	movl	-28(%rbp), %eax
	subl	$1, %eax
	cmpl	%eax, -24(%rbp)
	jge	.L13
	movl	-28(%rbp), %eax
	leal	-1(%rax), %ecx
	movq	stderr(%rip), %rax
	movl	-24(%rbp), %edx
	leaq	.LC4(%rip), %rsi
	movq	%rax, %rdi
	movl	$0, %eax
	call	fprintf@PLT
	movl	$0, %eax
	jmp	.L14
.L13:
	movl	-28(%rbp), %eax
	movl	$-1, %edx
	movl	%eax, %ecx
	sall	%cl, %edx
	movl	%edx, %eax
	notl	%eax
	movl	%eax, %edx
	movl	-28(%rbp), %eax
	leal	-1(%rax), %ecx
	movl	-24(%rbp), %eax
	subl	%ecx, %eax
	movl	%eax, %ecx
	sall	%cl, %edx
	movl	%edx, %eax
	movl	%eax, -4(%rbp)
	movl	-20(%rbp), %eax
	xorl	-4(%rbp), %eax
.L14:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	invert, .-invert
	.globl	print_uint_32
	.type	print_uint_32, @function
print_uint_32:
.LFB2:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movl	%edi, -20(%rbp)
	movl	$-2147483648, -4(%rbp)
	movl	$0, -8(%rbp)
	jmp	.L16
.L19:
	movl	-8(%rbp), %eax
	movl	-20(%rbp), %edx
	movl	%eax, %ecx
	sall	%cl, %edx
	movl	%edx, %eax
	andl	-4(%rbp), %eax
	testl	%eax, %eax
	je	.L17
	movl	$49, %eax
	jmp	.L18
.L17:
	movl	$48, %eax
.L18:
	movl	%eax, %edi
	call	putchar@PLT
	addl	$1, -8(%rbp)
.L16:
	cmpl	$31, -8(%rbp)
	jle	.L19
	nop
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	print_uint_32, .-print_uint_32
	.section	.rodata
.LC5:
	.string	"x:                  "
.LC6:
	.string	"\n~x:                 "
.LC7:
	.string	"\ninvert(x, %2d, %2d):  "
.LC8:
	.string	"\n"
	.text
	.globl	print_case
	.type	print_case, @function
print_case:
.LFB3:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	movl	%edx, -12(%rbp)
	leaq	.LC5(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	-4(%rbp), %eax
	movl	%eax, %edi
	call	print_uint_32
	leaq	.LC6(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	-4(%rbp), %eax
	notl	%eax
	movl	%eax, %edi
	call	print_uint_32
	movl	-12(%rbp), %edx
	movl	-8(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC7(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	-12(%rbp), %edx
	movl	-8(%rbp), %ecx
	movl	-4(%rbp), %eax
	movl	%ecx, %esi
	movl	%eax, %edi
	call	invert
	movl	%eax, %edi
	call	print_uint_32
	leaq	.LC8(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3:
	.size	print_case, .-print_case
	.ident	"GCC: (Ubuntu 11.4.0-1ubuntu1~22.04) 11.4.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
0:
	.string	"GNU"
1:
	.align 8
	.long	0xc0000002
	.long	3f - 2f
2:
	.long	0x3
3:
	.align 8
4:

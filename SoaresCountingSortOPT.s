	.file	"SoaresCountingSortOPT.c"
	.section .rdata,"dr"
LC0:
	.ascii "w\0"
LC1:
	.ascii "A[Idx]\0"
LC2:
	.ascii "Idx\0"
LC3:
	.ascii "\12\12Array Gerado:\12\12%10s | %10s\0"
LC4:
	.ascii "\12%10d | %10d\0"
	.text
	.p2align 2,,3
	.globl	_fprintArray
	.def	_fprintArray;	.scl	2;	.type	32;	.endef
_fprintArray:
LFB15:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	subl	$28, %esp
	.cfi_def_cfa_offset 48
	movl	48(%esp), %ebp
	movl	52(%esp), %edi
	movl	$LC0, 4(%esp)
	movl	56(%esp), %eax
	movl	%eax, (%esp)
	call	_fopen
	movl	%eax, %esi
	movl	$LC1, 12(%esp)
	movl	$LC2, 8(%esp)
	movl	$LC3, 4(%esp)
	movl	%eax, (%esp)
	call	_fprintf
	testl	%edi, %edi
	jle	L2
	xorl	%ebx, %ebx
	.p2align 2,,3
L3:
	movl	0(%ebp,%ebx,4), %eax
	movl	%eax, 12(%esp)
	movl	%ebx, 8(%esp)
	movl	$LC4, 4(%esp)
	movl	%esi, (%esp)
	call	_fprintf
	incl	%ebx
	cmpl	%edi, %ebx
	jne	L3
L2:
	movl	%esi, 48(%esp)
	addl	$28, %esp
	.cfi_def_cfa_offset 20
	popl	%ebx
	.cfi_def_cfa_offset 16
	.cfi_restore 3
	popl	%esi
	.cfi_def_cfa_offset 12
	.cfi_restore 6
	popl	%edi
	.cfi_def_cfa_offset 8
	.cfi_restore 7
	popl	%ebp
	.cfi_def_cfa_offset 4
	.cfi_restore 5
	jmp	_fclose
	.cfi_endproc
LFE15:
	.section .rdata,"dr"
LC5:
	.ascii "Memory Allocation Error.\0"
	.text
	.p2align 2,,3
	.globl	_genArray
	.def	_genArray;	.scl	2;	.type	32;	.endef
_genArray:
LFB16:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	subl	$28, %esp
	.cfi_def_cfa_offset 48
	movl	48(%esp), %edi
	movl	$0, (%esp)
	call	_time
	movl	%eax, (%esp)
	call	_srand
	leal	0(,%edi,4), %eax
	movl	%eax, (%esp)
	call	_malloc
	movl	%eax, %esi
	testl	%eax, %eax
	je	L7
	testl	%edi, %edi
	jle	L9
	movl	56(%esp), %eax
	subl	52(%esp), %eax
	leal	1(%eax), %ebp
	xorl	%ebx, %ebx
	.p2align 2,,3
L10:
	call	_rand
	cltd
	idivl	%ebp
	addl	52(%esp), %edx
	movl	%edx, (%esi,%ebx,4)
	incl	%ebx
	cmpl	%edi, %ebx
	jne	L10
L9:
	movl	%esi, %eax
	addl	$28, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 20
	popl	%ebx
	.cfi_def_cfa_offset 16
	.cfi_restore 3
	popl	%esi
	.cfi_def_cfa_offset 12
	.cfi_restore 6
	popl	%edi
	.cfi_def_cfa_offset 8
	.cfi_restore 7
	popl	%ebp
	.cfi_def_cfa_offset 4
	.cfi_restore 5
	ret
L7:
	.cfi_restore_state
	movl	__imp___iob, %eax
	addl	$64, %eax
	movl	%eax, 12(%esp)
	movl	$24, 8(%esp)
	movl	$1, 4(%esp)
	movl	$LC5, (%esp)
	call	_fwrite
	movl	$1, (%esp)
	call	_exit
	.cfi_endproc
LFE16:
	.p2align 2,,3
	.globl	_SoaresCountingSort
	.def	_SoaresCountingSort;	.scl	2;	.type	32;	.endef
_SoaresCountingSort:
LFB17:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	subl	$28, %esp
	.cfi_def_cfa_offset 48
	movl	48(%esp), %ebx
	movl	60(%esp), %eax
	movl	$4, 4(%esp)
	subl	56(%esp), %eax
	incl	%eax
	movl	%eax, (%esp)
	call	_calloc
	testl	%eax, %eax
	je	L21
	movl	52(%esp), %ecx
	decl	%ecx
	movl	56(%esp), %esi
	.p2align 2,,3
L14:
	movl	(%ebx,%ecx,4), %edx
	subl	%esi, %edx
	incl	(%eax,%edx,4)
	decl	%ecx
	jns	L14
	movl	52(%esp), %edx
	testl	%edx, %edx
	jle	L12
	xorl	%edi, %edi
	xorl	%edx, %edx
	jmp	L18
	.p2align 2,,3
L22:
	movl	56(%esp), %ebp
	addl	%edi, %ebp
	movl	%ebp, (%ebx,%edx,4)
	decl	%esi
	movl	%esi, (%ecx)
	incl	%edx
	cmpl	%edx, 52(%esp)
	jle	L12
L18:
	leal	(%eax,%edi,4), %ecx
	movl	(%ecx), %esi
	testl	%esi, %esi
	jg	L22
	incl	%edi
	decl	%edx
	incl	%edx
	cmpl	%edx, 52(%esp)
	jg	L18
L12:
	addl	$28, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 20
	popl	%ebx
	.cfi_def_cfa_offset 16
	.cfi_restore 3
	popl	%esi
	.cfi_def_cfa_offset 12
	.cfi_restore 6
	popl	%edi
	.cfi_def_cfa_offset 8
	.cfi_restore 7
	popl	%ebp
	.cfi_def_cfa_offset 4
	.cfi_restore 5
	ret
L21:
	.cfi_restore_state
	movl	__imp___iob, %eax
	addl	$64, %eax
	movl	%eax, 12(%esp)
	movl	$24, 8(%esp)
	movl	$1, 4(%esp)
	movl	$LC5, (%esp)
	call	_fwrite
	movl	$1, (%esp)
	call	_exit
	.cfi_endproc
LFE17:
	.p2align 2,,3
	.globl	_ControlSort
	.def	_ControlSort;	.scl	2;	.type	32;	.endef
_ControlSort:
LFB18:
	.cfi_startproc
	pushl	%esi
	.cfi_def_cfa_offset 8
	.cfi_offset 6, -8
	pushl	%ebx
	.cfi_def_cfa_offset 12
	.cfi_offset 3, -12
	movl	12(%esp), %ecx
	movl	16(%esp), %ebx
	movl	$1, %eax
	cmpl	$1, %ebx
	jle	L24
	movl	$1, %edx
	.p2align 2,,3
L26:
	movl	-4(%ecx,%edx,4), %esi
	cmpl	%esi, (%ecx,%edx,4)
	jge	L25
	movl	%ebx, %edx
	xorl	%eax, %eax
L25:
	incl	%edx
	cmpl	%edx, %ebx
	jg	L26
L24:
	popl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_restore 3
	popl	%esi
	.cfi_def_cfa_offset 4
	.cfi_restore 6
	ret
	.cfi_endproc
LFE18:
	.def	___main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
LC6:
	.ascii "O array esta ordenado.\0"
LC7:
	.ascii "O array nao est\341 ordenado.\0"
LC8:
	.ascii "Parameters Error.\0"
LC10:
	.ascii "\12\12Run time: %f sec\12\0"
	.section	.text.startup,"x"
	.p2align 2,,3
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
LFB19:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	andl	$-16, %esp
	subl	$32, %esp
	movl	12(%ebp), %ebx
	.cfi_offset 3, -20
	.cfi_offset 6, -16
	.cfi_offset 7, -12
	call	___main
	call	_clock
	movl	%eax, %esi
	cmpl	$4, 8(%ebp)
	je	L41
L31:
	movl	__imp___iob, %eax
	addl	$64, %eax
	movl	%eax, 12(%esp)
	movl	$17, 8(%esp)
	movl	$1, 4(%esp)
	movl	$LC8, (%esp)
	call	_fwrite
	xorl	%ebx, %ebx
L37:
	movl	%ebx, (%esp)
	call	_free
	call	_clock
	subl	%esi, %eax
	flds	LC9
	pushl	%eax
	fidivrl	(%esp)
	popl	%ecx
	fstpl	4(%esp)
	movl	$LC10, (%esp)
	call	_printf
	xorl	%eax, %eax
	leal	-12(%ebp), %esp
	popl	%ebx
	.cfi_remember_state
	.cfi_restore 3
	popl	%esi
	.cfi_restore 6
	popl	%edi
	.cfi_restore 7
	popl	%ebp
	.cfi_def_cfa 4, 4
	.cfi_restore 5
	ret
L41:
	.cfi_restore_state
	movl	4(%ebx), %eax
	movl	%eax, (%esp)
	call	_atoi
	testl	%eax, %eax
	jle	L31
	movl	4(%ebx), %eax
	movl	%eax, (%esp)
	call	_atoi
	movl	%eax, %edi
	movl	8(%ebx), %eax
	movl	%eax, (%esp)
	call	_atoi
	movl	%eax, 28(%esp)
	movl	12(%ebx), %eax
	movl	%eax, (%esp)
	call	_atoi
	movl	%eax, %edx
	cmpl	$1, %edi
	je	L39
	cmpl	%eax, 28(%esp)
	je	L39
	movl	%eax, 8(%esp)
	movl	28(%esp), %eax
	movl	%eax, 4(%esp)
	movl	%edi, (%esp)
	movl	%edx, 24(%esp)
	call	_genArray
	movl	%eax, %ebx
	movl	24(%esp), %edx
	movl	%edx, 12(%esp)
	movl	28(%esp), %eax
	movl	%eax, 8(%esp)
	movl	%edi, 4(%esp)
	movl	%ebx, (%esp)
	call	_SoaresCountingSort
	movl	$1, %edx
	movl	$1, %eax
L33:
	cmpl	%eax, %edi
	jle	L42
	movl	-4(%ebx,%eax,4), %ecx
	cmpl	%ecx, (%ebx,%eax,4)
	jge	L34
	movl	%edi, %eax
	xorl	%edx, %edx
L34:
	incl	%eax
	jmp	L33
L39:
	xorl	%ebx, %ebx
L32:
	movl	$LC6, (%esp)
	call	_printf
	jmp	L37
L42:
	testl	%edx, %edx
	jne	L32
	movl	$LC7, (%esp)
	call	_printf
	jmp	L37
	.cfi_endproc
LFE19:
	.section .rdata,"dr"
	.align 4
LC9:
	.long	1148846080
	.def	_fopen;	.scl	2;	.type	32;	.endef
	.def	_fprintf;	.scl	2;	.type	32;	.endef
	.def	_fclose;	.scl	2;	.type	32;	.endef
	.def	_fwrite;	.scl	2;	.type	32;	.endef
	.def	_time;	.scl	2;	.type	32;	.endef
	.def	_srand;	.scl	2;	.type	32;	.endef
	.def	_malloc;	.scl	2;	.type	32;	.endef
	.def	_rand;	.scl	2;	.type	32;	.endef
	.def	_exit;	.scl	2;	.type	32;	.endef
	.def	_calloc;	.scl	2;	.type	32;	.endef
	.def	_clock;	.scl	2;	.type	32;	.endef
	.def	_free;	.scl	2;	.type	32;	.endef
	.def	_printf;	.scl	2;	.type	32;	.endef
	.def	_atoi;	.scl	2;	.type	32;	.endef

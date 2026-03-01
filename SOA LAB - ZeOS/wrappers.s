# 0 "wrappers.S"
# 0 "<built-in>"
# 0 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 0 "<command-line>" 2
# 1 "wrappers.S"
# 1 "include/asm.h" 1
# 2 "wrappers.S" 2
# 1 "include/errno.h" 1
# 3 "wrappers.S" 2


.globl write; .type write, @function; .align 0; write:

    pushl %ebp;
    movl %esp, %ebp;

    pushl %ebx;

    movl 8(%ebp), %edx
    movl 12(%ebp), %ecx
    movl 16(%ebp), %ebx

    movl $4, %eax;
    sysenter;
    cmpl $0, %eax;
    jge ok;
    negl %eax;
    movl %eax, errno;
    movl $-1, %eax;
ok:
    popl %ebx;
    popl %ebp
    ret

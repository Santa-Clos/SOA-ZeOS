#include <asm.h>
#include <errno.h>


ENTRY(write)
    
    pushl %ebp;
    movl %esp, %ebp;

    pushl %ebx;

    movl 8(%ebp), %edx // fd
    movl 12(%ebp), %ecx // buffer
    movl 16(%ebp), %ebx // size

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


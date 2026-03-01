#include <asm.h>
#include <errno.h>

// Ahora los wrappers estan adaptados para sysenter. En caso de querer cambiarlo solo hace falta poner int 0x80 en vez de sysenter.

ENTRY(write)
    
    pushl %ebp;
    movl %esp, %ebp;

    pushl %ebx;

    movl 8(%ebp), %edx // fd
    movl 12(%ebp), %ecx // buffer
    movl 16(%ebp), %ebx // size
    movl $4, %eax;

    push %edx
	push %ecx
	push $next_write
	push %ebp
    sysenter;
next_write:
    pop %ebp
	sub $4, %esp
	pop %ecx
	pop %edx
    cmpl $0, %eax;
    jge end_write;
    negl %eax;
    movl %eax, errno;
    movl $-1, %eax;
end_write:
    popl %ebx;
    popl %ebp
    ret

ENTRY(gettime)
    // Prólogo
    pushl %ebp
    movl %esp, %ebp

    movl $0xa, %eax
    // Prólogo sysenter
    pushl %edx
    pushl %ecx
    pushl $next_gettime // Sysenter no guarda la direccion de retorno.
    pushl %ebp
    sysenter
next_gettime:
    // Epílogo sysenter
    popl %ebp
    subl $4, %esp
    popl %ecx
    popl %edx
    cmpl $0, %eax
    jge end_gettime
    negl %eax
    movl %eax, errno
    movl $-1, %eax
end_gettime:
    movl %ebp, %esp
    pop %ebp
    ret
#include <asm.h>

ENTRY(writeMSR)
    // PRE
    pushl %ebp
    movl %esp, %ebp

    // Write the value in EDX:EAX to MSR specified by ECX. -> Doc de writeMSR
    movl 8(%ebp), %ecx // ecx = number MSR
    movl 12(%ebp), %eax // eax = value MSR
    wrmsr

    // POST
    movl %ebp, %esp
    pop %ebp
    ret


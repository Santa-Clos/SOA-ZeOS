#include <asm.h>

/* Definimos la función para que sea visible desde otros archivos (como user.c) */
ENTRY(addAsm)

    /* --- PRÓLOGO --- */
    pushl %ebp            // Guardamos el valor base de la pila anterior
    movl %esp, %ebp       // Establecemos el nuevo tope de la pila


    movl 8(%ebp), %eax    // Movemos el primer parámetro al registro %eax
    addl 12(%ebp), %eax   // Sumamos el segundo parámetro directamente a %eax

   

    /* --- EPÍLOGO --- */
    popl %ebp             // Restauramos el antiguo valor de la base de la pila
    ret                   // Volvemos al punto donde se llamó a la función

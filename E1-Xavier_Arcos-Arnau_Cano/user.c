#include <libc.h>

char buff[24];

int pid;

int __attribute__ ((__section__(".text.main")))
  main(void)
{
    /* Next line, tries to move value 0 to CR3 register. This register is a privileged one, and so it will raise an exception */
     /* __asm__ __volatile__ ("mov %0, %%cr3"::"r" (0) ); */
  write(1, "\n", 1);
  write(1, "\n", 1);
  write(1, "Hello!\n", 7);
  char c[256] = "The clock is working! Entering the testing zone...\n";
  write(1, c, strlen(c));
  write(1, "\n", 1);
  char write_test[256] = "Testing write syscall..., oh, this is already using it...\n";
  write(1, write_test, strlen(write_test));
  char gettime_test[256] = "Testing gettime syscall...\n";
  write(1, gettime_test, strlen(gettime_test));
  int time = gettime();
  char c2[64];
  itoa(time, c2);
  write(1, c2, 10);
  int size = 100000000; // large number to ensure we can see the clock ticking while we are in this loop
  while(size--);
  write(1, "\n", 1);
  time = gettime();
  itoa(time, c2);
  write(1, c2, 10);
  write(1, "\n", 1);
  write(1, "\n", 1);
  
  char pagefault_test[256] = "Seems like gettime is working! Let's try the page fault...\n";
  write(1, pagefault_test, strlen(pagefault_test));
  char* p = 0;
  *p = 'x';
  while(1);
}
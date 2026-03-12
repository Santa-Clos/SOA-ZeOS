/*
 * libc.c 
 */

#include <libc.h>
#include <errno.h>
#include <types.h>

int errno;

void itoa(int a, char *b)
{
  int i, i1;
  char c;
  
  if (a==0) { b[0]='0'; b[1]=0; return ;}
  
  i=0;
  while (a>0)
  {
    b[i]=(a%10)+'0';
    a=a/10;
    i++;
  }
  
  for (i1=0; i1<i/2; i1++)
  {
    c=b[i1];
    b[i1]=b[i-i1-1];
    b[i-i1-1]=c;
  }
  b[i]=0;
}

int strlen(char *a)
{
  int i;
  
  i=0;
  
  while (a[i]!=0) i++;
  
  return i;
}

void perror() {
  char *msg;
  switch (errno) {
    case EPERM: msg = "Operation not permitted"; break;
    case ENOENT: msg = "No such file or directory"; break;
    case ESRCH: msg = "No such process"; break;
    case EINTR: msg = "Interrupted system call"; break;
    case EIO: msg = "I/O error"; break;
    case ENXIO: msg = "No such device or address"; break;
    case E2BIG: msg = "Arg list too long"; break;
    case ENOEXEC: msg = "Exec format error"; break;
    case EBADF: msg = "Bad file number"; break;
    case ECHILD: msg = "No children"; break;
    case EAGAIN: msg = "No more processes"; break;
    case ENOMEM: msg = "Not enough core"; break;
    case EACCES: msg = "Permission denied"; break;
    case EFAULT: msg = "Bad address"; break;
    case ENOTBLK: msg = "Block device required"; break;
    case EBUSY: msg = "Mount device busy"; break;
    case EEXIST: msg = "File exists"; break;
    case EXDEV: msg = "Cross-device link"; break;
    case ENODEV: msg = "No such device"; break;
    case ENOTDIR: msg = "Not a directory"; break;
    case EISDIR: msg = "Is a directory"; break;
    case EINVAL: msg = "Invalid argument"; break;
    case ENFILE: msg = "Too many open files in system"; break;
    case EMFILE: msg = "Too many open files"; break;
    case ENOTTY: msg = "Not a typewriter"; break;
    case ETXTBSY: msg = "Text file busy"; break;
    case EFBIG: msg = "File too large"; break;
    case ENOSPC: msg = "No space left on device"; break;
    case ESPIPE: msg = "Illegal seek"; break;
    case EROFS: msg = "Read only file system"; break;
    case EMLINK: msg = "Too many links"; break;
    case EPIPE: msg = "Broken pipe"; break;
    case EDOM: msg = "Math arg out of domain of func"; break;
    case ERANGE: msg = "Math result not representable"; break;
    case ENOMSG: msg = "No message of desired type"; break;
    case EIDRM: msg = "Identifier removed"; break;
    case ECHRNG: msg = "Channel number out of range"; break;
    case EL2NSYNC: msg = "Level 2 not synchronized"; break;
    case EL3HLT: msg = "Level 3 halted"; break;
    case EL3RST: msg = "Level 3 reset"; break;
    case ELNRNG: msg = "Link number out of range"; break;
    case EUNATCH: msg = "Protocol driver not attached"; break;
    case ENOCSI: msg = "No CSI structure available"; break;
    case EL2HLT: msg = "Level 2 halted"; break;
    case EDEADLK: msg = "Deadlock condition"; break;
    case ENOLCK: msg = "No record locks available"; break;
    case EBADE: msg = "Invalid exchange"; break;
    case EBADR: msg = "Invalid request descriptor"; break;
    case EXFULL: msg = "Exchange full"; break;
    case ENOANO: msg = "No anode"; break;
    case EBADRQC: msg = "Invalid request code"; break;
    case EBADSLT: msg = "Invalid slot"; break;
    case EBFONT: msg = "Bad font file fmt"; break;
    case ENOSTR: msg = "Device not a stream"; break;
    case ENODATA: msg = "No data (for no delay io)"; break;
    default: msg = "Unknown error"; break;  
  }
  write(1, msg, strlen(msg));
}
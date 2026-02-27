/*
 * sys.c - Syscalls implementation
 */
#include <devices.h>

#include <utils.h>

#include <io.h>

#include <mm.h>

#include <mm_address.h>

#include <sched.h>

#include <errno.h>

#define LECTURA 0
#define ESCRIPTURA 1

int check_fd(int fd, int permissions)
{
  if (fd!=1) return -9; /*EBADF*/
  if (permissions!=ESCRIPTURA) return -13; /*EACCES*/
  return 0;
}

int sys_ni_syscall()
{
	return -38; /*ENOSYS*/
}

int sys_write(int fd, char *buffer, int size) {
  int check = check_fd(fd, ESCRIPTURA);
  if(check < 0) return check;
  if(buffer == NULL) return -EFAULT;
  if(size < 0) return -EINVAL;

  int copy_size;
  char *sys_buffer[255];
  int bytes = 0;

  while(size > 0) {

    if(size > (int)sizeof(sys_buffer)) copy_size = (int)sizeof(sys_buffer);
    else copy_size = size;

    if(!access_ok(VERIFY_READ, buffer, size)) return -EFAULT;

    if(copy_from_user(buffer, sys_buffer, copy_size) < 0) return -EINVAL;

    if(copy_size < 0) return copy_size;
    sys_write_console(sys_buffer, copy_size);

    buffer += copy_size;
    size -= copy_size;
    bytes += copy_size;
  }
  return bytes;
}
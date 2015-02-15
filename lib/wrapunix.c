/* wrapunix.c --- 包裹 UNIX 系統調用 */
#include "unp.h"

ssize_t
Write(int fd, const void *buf, size_t nbytes)
{
  int n;
  if ((n = write(fd, buf, nbytes)) < 0)
    err_sys("write error");
  return n;
}

ssize_t
Read(int fd, void *buf, size_t nbytes)
{
  int n;
  if ((n = read(fd, buf, nbytes)) < 0)
    err_sys("read error");
  return n;
}

void
Close(int fd)
{
  if (close(fd) < 0)
    err_sys("close error");
}

int
Fork()
{
  int ret = fork();
  if (ret < 0)
    err_sys("fork error");
  return ret;
}

Sigfunc *
Signal(int signo, Sigfunc *func)
{
  Sigfunc *ret = signal(signo, func);
  if (ret == SIG_ERR)
    err_sys("signal error");
  return ret;
}

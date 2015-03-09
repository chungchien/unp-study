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

int Select(int nfds, fd_set *readfds, fd_set *writefds,
           fd_set *exceptfds, struct timeval *timeout)
{
  int ret;
  if ((ret = select(nfds, readfds, writefds, exceptfds, timeout)) < 0)
    err_sys("select error");
  return ret;
}

void
Shutdown(int sockfd, int hwo)
{
  if (shutdown(sockfd, hwo) < 0)
    err_sys("shutdown error");
}

int Poll(struct pollfd *fdarray, unsigned long nfds, int timeout)
{
  int ret;
  if ((ret = poll(fdarray, nfds, timeout)) < 0)
    err_sys("poll error");
  return ret;
}

void Getsockopt(int sockfd, int level, int optname, void *optval,
                socklen_t *optlen)
{
  if (getsockopt(sockfd, level, optname, optval, optlen) < 0)
    err_sys("getsockopt error");
}

void Setsockopt(int sockfd, int level, int optname, const void *optval,
                socklen_t optlen)
{
  if (setsockopt(sockfd, level, optname, optval, optlen) < 0)
    err_sys("setsockopt error");
}


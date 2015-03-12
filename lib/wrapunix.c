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

ssize_t Recv(int s, void *buf, size_t len, int flags)
{
  ssize_t ret = recv(s, buf, len, flags);
  if (ret < 0)
    err_sys("recv error");
  return ret;
}

ssize_t Recvfrom(int sockfd, void *buf, size_t buflen, int flags,
             SA *from, socklen_t *fromlen)
{
  ssize_t ret = recvfrom(sockfd, buf, buflen, flags, from, fromlen);
  if (ret < 0)
    err_sys("recvfrom error");
  return ret;
}

ssize_t Recvmsg(int sockfd, struct msghdr *msg, int flags)
{
  ssize_t ret = recvmsg(sockfd, msg, flags);
  if (ret == -1)
    err_sys("recvmsg error");
  return ret;
}

ssize_t Send(int sockfd, const void *msg, size_t len, int flags)
{
  ssize_t ret = send(sockfd, msg, len, flags);
  if (ret == -1)
    err_sys("send error");
  return ret;
}

ssize_t Sendto(int sockfd, const void *msg, size_t len, int flags,
               const struct sockaddr *to, socklen_t tolen)
{
  ssize_t ret = sendto(sockfd, msg, len, flags, to, tolen);
  if (ret == -1)
    err_sys("sendto error");
  return ret;
}

ssize_t Sendmsg(int sockfd, const struct msghdr *msg, int flags)
{
  ssize_t ret = sendmsg(sockfd, msg, flags);
  if (ret == -1)
    err_sys("sendmsg error");
  return ret;
}

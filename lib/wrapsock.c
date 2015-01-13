#include "unp.h"

int
Socket(int family, int type, int protocol)
{
  int n;

  if ((n = socket(family, type, protocol)) < 0)
    err_sys("socket error");
  return n;
}

int
Bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen)
{
  if (bind(sockfd, addr, addrlen) < 0)
    err_sys("bind error");
  return 0;
}

int
Listen(int sockfd, int backlog)
{
  if (listen(sockfd, backlog) < 0)
    err_sys("listen error");
  return 0;
}

int
Accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen)
{
  int n;

  if ((n = accept(sockfd, addr, addrlen)) < 0)
    err_sys("accept error");
  return n;
}

int
Connect(int sockfd, const struct sockaddr *name, socklen_t namelen)
{
  if (connect(sockfd, name, namelen) < 0)
    err_sys("connect error");
  return 0;
}

int
Write(int fd, const void *buf, size_t nbytes)
{
  int n;
  if ((n = write(fd, buf, nbytes)) < 0)
    err_sys("write error");
  return n;
}

int
Read(int fd, void *buf, size_t nbytes)
{
  int n;
  if ((n = read(fd, buf, nbytes)) < 0)
    err_sys("read error");
  return n;
}

int
Close(int fd)
{
  if (close(fd) < 0)
    err_sys("close error");
  return 0;
}

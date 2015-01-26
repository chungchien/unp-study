#include "unp.h"

int
Socket(int family, int type, int protocol)
{
  int n;

  if ((n = socket(family, type, protocol)) < 0)
    err_sys("socket error");
  return n;
}

void
Bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen)
{
  if (bind(sockfd, addr, addrlen) < 0)
    err_sys("bind error");
}

void
Listen(int sockfd, int backlog)
{
  const char *ptr;

  /* 使用戶可通過 LISTENQ 環境變量覆寫 backlog  */
  if ((ptr = getenv("LISTENQ")) != NULL)
    backlog = atoi(ptr);

  if (listen(sockfd, backlog) < 0)
    err_sys("listen error");
}

int
Accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen)
{
  int n;

  if ((n = accept(sockfd, addr, addrlen)) < 0)
    err_sys("accept error");
  return n;
}

void
Connect(int sockfd, const struct sockaddr *name, socklen_t namelen)
{
  if (connect(sockfd, name, namelen) < 0)
    err_sys("connect error");
}

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

void Sctp_bindx(int sockfd, struct sockaddr *addrs,
                int addrcnt, int flags)
{
  if (sctp_bindx(sockfd, addrs, addrcnt, flags) == -1)
    err_sys("sctp_bindx error");
}

void Sctp_connectx(int sockfd, struct sockaddr *addrs,
                   int addrcnt, sctp_assoc_t *id)
{
  if (sctp_connectx(sockfd, addrs, addrcnt, id) == -1)
    err_sys("sctp_connectx error");
}

ssize_t Sctp_sendmsg(int sockfd, const void *msg, size_t len,
                  const struct sockaddr *to, socklen_t tolen,
                  uint32_t ppid, uint32_t flags,
                  uint16_t stream_no, uint32_t timetolive,
                  uint32_t context)
{
  ssize_t sz = sctp_sendmsg(sockfd, msg, len, to, tolen, ppid,
                            flags, stream_no, timetolive, context);
  if (sz == -1)
    err_sys("sctp_sendmsg error");
  return sz;
}

ssize_t Sctp_recvmsg(int sockfd, void *msg, size_t len,
                     struct sockaddr *from, socklen_t *fromlen,
                     struct sctp_sndrcvinfo *sinfo, int *msg_flags)
{
  ssize_t sz = sctp_recvmsg(sockfd, msg, len, from,
                            fromlen, sinfo, msg_flags);
  if (sz == -1)
    err_sys("sctp_recvmsg error");
  return sz;
}

int Sctp_getpaddrs(int sockfd, sctp_assoc_t id,
                   struct sockaddr **addrs)
{
  int n = sctp_getpaddrs(sockfd, id, addrs);
  if (n == -1)
    err_sys("sctp_getpaddrs error");
  return n;
}

int Sctp_getladdrs(int sockfd, sctp_assoc_t id,
                   struct sockaddr **addrs)
{
  int n = sctp_getladdrs(sockfd, id, addrs);
  if (n == -1)
    err_sys("sctp_getladdrs error");
  return n;
}

void Sctp_opt_info(int sockfd, sctp_assoc_t id, int opt,
                   void *arg, socklen_t *size)
{
  if (sctp_opt_info(sockfd, id, opt, arg, size) == -1)
    err_sys("sctp_opt_info error");
}

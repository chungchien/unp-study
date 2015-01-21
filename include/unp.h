#ifndef UNPEXERCISE_UNP_H_
#define UNPEXERCISE_UNP_H_
#include "config.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <errno.h>

#define MAXLINE		1024
#define LISTENQ		10
typedef struct sockaddr SA;

#if !defined(HAVE_BZERO)
inline void bzero(void *dest, size_t nbytes)
{
  memset(dest, 0, nbytes);
}
#endif  /* !defined(HAVE_BZERO) */

/*
 * socket包裹函數。皆以大寫其所包含數首字母以名之。
 */
int Socket(int family, int type, int protocol);
int Bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
int Listen(int sockfd, int backlog);
int Accept(int sockfd, struct sockaddr *addr, socklen_t *addlen);
int Connect(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
int Write(int fd, const void *buf, size_t nbytes);
int Read(int fd, void *buf, size_t nbytes);
int Close(int fd);
/*
 * Nonfatal error related to a system call.
 * Print a message and return
 */
void err_ret(const char *fmt, ...);
/*
 * Fatal error related to a system call.
 * Print a message and terminate.
 */
void err_sys(const char *fmt, ...);
/*
 * Fatal error unrelated to a system call.
 * Error code passed as explict parameter.
 * Print a message and terminate.
 */
void err_exit(int error, const char *fmt, ...);
/*
 * Fatal error related to a system call.
 * Print a message, dump core, and terminate.
 */
void err_dump(const char *fmt, ...);
/*
 * Nonfatal error unrelated to a system call.
 * Print a message and return.
 */
void err_msg(const char *fmt, ...);
/*
 * Fatal error unrelated to a system call.
 * Print a message and terminate.
 */
void err_quit(const char *fmt, ...);

#ifndef INET_ADDRSTRLEN
#define INET_ADDRSTRLEN 16  /* for IPv4 dotted-decimal */
#endif

#ifndef INET6_ADDRSTRLEN
#define INET6_ADDRSTRLEN 46  /* for IPv6 hex string */
#endif

#if !defined(HAVE_INET_PTON)
int inet_pton(int family, const char *strptr, void *addrptr);
#endif

#if !defined(HAVE_INET_NTOP)
const char *inet_ntop(int family,
                      const void *addrptr,
                      char *strptr,
                      size_t len);
#endif

/* 將sa中的IP地址轉換肌字符串。其中IPv4轉換為點分十進制後加冒號加端口號，
 * IPv6轉換為中括號包圍的十六進制後加冒號加端口號 */
char *sock_ntop(const struct sockaddr *sa, socklen_t salen);
/* 比較兩個套節字地址結構的地址部分。相同返回0，否則返回非0值 */
int sock_cmp_addr(const struct sockaddr *sockaddr1,
                  const struct sockaddr *sockaddr2,
                  socklen_t addrlen);

#endif // UNPEXERCISE_UNP_H_

#ifndef UNPEXERCISE_UNP_H_
#define UNPEXERCISE_UNP_H_
#ifdef __cplusplus
extern "C" {
#endif

#include "config.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <memory.h>
#include <errno.h>
#include <assert.h>
#include <sys/un.h>
#include <signal.h>
#include <sys/select.h>
#include <sys/time.h>
#include <poll.h>

#define MAXLINE		1024
#define LISTENQ		1024
#define SERV_PORT       9876
#define SERV_PORT_STR   "9876"

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
void Bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
void Listen(int sockfd, int backlog);
int Accept(int sockfd, struct sockaddr *addr, socklen_t *addlen);
void Connect(int sockfd, const struct sockaddr *addr, socklen_t addrlen);

void str_echo(int sockfd);
void str_cli(FILE *fp, int sockfd);

/* unix 系統調用包裹函數  */
ssize_t Write(int fd, const void *buf, size_t nbytes);
ssize_t Read(int fd, void *buf, size_t nbytes);
void Close(int fd);
int Fork();
int Select(int nfds, fd_set *readfds, fd_set *writefds,
           fd_set *exceptfds, struct timeval *timeout);
void Shutdown(int sockfd, int how);
int Poll(struct pollfd *fdarray, unsigned long nfds, int timeout);

typedef void Sigfunc(int signo);
#if !defined(HAVE_SIGNAL_PROTO)
Sigfunc * signal(int signo, Sigfunc *func);
#endif
Sigfunc * Signal(int signo, Sigfunc *func);

/* stdio 的包裹函數  */
char *Fgets(char *buf, int size, FILE *fp);
int Fputs(const char *str, FILE *fp);
FILE *Fopen(const char *path, const char *mode);
void Fclose(FILE *fp);

const char * Inet_ntop(int family, const void *addrptr,
                       char *strptr, size_t len);
void Inet_pton(int family, const char *strptr, void *addrptr);

/* 我們自己的庫函數 */
ssize_t Writen(int fd, const void *buf, size_t nbytes);
ssize_t Readn(int fd, void *buf, size_t nbytes);
ssize_t Readline(int fd, void *buf, size_t max_len);

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

/* 儘量從文件描述符䢱取“n”個字符 */
ssize_t readn(int fd, void *buff, size_t nbytes);
/* 寫入“n”個字符到給定文件描述符；如果不能寫够n個則返回-1 */
ssize_t writen(int fd, const void *buff, size_t nbytes);
/* 讀取一行，類似fgets函數，會自動添加空字符 */
ssize_t readline(int fd, void *buff, size_t maxlen);
#if !defined(USE_READLINE_NOBUFFER)
/* 獲取readline使用的緩沖區 */
ssize_t readlinebuf(void **vptrptr);
#endif

/* 將sa中的IP地址轉換肌字符串。其中IPv4轉換為點分十進制後加冒號加端口號，
 * IPv6轉換為中括號包圍的十六進制後加冒號加端口號 */
char *sock_ntop(const struct sockaddr *sa, socklen_t salen);
/* 比較兩個套節字地址結構的地址部分，若相同返回0。 */
int sock_cmp_addr(const struct sockaddr *sockaddr1,
                  const struct sockaddr *sockaddr2,
                  socklen_t addrlen);
/* 比較兩個套節字地址結構的端口部分。若相同返回0。 */
int sock_cmp_port(const struct sockaddr *sockaddr1,
                  const struct sockaddr *sockaddr2,
                  socklen_t addrlen);

/* 獲取网絡套節字地址的端口號 。如果不提供端口號的地址，返回 -1*/
int sock_get_port(const struct sockaddr *sockaddr, socklen_t addlen);

/* 設置网絡套節字地址的端口號 */
void sock_set_port(struct sockaddr *sockaddr,
                   socklen_t addrlen, int port);


#ifndef max
#define max(a, b) ((a) > (b) ? (a) : (b))
#endif // max
#ifndef min
#define min(a, b) ((a) < (b) ? (a) : (b))
#endif // min

#ifdef __cplusplus
}
#endif
#endif // UNPEXERCISE_UNP_H_

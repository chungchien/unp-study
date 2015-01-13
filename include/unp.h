#ifndef UNPEXERCISE_UNP_H_
#define UNPEXERCISE_UNP_H_
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

#define MAXLINE		1024
#define LISTENQ		10
typedef struct sockaddr SA;

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


#endif // UNPEXERCISE_UNP_H_

#include "unp.h"
#include <netinet/tcp.h>

static void print_rcvbuf_and_mss(int sockfd);

int
main(int argc, char *argv[])
{
  int sockfd, n;
  char recvline[MAXLINE + 1];
  struct sockaddr_in servaddr;

  if (argc != 2)
    err_quit("usage: %s <IPaddress>", argv[0]);

  if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    err_sys("socket error");

  printf("before connect: \n");
  print_rcvbuf_and_mss(sockfd);

  bzero(&servaddr, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(9999);  /* daytime server */
  if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0)
    err_quit("inet_pton error for %s", argv[1]);

  if (connect(sockfd, (SA *) &servaddr, sizeof(servaddr)) < 0)
    err_sys("connect error");

  printf("after connect: \n");
  print_rcvbuf_and_mss(sockfd);

  while ((n = read(sockfd, recvline, MAXLINE)) > 0) {
    recvline[n] = 0;
    if (fputs(recvline, stdout) == EOF)
      err_sys("fputs error");
  }
  if (n < 0)
    err_sys("read error");

  exit(0);
}

static void print_rcvbuf_and_mss(int sockfd)
{
  long val;
  socklen_t len;

  len = sizeof(val);
  if (getsockopt(sockfd, SOL_SOCKET, SO_RCVBUF, &val, &len) < 0)
    err_sys("getsockopt error");
  printf("\treceive buffer = %ld", val);

  len = sizeof(val);
  if (getsockopt(sockfd, IPPROTO_TCP, TCP_MAXSEG, &val, &len) < 0)
    err_sys("getsockopt error");
  printf(", MSS = %ld\n", val);
}

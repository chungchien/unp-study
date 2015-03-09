#include "unp.h"

#define CLI_PORT 1500

int main(int argc, char *argv[])
{
  int sockfd, flag;
  struct sockaddr_in cliaddr, servaddr;

  if (argc != 3) {
    err_quit("usage: %s <server IP> <server port>", argv[0]);
  }

  sockfd = Socket(AF_INET, SOCK_STREAM, 0);
  flag = 1;
  Setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &flag, sizeof(flag));

  bzero(&cliaddr, sizeof(cliaddr));
  cliaddr.sin_family = AF_INET;
  cliaddr.sin_port = htons(CLI_PORT);
  cliaddr.sin_addr.s_addr = htonl(INADDR_ANY);

  printf("[%d]Binding to %s ...\n", getpid(),
         sock_ntop((SA *) &cliaddr, sizeof(cliaddr)));
  Bind(sockfd, (SA *) &cliaddr, sizeof(cliaddr));
  printf("[%d]Bound to %s\n", getpid(),
         sock_ntop((SA *) &cliaddr, sizeof(cliaddr)));

  sleep(5);  /* 等待另一个客户端绑定到相同的端口号 */

  bzero(&servaddr, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(atoi(argv[2]));
  Inet_pton(AF_INET, argv[1], &servaddr.sin_addr);

  Connect(sockfd, (SA *) &servaddr, sizeof(servaddr));
  printf("[%d]Connected to %s\n", getpid(),
         sock_ntop((SA *) &servaddr, sizeof(servaddr)));

  sleep(10);

  Close(sockfd);
  exit(EXIT_SUCCESS);
}

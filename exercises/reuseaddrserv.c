#include "unp.h"

int main(int argc, char *argv[])
{
  int listenfd, sockfd;
  /* int flag; */
  socklen_t len;
  struct sockaddr_in cliaddr, servaddr;

  if (argc != 3) {
    err_quit("usge: %s <server IP> <server port>", argv[0]);
  }

  listenfd = Socket(AF_INET, SOCK_STREAM, 0);

  /* flag = 1; */
  /* Setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &flag, sizeof(flag)); */

  bzero(&servaddr, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(atoi(argv[2]));
  Inet_pton(AF_INET, argv[1], &servaddr.sin_addr);

  Bind(listenfd, (SA *) &servaddr, sizeof(servaddr));

  Listen(listenfd, 5);

  for ( ; ; ) {
    len = sizeof(cliaddr);
    if ((sockfd = accept(listenfd, (SA *) &cliaddr, &len)) < 0) {
      if (errno == EPIPE || errno == EINTR)
        continue;
      err_sys("accept error");
    }
    printf("[%s] from %s\n",
           argv[2], sock_ntop((SA *) &cliaddr, sizeof(cliaddr)));
  }

  exit(EXIT_SUCCESS);
}

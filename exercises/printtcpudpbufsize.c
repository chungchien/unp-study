#include "unp.h"

int main()
{
  int sockfd;
  long bufsize;
  socklen_t len;

  sockfd = Socket(AF_INET, SOCK_STREAM, 0);
  len = sizeof(bufsize);
  if (getsockopt(sockfd, SOL_SOCKET, SO_RCVBUF, &bufsize, &len) < 0)
    err_sys("getsockopt error");
  printf("TCP's recve buffer size is %ld\n", bufsize);
  len = sizeof(bufsize);
  if (getsockopt(sockfd, SOL_SOCKET, SO_SNDBUF, &bufsize, &len) < 0)
    err_sys("getsockopt error");
  printf("TCP's recve send size is %ld\n", bufsize);
  close(sockfd);


  sockfd = Socket(AF_INET, SOCK_DGRAM, 0);
  len = sizeof(bufsize);
  if (getsockopt(sockfd, SOL_SOCKET, SO_RCVBUF, &bufsize, &len) < 0)
    err_sys("getsockopt error");
  printf("UDP's recve buffer size is %ld\n", bufsize);
  len = sizeof(bufsize);
  if (getsockopt(sockfd, SOL_SOCKET, SO_SNDBUF, &bufsize, &len) < 0)
    err_sys("getsockopt error");
  printf("UDP's recve send size is %ld\n", bufsize);
  close(sockfd);

  exit(EXIT_SUCCESS);
}

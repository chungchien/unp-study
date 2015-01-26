#include "unp.h"

ssize_t readn(int fd, void *vptr, size_t n)
{
  size_t nleft;
  ssize_t nread;
  char *ptr;

  ptr = vptr;
  nleft = n;
  while (nleft > 0) {
    if ((nread = read(fd, ptr, nleft)) < 0) {
      if (errno == EINTR)
        nread = 0;  /* all call read() again */
      else
        return -1;
    } else if (nread == 0) {
      break;  /* EOF */
    }
    nleft -= nread;
    ptr += nread;
  }
  return n - nleft;  /* return >= 0 */
}

ssize_t Readn(int fd, void *buf, size_t nbytes)
{
  ssize_t nret = readn(fd, buf, nbytes);
  if (nret < 0)
    err_sys("readn error");
  return nret;
}

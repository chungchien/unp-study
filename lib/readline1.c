#include "unp.h"

/* 讀取一行；效率很低，只是用於示例。 */
ssize_t readline(int fd, void *vptr, size_t maxlen)
{
  ssize_t n, rc;
  char c, *ptr;

  ptr = vptr;
  for (n = 1; n < maxlen; n++) {
 again:
    if ((rc = read(fd, &c, 1)) == 1) {
      *ptr++ = c;
      if (c == '\n')
        break;
    } else if (rc == 0) {
      *ptr = 0;
      return n - 1;  /* EOF, n - 1 bytes were read */
    } else {
      if (errno == EINTR)
        goto again;
      return -1;  /* error, errno set by read() */
    }
  }

  *ptr = 0;  /* null terminate like fgets() */
  return n;
}

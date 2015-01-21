/* 帶緩沖的readline實現。不能與readn或是系統的讀函數混用，因爲可能會遺
 * 漏數據。 */
#include "unp.h"

static int read_cnt;
static char *read_ptr;
static char read_buf[MAXLINE];

/* 我們自己的read函數，一次從緩沖區讀取一個字符；如果緩沖區已空，則從
 * 文件描述符讀取數據到緩沖區。出錯返回-1 */
static ssize_t my_read(int fd, char *ptr)
{
  if (read_cnt <= 0) {
 again:
    if ((read_cnt = read(fd, read_buf, sizeof(read_buf))) < 0) {
      if (errno == EINTR)
        goto again;
      return -1;
    } else if (read_cnt == 0) {
      return 0;
    }
    readptr = read_buf;
  }

  read_cnt--;
  *ptr = *read_ptr++;
  return 1;
}

ssize_t readline(int fd, void *vptr, size_t maxlen)
{
  ssize_t n, rc;
  char c, *ptr;

  ptr = vptr;
  for (n = 1; n < maxlen; n++) {
    if ((rc = my_read(fd, &c)) == 1) {
      *ptr++ = c;
      if (c == '\n')
        break;
    } else if (rc == 0) {
      *ptr = 0;
      return n - 1;
    } else {
      return -1;
    }
  }
  *ptr = 0;
  return n;
}

/* 返回緩沖區，用於調試。 */
ssize_t readlinebuf(void **vptrptr)
{
  if (read_cnt)
    *vptrptr = read_ptr;
  return read_cnt;
}

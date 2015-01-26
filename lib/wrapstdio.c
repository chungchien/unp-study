#include "unp.h"

char *
Fgets(char *buf, int size, FILE *stream)
{
  char *ret = fgets(buf, size, stream);
  if (ret == NULL && ferror(stream))
    err_sys("fgets error");
  return ret;
}

int
Fputs(const char *str, FILE *stream)
{
  int ret = fputs(str, stream);
  if (ret == EOF)
    err_sys("fputs error");
  return ret;
}

void Fclose(FILE *fp)
{
  if (fclose(fp) == EOF)
    err_sys("fclose error");
}

FILE *Fopen(const char *path, const char *mode)
{
  FILE *fp;
  if ((fp = fopen(path, mode)) == NULL)
    err_sys("fopen error");
  return fp;
}

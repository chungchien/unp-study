#include "unp.h"
#include <assert.h>

/* 比較兩個套節字結構的地址；若相等則返回0。 */
int sock_cmp_addr(const struct sockaddr *addr1,
                  const struct sockaddr *addr2,
                  socklen_t addrlen)
{
  int family = addr1->sa_family;
  assert(addr1->sa_family == addr2->sa_family);

  switch (family) {
    case AF_INET: {
      struct sockaddr_in *sin1 = (struct sockaddr_in *) addr1;
      struct sockaddr_in *sin2 = (struct sockaddr_in *) addr2;
      return memcmp(&sin1->sin_addr, &sin2->sin_addr, sizeof(struct in_addr));
    }
    case AF_INET6: {
      struct sockaddr_in6 *sin1 = (struct sockaddr_in6 *) addr1;
      struct sockaddr_in6 *sin2 = (struct sockaddr_in6 *) addr2;
      return memcmp(&sin1->sin6_addr, &sin2->sin6_addr,
                    sizeof(struct in6_addr));
    }
    default:
      errno = ENOTSUP;
      return -1;
  }
}

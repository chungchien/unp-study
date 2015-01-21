#include "unp.h"

int sock_cmp_port(const struct sockaddr *addr1,
                  const struct sockaddr *addr2,
                  socklen_t addrlen)
{
  int family = addr1->sa_family;

  assert(addr1->sa_family == addr2->sa_family);
  switch (family) {
    case AF_INET: {
      const struct sockaddr_in *sin1 = (const struct sockaddr_in *) addr1;
      const struct sockaddr_in *sin2 = (const struct sockaddr_in *) addr2;
      return sin1->sin_port == sin2->sin_port ? 0 : 1;
    }
    case AF_INET6: {
      const struct sockaddr_in6 *sin1 = (const struct sockaddr_in6 *) addr1;
      const struct sockaddr_in6 *sin2 = (const struct sockaddr_in6 *) addr2;
      return sin1->sin6_port == sin2->sin6_port ? 0 : 1;
    }
    default:
      errno = ENOTSUP;
      return -1;
  }
}

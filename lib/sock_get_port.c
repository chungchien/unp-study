#include "unp.h"

int sock_get_port(const struct sockaddr *sockaddr, socklen_t addlen)
{
  switch (sockaddr->sa_family) {
    case AF_INET:
      return ntohs(((const struct sockaddr_in *) sockaddr)->sin_port);
#if defined(IPV6)
    case AF_INET6:
      return ntohs(((const struct sockaddr_in6 *) sockaddr)->sin6_port);
#endif // IPV6
    default:
      errno = EAFNOSUPPORT;
      return -1;
  }
}

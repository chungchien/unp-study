#include "unp.h"

void sock_set_port(struct sockaddr *sockaddr,
                   socklen_t addrlen, int port)
{
  assert(sockaddr);
  switch (sockaddr->sa_family) {
    case AF_INET:
      ((struct sockaddr_in *) sockaddr)->sin_port =
          htons(port);
      break;
#if defined(IPV6)
    case AF_INET6:
      ((struct sockaddr_in6 *) sockaddr)->sin6_port =
          htons(port);
      break;
#endif // IPV6
    default:
      assert(0);
      break;
  }
}

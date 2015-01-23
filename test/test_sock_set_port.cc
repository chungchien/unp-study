#include "unp.h"
#include "gtest/gtest.h"

TEST(test_sock_set_port, IPv4) {
  struct sockaddr_in addr;
  bzero(&addr, sizeof(addr));
  addr.sin_family = AF_INET;
  sock_set_port((struct sockaddr *)&addr, sizeof(addr), 1234);

  EXPECT_EQ(ntohs(addr.sin_port), 1234);
}

TEST(test_sock_set_port, IPv6) {
  struct sockaddr_in6 addr;
  bzero(&addr, sizeof(addr));
  addr.sin6_family = AF_INET6;
  sock_set_port((struct sockaddr *)&addr, sizeof(addr), 1234);

  EXPECT_EQ(ntohs(addr.sin6_port), 1234);
}

#include "unp.h"
#include "gtest/gtest.h"

TEST(test_sock_get_port, IPv4) {
  struct sockaddr_in addr;
  bzero(&addr, 0);
  addr.sin_family = AF_INET;
  addr.sin_port = htons(13);

  EXPECT_EQ(13, sock_get_port((struct sockaddr *)&addr, sizeof(addr)));
}

TEST(test_sock_get_port, IPv6) {
  struct sockaddr_in6 addr;
  bzero(&addr, 0);
  addr.sin6_family = AF_INET6;
  addr.sin6_port = htons(13);

  EXPECT_EQ(13, sock_get_port((struct sockaddr *) &addr, sizeof(addr)));
}

TEST(test_sock_get_port, InvalidProtocol) {
  struct sockaddr_un addr;
  bzero(&addr, sizeof(addr));
  addr.sun_family = AF_UNIX;
  strcpy(addr.sun_path, "foo.socket");
  int len = offsetof(struct sockaddr_un, sun_path) +
      strlen(addr.sun_path);

  EXPECT_EQ(-1, sock_get_port((struct sockaddr *) &addr, len));
  EXPECT_EQ(EAFNOSUPPORT, errno);
}











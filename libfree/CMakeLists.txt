if (NOT HAVE_INET_PTON)
  set(LIBFREE_SRCS "${LIBFREE_SRCS} inet_pton_ipv4.c")
endif (NOT HAVE_INET_PTON)
if (NOT HAVE_INET_NTOP)
  set(LIBFREE_SRCS "${LIBFREE_SRCS} inet_ntop_ipv4.c")
endif (NOT HAVE_INET_NTOP)

if (LIBFREE_SRCS)
  add_library(free ${LIBFREE_SRCS})
endif (LIBFREE_SRCS)

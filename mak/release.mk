BUILDTYPE := release
LIBSUFFIX := .a
CPPFLAGS += -DNDEBUG
CFLAGS += -O $(CPPFLAGS)

JUST_DO_SHELL := \
  $(shell (test -d $(BUILDDIR) || mkdir -p $(BUILDDIR)) &&  \
  cp $(TOPDIR)/mak/release.mk $(BUILDDIR)/latest.mk && echo "Ok")

BUILDTYPE := release
LIBSUFFIX := .a
CPPFLAGS += -DNDEBUG
CFLAGS += -O $(CPPFLAGS)

JUST_DO_SHELL := \
  $(shell cp $(TOPDIR)/mak/release.mk $(BUILDDIR)/latest.mk && echo "Ok")

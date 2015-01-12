BUILDTYPE := debug
LIBSUFFIX := d.a
CPPFLAGS += -D_DEBUG
CFLAGS += -g $(CPPFLAGS)

JUST_DO_SHELL := \
  $(shell cp $(TOPDIR)/mak/release.mk $(BUILDDIR)/latest.mk && echo "Ok")

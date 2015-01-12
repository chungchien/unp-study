BUILDTYPE := debug
CPPFLAGS += -D_DEBUG
CFLAGS += -g $(CPPFLAGS)

JUST_DO_SHELL := \
  $(shell (test -d $(BUILDDIR) || mkdir -p $(BUILDDIR)) &&  \
  cp $(TOPDIR)/mak/debug.mk $(BUILDDIR)/latest.mk && echo "Ok")

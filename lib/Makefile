include ../mak/make.settings

INCDIR := $(TOPDIR)/include
OBJDIR := $(BUILDDIR)/libapueobjs

CFLAGS += -I$(INCDIR)

TARGET := $(LIBDIR)/libunp$(LIBSUFFIX)
DIRS   := $(BUILDDIR) $(LIBDIR) $(OBJDIR)
OBJS   := error.o

VPATH = $(INCDIR):$(OBJDIR)

.PHONY: all clean dirs

all: dirs $(TARGET)

dirs:
	@for dir in $(DIRS) ; do \
	if [ -d $$dir ]; then true;\
	else mkdir -p $$dir ; echo "mkdir -p $$dir"; fi; \
	done

$(TARGET): $(OBJS)
	$(AR) -cr $@ $(OBJDIR)/*

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(OBJDIR)/$@

clean:
	-rm $(TARGET)
	-rm -rf $(OBJDIR)

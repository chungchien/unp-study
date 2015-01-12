include ../mak/make.settings

OBJDIR := $(BUILDDIR)/libapueobjs

TARGET := $(LIBDIR)/libunp$(LIBSUFFIX)
DIRS   := $(BUILDDIR) $(LIBDIR) $(OBJDIR)
SRCS   = $(OBJS:.o=.c)
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

sinclude $(SRCS:.c=.d)

.c.o:
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $(OBJDIR)/$@

clean:
	-rm $(TARGET)
	-rm -rf $(OBJDIR)

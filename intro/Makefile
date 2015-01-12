include ../mak/make.settings

OBJDIR := $(BUILDDIR)/daytimetcpcliobjs
TARGET := $(BINDIR)/daytimetcpcli
OBJS := daytimetcpcli.o
DIRS :=  $(BUILDDIR) $(OBJDIR) $(BINDIR)
VPATH := $(OBJDIR):$(INCDIR)

all: dirs $(TARGET)

dirs:
	$(MAKE) -f ../mak/common.mk dirs DIRS="$(DIRS)"

$(TARGET): $(OBJS) libunp.a
	$(CC) -o $@ $(OBJDIR)/* $(LDFLAGS)

libunp.a:
	$(MAKE) -C ../lib
.c.o:
	$(CC) $(CFLAGS) -c $< -o $(OBJDIR)/$@

clean:
	-rm -rf $(OBJDIR)
	-rm $(TARGET)

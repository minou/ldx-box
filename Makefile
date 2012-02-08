SRCDIR=src
BINDIR=bin
CFLAGS= -Wall -Werror -ansi -fPIC -D_GNU_SOURCE
EXEC=libc.so
all: $(EXEC)

$(EXEC): $(BINDIR)/alloc.o $(BINDIR)/open.o
	gcc -o $@ $^ -shared -ldl

$(BINDIR)/%.o: $(SRCDIR)/%.c
	mkdir -p bin
	gcc -o $@ -c $< $(CFLAGS)

clean:
	rm -rf $(BINDIR)

mrproper: clean
	rm $(EXEC)

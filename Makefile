SRCDIR=src
BINDIR=bin
CFLAGS= -Wall -Werror -ansi -fPIC -D_GNU_SOURCE
EXEC=libc.so
all: $(EXEC)

SRC=$(wildcard $(SRCDIR)/*.c)
OBJ=$(SRC:.c=.o)

$(EXEC): $(OBJ)
	gcc -o $@ $^ -shared -ldl

$(BINDIR)/%.o: $(SRCDIR)/%.c
	gcc -o $@ -c $< $(CFLAGS)

clean:
	rm -rf $(BINDIR)

mrproper: clean
	rm $(EXEC)

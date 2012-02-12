SRCDIR		= src

CC      	= gcc
CFLAGS		= -W -Wall -Werror -ansi
LDFLAGS		= -fPIC -Iiniparser/src -D_GNU_SOURCE
LDSHFLAGS	= -shared -Liniparser -liniparser

EXEC		= libdx.so
SRC 		= $(wildcard $(SRCDIR)/*.c)
OBJ 		= $(SRC:.c=.o)

default: all

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) -o $@ $^ $(LDSHFLAGS)

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS) $(LDFLAGS)

clean:
	@rm $(OBJ)

mrproper: clean
	@rm $(EXEC)

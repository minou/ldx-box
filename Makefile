SRCDIR		= src

CC      	= gcc
CFLAGS		= -Wall -Werror -ansi -fPIC -I../iniparser/src -D_GNU_SOURCE
LFLAGS  	= -L../iniparser -liniparser -shared -ldl -D_GNU_SOURCE
#LDSHFLAGS	= -shared -D_GNU_SOURCE

EXEC		= libtest.so

SRC = $(wildcard $(SRCDIR)/*.c)
OBJ = $(SRC:.c=.o)


default: all

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LFLAGS)

clean:
	rm $(OBJ)
	rm $(EXEC)

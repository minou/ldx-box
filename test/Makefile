CC      = gcc
CFLAGS  = -Wall -Werror -ansi -pedantic

SRC 	= $(wildcard *.c)
OBJ 	= $(SRC:.c=)

default: all

all: $(OBJ)

%: %.c
	$(CC) -o $@ $< $(CFLAGS)

clean veryclean:
	@rm $(OBJ)

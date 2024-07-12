CC=gcc
CFLAGS=$(shell pkg-config --cflags glib-2.0)
LIBS=$(shell pkg-config --libs glib-2.0)

all:
	$(CC) -g -O0 -Wall -Werror -o a.out main.c $(CFLAGS) $(LIBS)

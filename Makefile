CC = gcc
CFLAGS = -Wall -Wextra -O2

all: libdegtrig.a

libdegtrig.a: degtrig.o
	ar rcs libdegtrig.a degtrig.o

degtrig.o: degtrig.c degtrig.h
	$(CC) $(CFLAGS) -c degtrig.c

example: example.c libdegtrig.a
	$(CC) $(CFLAGS) example.c -L. -ldegtrig -lm -o example

clean:
	rm -f *.o *.a example
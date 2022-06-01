all: main clean
CC=gcc
CFLAGS=-Wall

main.o:
	$(CC) $(CFLAGS) -c src/main.c

main: main.o
	$(CC) $(CFLAGS) -o ret $^
clean:
	rm *.o
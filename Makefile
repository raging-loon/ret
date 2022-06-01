all: main clean
CC=g++
CFLAGS=-Wall

main.o:
	$(CC) $(CFLAGS) -c src/main.cpp

main: main.o
	$(CC) $(CFLAGS) -o ret $^
clean:
	rm *.o
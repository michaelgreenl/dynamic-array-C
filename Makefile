CC = gcc
CFLAGS = -Wall -Wextra -std=c11

all: main

main: main.c dynamic_array.c
	$(CC) $(CFLAGS) -o main main.c dynamic_array.c

clean:
	rm -f main

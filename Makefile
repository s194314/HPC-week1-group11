CC = gcc
CFLAGS = -g -Wall
LDFLAGS = -lm

jacobi: main.c
	$(CC) $(CFLAGS) -o jacobi main.c $(LDFLAGS)
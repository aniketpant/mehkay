CC = gcc
CFLAGS = -pedantic -Wall -g

queuetest: queuetest.o queue.o
	$(CC) $(CFLAGS) -o queuetest queuetest.o queue.o

queuetest.o: queuetest.c queue.h
	$(CC) $(CFLAGS) -c queuetest.c

queue.o: queue.c queue.h
	$(CC) $(CFLAGS) -c queue.c

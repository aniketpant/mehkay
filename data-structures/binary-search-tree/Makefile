CC = gcc
CFLAGS = -pedantic -Wall -g

bsttest: bsttest.o bst.o
	$(CC) $(CFLAGS) -o bsttest bsttest.o bst.o

bsttest.o: bsttest.c bst.h
	$(CC) $(CFLAGS) -c bsttest.c

bst.o: bst.c bst.h
	$(CC) $(CFLAGS) -c bst.c

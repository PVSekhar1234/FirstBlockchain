#makefile

CC = gcc
CFLAGS = -Wall -g
LDFLAGS = -lssl -lcrypto

all: blockchain

blockchain: main.o block.o blockchain.o
	$(CC) $(CFLAGS) -o blockchain main.o block.o blockchain.o $(LDFLAGS)

main.o: main.c block.h blockchain.h
	$(CC) $(CFLAGS) -c main.c

block.o: block.c block.h
	$(CC) $(CFLAGS) -c block.c

blockchain.o: blockchain.c blockchain.h block.h
	$(CC) $(CFLAGS) -c blockchain.c

clean:
	rm -f *.o blockchain
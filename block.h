#ifndef BLOCK_H
#define BLOCK_H

#include <time.h>

#define HASH_LENGTH 64 // Length of SHA-256 hash in hexadecimal

typedef struct
{
    int index;
    char previousHash[HASH_LENGTH + 1];
    char data[256];
    time_t timestamp;
    char hash[HASH_LENGTH + 1];
} Block;

Block createBlock(int index, const char *previousHash, const char *data, time_t timestamp);
char *calculateHash(const Block *block);

#endif // BLOCK_H
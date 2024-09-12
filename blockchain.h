#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#include "block.h"
#define MAX_BLOCKS 1000

typedef struct
{
    Block chain[MAX_BLOCKS];
    int size;
} Blockchain;

Blockchain createBlockchain();
void addBlock(Blockchain *blockchain, const char *data);
void printBlockchain(const Blockchain *blockchain);

#endif // BLOCKCHAIN_H
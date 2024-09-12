#include "blockchain.h"
#include <stdio.h>
#include <string.h>

Blockchain createBlockchain()
{
    Blockchain blockchain;
    blockchain.size = 0;
    blockchain.chain[0] = createBlock(0, "0", "Genesis Block", time(NULL));
    blockchain.size = 1;
    return blockchain;
}

void addBlock(Blockchain *blockchain, const char *data)
{
    if (blockchain->size >= MAX_BLOCKS)
    {
        printf("Blockchain is full!\n");
        return;
    }
    Block previousBlock = blockchain->chain[blockchain->size - 1];
    Block newBlock = createBlock(blockchain->size, previousBlock.hash, data,
                                 time(NULL));
    blockchain->chain[blockchain->size] = newBlock;
    blockchain->size++;
}

void printBlockchain(const Blockchain *blockchain)
{
    for (int i = 0; i < blockchain->size; ++i)
    {
        const Block *block = &blockchain->chain[i];
        printf("Block #%d\n", block->index);
        printf("Previous Hash: %s\n", block->previousHash);
        printf("Data: %s\n", block->data);
        printf("Timestamp: %ld\n", block->timestamp);
        printf("Hash: %s\n\n", block->hash);
    }
}
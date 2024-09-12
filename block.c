#include "block.h"
#include <stdio.h>
#include <string.h>
#include <openssl/sha.h>

// Helper function to convert bytes to a hexadecimal string
void bytesToHex(const unsigned char *bytes, char *hex, size_t length)
{
    for (size_t i = 0; i < length; ++i)
    {
        sprintf(hex + (i * 2), "%02x", bytes[i]);
    }
    hex[length * 2] = '\0'; // Null-terminate the string
}

char *calculateHash(const Block *block)
{
    static char hash[HASH_LENGTH + 1];
    unsigned char digest[SHA256_DIGEST_LENGTH];
    char input[512];
    // Create the input string for hashing
    sprintf(input, "%d%s%s%ld", block->index, block->previousHash, block->data, block->timestamp);
    // Compute SHA-256 hash
    SHA256((unsigned char *)input, strlen(input), digest);
    // Convert hash to hexadecimal string
    bytesToHex(digest, hash, SHA256_DIGEST_LENGTH);
    return hash;
}

Block createBlock(int index, const char *previousHash, const char *data, time_t timestamp)
{
    Block block;
    block.index = index;
    strncpy(block.previousHash, previousHash, HASH_LENGTH);
    strncpy(block.data, data, sizeof(block.data) - 1);
    block.timestamp = timestamp;
    strncpy(block.hash, calculateHash(&block), HASH_LENGTH);
    return block;
}
#include <stdio.h>
#include "blockchain.h"

int main() {
    Blockchain blockchain = createBlockchain();
    printf("Creating the blockchain...\n");
    addBlock(&blockchain, "First block after genesis");
    addBlock(&blockchain, "Second block after genesis");
    printf("Blockchain created with %d blocks:\n",
    blockchain.size);
    printBlockchain(&blockchain);
    return 0;
}
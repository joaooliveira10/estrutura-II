#include "Blockchain.h"
#include <stdlib.h>
#include <stdio.h>

// Dupla : Victor e Thays

void ExInfo(Block* block)
{
    printf("\n [bloco %u] \n", block->index);
    printf("Timestamp: %lu\n", block->timestamp);
    printf("Data: %f\n", block->data);
    printf("Hash: %.20s...\n", block->hash);
    printf(" \n ");
}

int main() {
    Blockchain blockchain;
    initBlockchain(&blockchain);

    Block* bloco1;

    printf("%s\n", blockchain.genesisBlock->hash);
    printf("%lu\n", blockchain.genesisBlock->timestamp);
    printf("\n");

    Block* newBlock1 = generateNextBlock(&blockchain, 50.0);
    addBlock(&blockchain, newBlock1);

    printf("Block 1 is valido? %d\n", isValidNewBlock(newBlock1, blockchain.genesisBlock));

    Block* newBlock2 = generateNextBlock(&blockchain, 180.0);
    addBlock(&blockchain, newBlock2);

    printf("Block 2 is valido? %d\n", isValidNewBlock(newBlock2, blockchain.genesisBlock));

    Block* newBlock3 = generateNextBlock(&blockchain, 150.0);
    addBlock(&blockchain, newBlock3);

    printf("Block 3 is valido? %d\n", isValidNewBlock(newBlock3, blockchain.genesisBlock));

    printf(" \n Antes de  Alterado o Valor do bloco 3 \n");

    printf("\n- Blockchain é valida?\n  resposta: %d\n", isBlockchainValid(&blockchain));

    printf(" \n Depois de  Alterado o Valor do bloco 3 \n");
    newBlock3->data = 170.0;

    printf("\n- Blockchain é valida?\n  resposta: %d\n", isBlockchainValid(&blockchain));


    Block* block = getLatestBlock(&blockchain);
    while (block != blockchain.genesisBlock)
    {
        ExInfo(block);
        block = block->previousBlock;
    }

    return 0;
}
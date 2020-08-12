#include "blockchain.h"
#include <stdio.h>
#include <stdlib.h>

// CRISTIAN E RUBIA
const char* boolalpha(bool condition)
{
    return condition ? "true" : "false";
}

void ExibirInfo(Block* block)
{
    printf("+----------[Bloco %u]----------+\n", block->index);
    printf("Timestamp: %lu\n", block->timestamp);
    printf("Data: %f\n", block->data);
    printf("Hash: %.20s...\n", block->hash);
    
   printf("+-----------------------------+\n");    
}

int main()
{
    Blockchain blockchain;
    initBlockchain(&blockchain);

    Block *newBlock1 = generateNextBlock(&blockchain, 10.0);
    addBlock(&blockchain, newBlock1);
    printf("Block 1 is valid? %d\n",isValidNewBlock(newBlock1, blockchain.genesisBlock));
    //aqui ele faz a adiçao do block normalmente
    Block *newBlock2 = generateNextBlock(&blockchain, 20.0);
    addBlock(&blockchain, newBlock2);
    printf("Block 2 is valid? %d\n",isValidNewBlock(newBlock2, blockchain.genesisBlock));
    //quando é adicionado newblock ele não valida a blockchain
    //newBlock2->data = 74.00;

    Block *newBlock3 = generateNextBlock(&blockchain, 30.0);
    addBlock(&blockchain, newBlock3);
    printf("Block 3 is valid? %i\n",isValidNewBlock(newBlock3, blockchain.genesisBlock));

    Block *newBlock4 = generateNextBlock(&blockchain, 40.0);
    addBlock(&blockchain, newBlock4);
    printf("Block 4 is valid? %i\n",isValidNewBlock(newBlock4, blockchain.genesisBlock));

    Block *newBlock5 = generateNextBlock(&blockchain, 50.0);
    addBlock(&blockchain, newBlock5);
    printf("Block 5 is valid? %i\n",isValidNewBlock(newBlock5, blockchain.genesisBlock));

    printf("Blockchain é valida? %i\n",isBlockchainValid(&blockchain));
    printf("tamanho: %u\n",blockchain.latestBlock->index);

    Block *block = getLatestBlock(&blockchain)
    ;
    
    while (block != blockchain.genesisBlock)
    {   
      //chama a função exibir para mostrar os valores de cada bloco.
        ExibirInfo(block);
        block = block->previousBlock;
        
    }
    
    
     
}
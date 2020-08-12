// grupo 06 Caroline int addBlock

#include "Blockchain.h"

int main() {
    Blockchain blockchain;
    printf("");
    initBlockchain(&blockchain);
    printf("%s\n",blockchain.genesisBlock->hash);
    printf("%lu\n",blockchain.genesisBlock->timestamp);
    
    Block *newBlock2 = generateNextBlock(&blockchain,10.0);
    addBlock(&blockchain, newBlock2);
    printf("Block 2 is valid? %i\n",isValidNewBlock(newBlock2, blockchain.genesisBlock));

    Block *newBlock3 = generateNextBlock(&blockchain,210.0);
    addBlock(&blockchain, newBlock3);
    printf("Block 3 is valid? %i\n",isValidNewBlock(newBlock3, blockchain.genesisBlock));


    Block *newBlock4 = generateNextBlock(&blockchain, 180.0);
    addBlock(&blockchain, newBlock4);
    printf("Block 4 is valid? %i\n",isValidNewBlock(newBlock4, blockchain.genesisBlock));

    Block *newBlock5 = generateNextBlock(&blockchain, 178.0);
    addBlock(&blockchain, newBlock5);
    printf("Block 5 is valid? %i\n",isValidNewBlock(newBlock5, blockchain.genesisBlock));

    printf("Blockchain is valid? %i\n",isBlockchainValid(&blockchain));
    printf("size: %u\n",blockchain.latestBlock->index);

    
    Block *block = getLatestBlock(&blockchain);
    
    while (block != blockchain.genesisBlock)
    {   
        ExibirInfo(block);
        block = block->previousBlock;
        
    }
    return 0;
}
#ifndef Blockchain_h
#define Blockchain_h

#include <stdlib.h>
#include <stdio.h>

enum boolean {
    true = 1, false = 0
};

typedef enum boolean bool;

typedef struct Block {
    unsigned int index;
    char* previousHash;
    struct Block* previousBlock;
    unsigned long timestamp;
    float data;
    char* hash;
}Block;

typedef struct Blockchain {
    Block *genesisBlock;
    Block *latestBlock;
}Blockchain;

void initBlockchain(Blockchain *blockchain);
char* calculateHash(int index, char* previousHash, unsigned long timestamp, float data);
Block* generateNextBlock(Blockchain *blockchain, float data);
Block* getLatestBlock(Blockchain *blockchain);
bool isValidNewBlock(Block* newBlock, Block* previousBlock);
bool isBlockchainValid(Blockchain *blockchain);
int addBlock(Blockchain *blockchain, Block *newBlock);

#endif
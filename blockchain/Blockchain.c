#include "sha-256.h"
#include "Blockchain.h"
#include <string.h>
#include <time.h>

void initBlockchain(Blockchain *blockchain) {
    Block *genesisBlock = (Block*)malloc(sizeof(Block));
    genesisBlock->index = 0;
    genesisBlock->previousHash = "0";
    genesisBlock->previousBlock = NULL;
    genesisBlock->timestamp = time(NULL);
    genesisBlock->data = 1000000;
    
    genesisBlock->hash = calculateHash(genesisBlock->index, genesisBlock->previousHash, genesisBlock->timestamp, genesisBlock->data);

    blockchain->genesisBlock = genesisBlock;
    blockchain->latestBlock = genesisBlock;
}

static void hash_to_string(char string[65], const uint8_t hash[32])
{
    size_t i;
    for (i = 0; i < 32; i++) {
        //montar uma string com 64 caracteres hexadecimais
        string += sprintf(string, "%02x", hash[i]); //02x hexadecimal em 2 caracteres
    }
}

char* calculateHash(int index, char* previousHash, unsigned long timestamp, float data) {
    char input[1024];
    sprintf(input, "%i%s%lu%.8f",index,previousHash, timestamp, data);
    //vetor de 32 bytes de inteiros unsigned [0-255] (256/8 = 32)
    uint8_t hash[32];
    //char hash_string[65];
    char *hash_string = (char*)malloc(sizeof(char)*65);
    calc_sha_256(hash, input, strlen(input));
    hash_to_string(hash_string, hash);

    return hash_string;
}

char* calculateBlockHash(Block *block) {
    return calculateHash(block->index, block->previousHash, block->timestamp, block->data);
}

// Dupla 02 - André e Danubia
Block* generateNextBlock(Blockchain *blockchain, float data) {
    Block *previousBlock = getLatestBlock(blockchain);
    Block *newBlock = (Block*)malloc(sizeof(Block));
    
    newBlock->data = data;
    newBlock->previousHash = previousBlock->hash;
    newBlock->index = previousBlock->index+1;
    newBlock->timestamp = time(NULL);
    newBlock->hash = calculateBlockHash(newBlock);
    
    return newBlock;
}

Block* getLatestBlock(Blockchain *blockchain) {
    return blockchain->latestBlock;
}

bool isValidNewBlock(Block* newBlock, Block* previousBlock) {
    if (previousBlock->index + 1 != newBlock->index) {
        return false;
    } else if (previousBlock->hash != newBlock->previousHash) {
        return false;
    } else if (strcmp(calculateBlockHash(newBlock),newBlock->hash)!=0) {
        return false;
    }
    return true;
}

bool isBlockchainValid(Blockchain *blockchain) {
    Block *aux = getLatestBlock(blockchain);
    while (aux!=blockchain->genesisBlock) {
        if (!isValidNewBlock(aux, aux->previousBlock))
            return false;
        aux = aux->previousBlock;
    }
    return true;
}

int addBlock(Blockchain *blockchain, Block *newBlock) {
    if (isValidNewBlock(newBlock, getLatestBlock(blockchain))) {
        newBlock->previousBlock = getLatestBlock(blockchain);
        blockchain->latestBlock = newBlock;
        return 1;
    }
    return -1;
}
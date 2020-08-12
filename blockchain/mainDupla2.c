/* 
    * Implementação da estrutura de dados Blockchain
    * Grupos responsavel: André Geraldo e Danubia Macedo
    * Prof. Dr. João Paulo  D. Preti
    * agosto de 2020.

*/ 

#include "Blockchain.h"
int main(){
    Blockchain blockchain;
    initBlockchain(&blockchain);

    Block *bloco0;
  
    bloco0 = generateNextBlock(&blockchain, 233);

    if(isValidNewBlock(bloco0, blockchain.genesisBlock) == true ){
        
        printf("Bloco valido e adicionado: %i \n",addBlock(&blockchain, bloco0));
    } else { 
           printf("Bloco invalido\n");
    };

   Block *bloco1;
  
   bloco1 = generateNextBlock(&blockchain,43);
   addBlock(&blockchain, bloco1);

   printf("Blockchain valida? %d \n",isBlockchainValid(&blockchain));

   bloco0->data = 253;

   printf("Blockchain valida? %d \n",isBlockchainValid(&blockchain));

   printf("\n-----------Testes Adicionais---------\n");
   printf(" ");
   Blockchain blockchain2;
   initBlockchain(&blockchain2);

   printf("GenesisBlock Hash:%s\n",blockchain2.genesisBlock->hash);
   printf("GenesisBlock timestamp:%lu\n",blockchain2.genesisBlock->timestamp);


   Block *newBlockAndre = generateNextBlock(&blockchain2,55.0);
   addBlock(&blockchain2,newBlockAndre);

   Block * newBlockDanubia = generateNextBlock(&blockchain2,399.99);
   addBlock(&blockchain2,newBlockDanubia);

   printf("Bloco do andré válido ? %i\n", isValidNewBlock(newBlockAndre,blockchain2.genesisBlock));
   printf("\nAntes da alteração - Cadeia de blocos é válida ?%i\n" ,isBlockchainValid(&blockchain2));
   newBlockAndre->data = 444.6;
   printf("\nDepois da alteração - Cadeia de blocos é válida ?%i\n" ,isBlockchainValid(&blockchain2));
   printf("Size da lista: %u\n", blockchain2.latestBlock->index);

   return 0;
}
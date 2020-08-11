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

}
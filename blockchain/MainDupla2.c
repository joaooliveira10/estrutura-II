#include "Blockchain.c"
#include "locale.h"

/*Dupla 2: Bruno ferreira e Herique sena*/
int main() {

    setlocale(LC_ALL,"portuguese");
    Blockchain blockchain;
    initBlockchain(&blockchain);

    printf("%s\n",blockchain.genesisBlock->hash);
    printf("%lu\n",blockchain.genesisBlock->timestamp);

    float valor;
    int i = 1;
    do{
        printf("\n\n digite um valor para o bloco ou digite 0 para sair :");
        scanf("%f", &valor);
        if(valor != 0){
           Block *newBlock = generateNextBlock(&blockchain,valor);
           addBlock(&blockchain, newBlock);
           printf("\n Inserido o valor (%2.f) no bloco %d",valor, i);
           i++;
        }

    } while(valor != 0);

    Block *aux = blockchain.latestBlock;
    printf("\n\n O valor do ultimo nó (%d) é: %2.f",i-1,aux->data);
    printf("\n\n O valor do primeiro nó (%d) é: %2.f",i-i,blockchain.genesisBlock->data);

    printf("\n");

    while(aux != blockchain.genesisBlock){
        printf("\n- Block %d com valor %2.f é valido?\n  resposta: %i\n",i-1,aux->data,isValidNewBlock(aux, aux->previousBlock));
        aux = aux->previousBlock;
        i--;
    }

    printf( "\n- Blockchain é valida?\n  resposta: %i\n",isBlockchainValid(&blockchain));

    printf("\nsize: %u\n",blockchain.latestBlock->index);
    return EXIT_SUCCESS;
}

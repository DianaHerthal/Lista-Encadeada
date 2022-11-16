#include <stdlib.h>
#include <stdio.h>
#include "lista.h"


int main() {
    int op = 1;
    while (op==1){
	Lista l;
	iniciar_lista(&l);

    for(int i=0; i<10; i++)
        inserir_lista_ord(&l, i);
    imprimir_lista(&l);

	int chave_busca=4;
	No *pre = NULL;
	buscar_lista(&l, chave_busca, &pre);

	printf("Valor buscado %d\n", chave_busca);
    printf("PRED: %d\n", pre->chave);
    printf("PRED->proximo: %d\n", (pre->prox)->chave);


    remover_kesimo_elemento_lista(&l, 2);
    imprimir_lista(&l);

    destruir_lista(&l);
    scanf("%d", &op);
    }
	return 0;
}




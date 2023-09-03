#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "lista.h"

void main()
{
    // iniciar_lista(&l);
    int valor;
    int opcao = 1;

    while (opcao != 0)
    {
        Lista l;
        iniciar_lista(&l);
        printf("Digite o numero da funcao desejada:\n");
        printf("1 - Carregar dados.\n");
        printf("2 - Cadastrar dados.\n");
        printf("3 - Buscar dado.\n");
        printf("4 - Salvar dados.\n");
        printf("5 - Deletar dados.\n");
        printf("6 - Imprimir todos os dados.\n");
        printf("7 - Sair do programa.\n");

        fflush(stdin);

        scanf("%d", &opcao);

        if(opcao == 1)
        {
            retornar_livros(&l, 0, "livros.txt", "lista.txt");
        }
        
        else if(opcao == 2)
        {
            int op_sec;
            printf("Escolha a posicao onde deseja cadastrar:\n1 - Inicio.\n2 - Meio.\n3 - Fim.\n");
            scanf("%d", &op_sec);

            if(op_sec == 1)
            {
                int result = insercao_inicio_lista(&l);
                if (result == 1){
                    printf("Cadastrado com sucesso\n");
                }
                else{
                    printf("Error");
                }

            }
            else if(op_sec == 2)
            {
                No* novo;
                int result = insercao_meio_lista(&l, novo);
                if (result == 1){
                    printf("Cadastrado com sucesso\n");
                }
                else{
                    printf("Error");
                }
            }
            else if(op_sec == 3)
            {
                
                No* novo;
                int result = insercao_meio_lista(&l, novo);
                if (result == 1){
                    printf("Cadastrado com sucesso\n");
                }
                else{
                    printf("Error");
                }
            }
        }

        else if(opcao == 3)
        {
            buscar_livro_lista(&l);
        }
        else if(opcao == 4)
        {
            salvar_livros(&l, "livros.txt", "lista.txt");
            printf("Todos os livros foram salvos para uma proxima consulta!");
        }
        else if (opcao == 5)
        { 
            remover_lista(&l);
        }
        else if (opcao == 6)
        {
            printf("Livros:\n\n");
            imprimir_lista(&l);
        }
        else if (opcao == 7)
        {
            printf("Tchau\n");
            opcao = 0;
        }
        else
        {
            printf("Funcao invalida\n");
        }
    }
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "lista.h"


void iniciar_lista(Lista *p_l){
	// para iniciar uma lista encadeada basta fazer o inicio apontar para NULL (nada)
	p_l->inicio=NULL;
	p_l->final=NULL;
	p_l->tamanho_lista=0;
}

// inserir elemento no inicio da lista
int insercao_inicio_lista(Lista *p_l){
	// aloca o novo no a ser iserido
	No *novo = malloc(sizeof(No));

	// verifica se a alocacao deu certo
	if (novo==NULL) //falta de memória
		printf("Error: Memoria insuficiente");
		return 0;

	// escaneia e copia os valores para o novo no
	printf("Digite nome do livro\n");
    scanf(" %[^\n]", novo->nome_livro);
    printf("Digite o nome do autor do livro\n");
    scanf(" %[^\n]", novo->nome_autor);
	printf("Digite o nome da editora\n");
    scanf(" %[^\n]", novo->editora);

    	
	// caso não haja nenhum elemento ainda ele aponta o final como o novo elemento
	if (p_l == NULL){
		p_l->final = novo;
	}
	else{
		// faz o proximo do novo no apontar para o inicio
		novo->prox = p_l->inicio;
	}
	// faz o inicio apontar para o novo
	p_l->inicio = novo;
	p_l->tamanho_lista++;



	return 1;
}


// inseririr novo elemento no meio da lista
int insercao_meio_lista(Lista *p_l, No *p){
	// aloca o novo no a ser inserido
	No *novo = (No*) malloc(sizeof(No));
	
	// verifica se a alocacao deu certo
	if (novo==NULL) //falta de memória
		printf("Error: Memoria insuficiente");
		return 0;

	// escaneia e copia os valores para o novo no
	printf("Digite nome do livro\n");
    scanf(" %[^\n]", novo->nome_livro);
    printf("Digite o nome do autor do livro\n");
    scanf(" %[^\n]", novo->nome_autor);
	printf("Digite o nome da editora\n");
    scanf(" %[^\n]", novo->editora);

	novo->prox = p->prox;
	p->prox = novo;
	p_l->tamanho_lista++;

	return 1;
}

// realiza uma busca sequencial na lista (busca binaria so pode ser usada em listas ordenadas)
No* buscar_lista(Lista *p_l, No** pred){
	// ponteiro para o predecessor
	*pred = NULL;
	
	// poteiro para o no corrente
	No* corrente = p_l->inicio;
    
	char procura[300];
	int contador = 0;
    
	printf("Digite o nome do livro:\n");
    scanf(" %[^\n]", procura);

    while((corrente != NULL) && (contador< p_l->tamanho_lista))
    {
        if (strcmp(procura, corrente->nome_livro) == 0)
        {
			// se achou o elemento retorna o ponteiro para sua posicao
            return corrente;
        }
		else{
			*pred = corrente;
			corrente = corrente->prox;
			contador++;
		}
    }

    printf("Livro nao esta cadastrado\n");
	// se não achou o elemento retorna NULL
    return NULL;
}


// remove o elemento do inicio da lista
int remover_inicio_lista(Lista *p_l){
	// verifica se a lista esta vazia
	if(p_l == NULL) {
		printf("A lista está vazia");
		return 0;
	}

	// se a lista nao esta vazia entao da para remover o elemento do inciio
	No* temp = p_l->inicio;
	p_l->inicio = temp->prox;
	free(temp);
	printf("Livro deletado com sucesso");
	return 1;
}

// remove um elemnto do meio da lista
int remover_meio_lista(No* pred){

	// verifica se alista esta vazia
	if(pred == NULL) {
		printf("A lista está vazia");
		return 0; // se estiver nao ha nada a ser removido
	}

	// cria um ponteiro temp servir como ancora e nao perder o link do no
	No* temp = pred->prox;
	if(temp == NULL) // se temp for nulo que dizer que estamos no final da lista
        pred->prox = NULL; // entao proximo do ultimo tem que ser null
    else
        pred->prox= temp->prox; // como nao é o ultimo entao proxi tem que ser temp-prox
	free(temp);
	return 1;
}

// remove um elemnto especifico da lista
int remover_lista(Lista *p_l){
	No *q;
	No *pred=NULL;

	// procura pelo elemento a ser removido
	q = buscar_lista(p_l, &pred);

	if (q==NULL) // elemento não existe na lista
		printf("Elemento não existe na lista");
		return 0;

	if (pred==NULL) // remover no inicio da lista
		return remover_inicio_lista(p_l);
	else
		// remover no meio da lista
		return remover_meio_lista(pred);
}

// imrime o conteudo armazenado na lista
void imprimir_lista(Lista *p_l){
	No* temp = p_l->inicio;
	while(temp!=NULL){
		printf("%s", temp->nome_livro);
		printf("%s", temp->nome_autor);
		printf("%s", temp->editora);
		printf("\n");
		temp=temp->prox; //aponta para o próximo nó
	}
	
}


// remove todos os elementos da lista
void destruir_lista(Lista *p_l){
	char resposta[3];
	printf("Tem certeza de que quer deletar a lista?\n");
	gets(resposta);
	for (int i = 0; resposta[i]!='\0'; i++) {
      if(resposta[i] >= 'a' && resposta[i] <= 'z') {
         resposta[i] = resposta[i] -32;
      }
   }
	if(resposta == "SIM")
	{
		printf("Voce realmente tem certeza disso,\nUma vez feito nao tem volta.\n");
	}
	gets(resposta);
	for (int i = 0; resposta[i]!='\0'; i++) {
      if(resposta[i] >= 'a' && resposta[i] <= 'z') {
         resposta[i] = resposta[i] -32;
      }
   	}
	if (resposta == "SIM"){
		No* temp = p_l->inicio;
		while(temp!=NULL){
			No* prox = temp->prox;
			free(temp);
			temp=prox;
			printf("voce deletou tudo\n");

		p_l->inicio=NULL;
	}
	}
	else{
		printf("Ufa! \\(^-^)/\nVoce quase deletou todos os dados.\n");
	}
}

// realiza uma busca sequencial na lista (busca binaria so pode ser usada em listas ordenadas)
No* buscar_livro_lista(Lista *p_l){
	
	// poteiro para o no corrente
	No* corrente = p_l->inicio;
    
	char procura[300];
	int contador = 0;
    
	printf("Digite o nome do livro:\n");
    scanf(" %[^\n]", procura);

    while((corrente != NULL) && (contador< p_l->tamanho_lista))
    {
        if (strcmp(procura, corrente->nome_livro) == 0)
        {
			// se achou o elemento printa as informações
			printf("%s", corrente->nome_livro);
			printf("%s", corrente->nome_autor);
			printf("%s", corrente->editora);
			// e retorna o ponteiro para sua posicao
            return corrente;
        }
		else{
			corrente = corrente->prox;
			contador++;
		}
    }

    printf("Livro nao esta cadastrado\n");
}

//Retornar clientes do arquivo para a memoria
void retornar_livros(Lista *p_l, int *i, char *filename, char *filename2)
{
	No **vetor_livros;
    FILE *arq = fopen(filename, "r");

    if (arq == NULL)
    {
        printf("ERROR: COULDNT OPEN FILE\n");
        return;
    }

	FILE *arq2 = fopen(filename2, "r");

    if (arq2 == NULL)
    {
        printf("ERROR: COULDNT OPEN FILE\n");
        return;
    }

    fread(i, sizeof(int), 1, arq);

    fread(p_l, sizeof(Lista), 1, arq2);


    if ((*i) != (p_l->tamanho_lista)) //Realoca array do tamanho certo
    {
        *vetor_livros = (No *)realloc(*vetor_livros, (p_l->tamanho_lista) * sizeof(No));
    }

	fread(*vetor_livros, sizeof(No), *i, arq);



	
    printf("\n\nRetornando %d livros para memoria\n\n", *i);

    fclose(arq);


    printf("Livros Retornados para Memoria com Sucesso!\n\n");
}

void salvar_livros(Lista *p_l, char *resultfilename, char *resultfilename2)
{
	No **vetor_livros;
    FILE *arq = fopen(resultfilename, "w");

    if (arq == NULL)
    {
        printf("ERROR: COULDNT OPEN FILE\n");
        return;
    }

	FILE *arq2 = fopen(resultfilename2, "w");

	if (arq == NULL)
    {
        printf("ERROR: COULDNT OPEN FILE\n");
        return;
    }

    fwrite(vetor_livros, sizeof(No), p_l->tamanho_lista, arq);

	fwrite(p_l, sizeof(No)+sizeof(No)+sizeof(int), 1, arq2);

    fclose(arq);

	fclose(arq2);

    printf("Arquivo Salvo com Sucesso!\n\n");
}
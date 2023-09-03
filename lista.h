#ifndef LISTA_H
#define LISTA_H

typedef struct No{
	// int chave;
	char nome_livro[300];
	char nome_autor[150];
	char editora[150];
	struct No *prox;
} No;

typedef struct {
	No *inicio;
	No *final;
	int tamanho_lista;
} Lista;

void iniciar_lista(Lista *p_l);
int insercao_inicio_lista(Lista *p_l);
int insercao_meio_lista(Lista *p_l, No *p);
No* buscar_lista(Lista *p_l, No** pred);
int remover_inicio_lista(Lista *p_l);
int remover_meio_lista(No* pred);
int remover_lista(Lista *p_l);
void imprimir_lista(Lista *p_l);
void destruir_lista(Lista *p_l);
No* buscar_livro_lista(Lista *p_l);
void retornar_livros(Lista *p_l, int *i, char *filename, char *filename2);
void salvar_livros (Lista *p_l, char *resultfilename, char *resultfilename2);

#endif 
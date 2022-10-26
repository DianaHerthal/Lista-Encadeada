typedef struct No{
	int chave;
	struct No *prox;
} No;

typedef struct {
	No *inicio;
} Lista;

void iniciar_lista(Lista *p_l);
int insercao_inicio_lista(Lista *p_l, int valor);
int insercao_meio_lista(No *p, int valor);
No* buscar_lista(Lista *p_l, int ch_busca, No** pred);
int inserir_lista_ord(Lista *p_l, int valor);
int remover_inicio_lista(Lista *p_l);
int remover_meio_lista(No* pred);
int remover_lista(Lista *p_l, int chave_usu);
void imprimir_lista(Lista *p_l);
void destruir_lista(Lista *p_l);
int remover_kesimo_elemento_lista(Lista *p_l, int k);


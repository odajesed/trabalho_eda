#include "bloco.h"

typedef struct arvore_b
{
    int n_bloco, folha;
    struct arvore_b **filho;
    struct arquivo_data **super_bloco;
}arv_b;

arv_b *arv_b_criar(int t);
arv_b *arv_b_free(arv_b *a);
arv_b *arv_b_inicializa();
arv_b *arv_b_insere(arv_b *a, ar_data *bloco, int t);
arv_b	*arv_b_divisao(arv_b *x, int i, arv_b *y, int t);
arv_b	*arv_b_insere_nao_completo(arv_b *T, ar_data *bloco, int t);

void arv_b_imprec(arv_b *a, int t);
void arv_b_imprimir(arv_b *a);

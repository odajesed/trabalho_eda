#include "../headers/b_tree.h" 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

arv_b *arv_b_inicializa()
{
    return NULL;
}

arv_b *arv_b_criar(int t)
{
    arv_b *novo =(arv_b *) malloc(sizeof(arv_b));
    novo->n_bloco = 0;
    novo->folha = 1;
    novo->super_bloco = (ar_data **) malloc(sizeof(ar_data **)*((t*2)-1));
    novo->filho = (arv_b**)malloc(sizeof(arv_b*)*t*2);

    int i;
    for(i = 0; i < (t*2); i++) novo->filho[i] = NULL;

    return novo;
}   

arv_b *arv_b_free(arv_b *a)
{
  if(a){
    if(!a->folha){
      int i;
      for(i = 0; i <= a->n_bloco; i++) arv_b_free(a->filho[i]);
    }
    free(a->super_bloco);
    free(a->filho);
    free(a);
    return NULL;
  }
}

arv_b	*arv_b_divisao(arv_b *x, int i, arv_b *y, int t)
{
	int		j;
	arv_b	*z;

	z = arv_b_criar(t);
	z->n_bloco = t - 1;
	z->folha = y->folha;
	j = 0;
	while (j < (t - 1))
	{
		z->super_bloco[j] = y->super_bloco[(j + t)];
		j++;
	}
	if (!y->folha)
	{
		j = 0;
		while (j < t)
		{
			z->filho[j] = y->filho[(j + t)];
			y->filho[(j + t)] = NULL;
			j++;
		}
	}
	y->n_bloco = t - 1;
	j = x->n_bloco;
	while (j >= i)
	{
		x->filho[(j + 1)] = x->filho[j];
		j--;
	}
	x->filho[i] = z;
	j = x->n_bloco;
	while (j >= i)
	{
		x->super_bloco[j] = x->super_bloco[(j - 1)];
		j--;
	}
	x->super_bloco[(i - 1)] = y->super_bloco[(t - 1)];
	x->n_bloco++;
	return (x);
}

arv_b	*arv_b_insere_nao_completo(arv_b *T, ar_data *bloco, int t)
{
	int	i;

	i = T->n_bloco - 1;
	if (T->folha)
	{
		while ((i >= 0) && (bloco->id < (T->super_bloco[i])->id))
		{
			T->super_bloco[(i + 1)] = T->super_bloco[i];
			--i;
		}
		T->super_bloco[i + 1] = bloco;
		T->n_bloco++;
		return (T);
	}
	while ((i >= 0) && (bloco->id < (T->super_bloco[i])->id))
		i--;
	i++;
	if (T->filho[i]->n_bloco == ((2 * t) - 1))
	{
		T = arv_b_divisao(T, (i + 1), T->filho[i], t);
		if (bloco->id > (T->super_bloco[i])->id)
			i++;
	}
	T->filho[i] = arv_b_insere_nao_completo(T->filho[i], bloco, t);
	return (T);
}

arv_b *arv_b_insere(arv_b *a, ar_data *bloco, int t)
{
  //if(arv_b_busca(T,k)) return T;
  if(!a){
    a=arv_b_criar(t);
    a->super_bloco[0] = bloco;
    a->n_bloco=1;
    return a;
  }
  if(a->n_bloco == (2*t)-1){
    arv_b *S = arv_b_criar(t);
    S->n_bloco=0;
    S->folha = 0;
    S->filho[0] = a;
    S = arv_b_divisao(S,1,a,t);
    S = arv_b_insere_nao_completo(S,bloco,t);
    return S;
  }
  a = arv_b_insere_nao_completo(a,bloco,t);
  return a;
}

void arv_b_imprec(arv_b *a, int t){
  if(a){
    int i,j;
    for(i=0; i<=a->n_bloco-1; i++){
      arv_b_imprec(a->filho[i],t+1);
      for(j=0; j<=t; j++) printf("\t");
      printf("(%d->%s)\n",a->super_bloco[i]->id,(a->super_bloco[i])->texto);
    }
    arv_b_imprec(a->filho[i],t+1);
  }
}


void arv_b_imprimir(arv_b *a){
  arv_b_imprec(a, 0);
}

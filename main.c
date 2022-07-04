#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "headers/in_table.h"
#include "headers/bloco.h"
#include "headers/b_tree.h"

#define t 2
#define BUFF_SIZE 25
char * readLine(in_tabela **start);
int main(int argc,char *argv[])
{
    
    in_tabela	*start;

	start =	NULL;

    int i = 1;
    while(argv[i])
    {
        in_t_adicionar(&start, in_t_novo(i, argv[i]));
        i++;
    }
	in_t_imprimir(&start);
	printf("\n\n");

    arv_b *tree = arv_b_inicializa();
    ar_data *bloco;
    char *input;
    

    while(start)
    {
        strcpy(input,readLine(&start));       
        //COMO ASSIM?
        bloco = ar_data_novo(start->id, -1, &input);        
        tree = arv_b_insere(tree, bloco, t);
        start = start->prox;
        //nesse estado ele   ta printando o texto do ultimo cara
    }
    printf("\n\n");
    arv_b_imprimir(tree);

	in_t_free(&start);
/*
    char *a,*b,*c,*d;
    ar_data *bloco1,*bloco2,*bloco3,*bloco4;
    arv_b *tree = arv_b_inicializa();

    a = strdup("AAAA");
    b = strdup("BBBB");
    c = strdup("CCCC");
    d = strdup("DDDD");

    bloco1 = ar_data_novo(1, -1, &a);
    bloco2 = ar_data_novo(2, -1, &b);
    bloco3 = ar_data_novo(3, -1, &c);
    bloco4 = ar_data_novo(4, -1, &d);

    tree = arv_b_insere(tree, bloco1, t);
    tree = arv_b_insere(tree, bloco2, t);
    tree = arv_b_insere(tree, bloco3, t);
    tree = arv_b_insere(tree, bloco4, t);

    arv_b_imprimir(tree);
    */
    return 0;
}

char *readLine(in_tabela **start)
{
    in_tabela	*p;
	p = (*start);
    char * input = malloc(sizeof(char)*BUFF_SIZE);
    FILE *f = fopen(p->filename, "r");
    fgets(input, BUFF_SIZE, f); 
    fclose(f);
    return input;
}
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
    char input[BUFF_SIZE];
    
    // ELE SO PEGA UM POR ARQUIVO E N UTILIZA DO PROXID
    while(start)
    {
        strcpy(input,readLine(&start));       
        bloco = ar_data_novo(start->id, -1, strdup(input));        
        tree = arv_b_insere(tree, bloco, t);
        start = start->prox;
    }
    in_t_free(&start);
    printf("\n\n");
    arv_b_imprimir(tree);

	
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
#include "../headers/bloco.h"
#include <stdio.h>
#include <stdlib.h>



ar_data *ar_data_novo(int id, int no_pai, char **content)
{
    ar_data *novo = (ar_data *) malloc(sizeof(ar_data));

    novo->id = id;
    novo->no_pai = no_pai;
    novo->prox_id = -1;
    novo->texto = content;

    return novo;
}
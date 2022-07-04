#ifndef INODE_TREE_H
#define INODE_TREE_H
//tive que add esse ifndef senao ele tentava dar typedef 2 vezes
//erro de redefinicao de struct <- resolvi essa merda as 2h44 da manha pqp

#include <stdlib.h>
#include <stdio.h>
typedef struct arquivo_data
{
    int no_pai,id,prox_id;
    char **texto;
}ar_data;

ar_data * ar_data_novo(int id, int no_pai, char **content);

#endif
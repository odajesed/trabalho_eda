# include <stdio.h>
# include <stdlib.h>

typedef struct inode_table
{
	int					id;
	char				*filename;
	struct inode_table		*prox;
}in_tabela;

in_tabela	*in_t_novo(int id, char *filename);
in_tabela	*in_t_ultimo(in_tabela *start);

void in_t_adicionar(in_tabela **start, in_tabela *new);
void in_t_free(in_tabela **start);
void in_t_imprimir(in_tabela **start);


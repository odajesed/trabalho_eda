
#include "../headers/in_table.h"

in_tabela *in_t_novo(int id, char *filename)
{
	in_tabela	*new;

	if (!id)
		return (NULL);
	new = (in_tabela *) malloc(sizeof(in_tabela));
	if (!new)
		return (NULL);
	new->id = id;
	new->filename = filename;
	new->prox = NULL;
	return (new);
}

in_tabela *in_t_ultimo(in_tabela *start)
{
	if (!start)
		return (NULL);
	if (!start->prox)
		return (start);
	return (in_t_ultimo(start->prox));
}

void in_t_adicionar(in_tabela **start, in_tabela *new)
{
	in_tabela	*last;

	last = in_t_ultimo(*start);
	if (last)
		last->prox = new;
	else
		*start = new;
}

void in_t_free(in_tabela **start)
{
	in_tabela	*p;
	in_tabela	*q;

	p = (*start);
	while (p)
	{
		q = p;
		p = p->prox;
		free(q);
	}
	*start = NULL;
}

void in_t_imprimir(in_tabela **start)
{
	in_tabela	*p;

	p = (*start);
	printf("+---------------------------------------+\n");
	printf("| ID | %-33s|\n", "FILENAME");
	printf("+---------------------------------------+\n");
	while (p)
	{
		printf("| %02d | %-33s|\n", p->id, p->filename);
		p = p->prox;
	}
	printf("+---------------------------------------+\n");
}

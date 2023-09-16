main.c
#include <stdio.h>
#include <stdlib.h>

struct lista 
{
	int info;
	struct lista* prox;	
};
typedef struct lista Lista;

Lista* inicializa()
{
	return NULL;	
}

Lista* insereI(Lista *l, int v)
{
	Lista *novo, *p = l;
	novo = (Lista*) malloc(sizeof(Lista));
	novo->info = v;
	if(l == NULL)
	{
		novo->prox = novo;
	}
	else
	{
		novo->prox = l;	
		
		while(p->prox != l)
		{
			p = p->prox;
		}
		
		p->prox = novo;
	}
	
	return novo;
}

Lista* insereF(Lista* l, int v)
{
	Lista *novo, *p = l, *retorno;
	novo = (Lista*)malloc(sizeof(Lista));
	novo->info = v;
	
	if(l!=NULL)
	{
		novo->prox=l;
		while(p->prox != l)
		{
			p = p->prox;
		}
		p->prox = novo;
		
		retorno = l;
	}
	else
	{
		novo->prox = novo;
		retorno = novo;
	}
	
	return retorno;
}

void imprimir(Lista *l)
{
	Lista *p = l;
	
	if(p != NULL)
	{
		do
		{
			printf("[ %x | %d | %x ] -> ",p, p->info, p->prox);
			p = p->prox;
		} while(p!=l);
	}
}

Lista* excluir(Lista *l, int v)
{
	Lista *p = l, *p2 = l, *ant;
	
	
	do
	{
		if(p->info == v)
		{
			break;
		}
		ant = p;
		p = p->prox;
	} while (p!=l);
	
	if(p==l)
	{
		if(p->prox == l)
		{
			free(p);
			return NULL;
		}
		else 
		{
			while(p2->prox!=l)
			{
				p2 = p2->prox;
			} 
			p2->prox = p->prox;
			free(p);
			return p2->prox;
		}
	}
	else
	{
		ant->prox = p->prox;
		free(p);
		return l;
	}
}

int main()
{
	Lista *l1;
	l1 = inicializa();
	l1 = insereI(l1, 5);
	l1 = insereI(l1, 4);
	l1 = insereI(l1, 3);
	
	l1 = insereF(l1, 6);
	
	l1 = excluir(l1, 3);
	
	imprimir(l1);
	return 0;
}
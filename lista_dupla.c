#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>


typedef struct _produto{

	int codigo;
	char nome[20];
	float preco;

} TpProduto;


typedef struct _nodo{

	TpProduto info;
	struct _nodo *next;
	struct _nodo *prev;

} TpNodo;


typedef struct _lista{

	int nItens;
	TpNodo *first;
	TpNodo *last;

} TpLista;



TpNodo *adicinar(TpNodo *c, TpLista *n){

	TpNodo *a;

	a = (TpNodo *)malloc(sizeof(TpNodo));

	printf("Informe o código do produto: ");
	scanf("%d", &(a->info).codigo);
	__fpurge(stdin);
	printf("Digite o nome  do produto: ");
	fgets(a->info.nome, 20, stdin);
	__fpurge(stdin);
	printf("Informe o preço do produto: ");
	scanf("%f", &((a->info).preco));
	__fpurge(stdin);
	printf("\n\n");

	if (n->nItens == 0){
		a->prev = c;
		a->next = NULL;
		n->first = a;
		n->last = a;
		n->nItens++;

	}else{
		(n->first)->prev = a;
		a->next = (n->first);
		a->prev = NULL;
		n->first = a;
		n->nItens++;

	}

	return a;
}

TpNodo *remover(TpNodo *c, TpLista *n){

	int cod;
	TpNodo *k;

	k = (n->last);


	if (n->nItens == 0){
		printf("Nenhum produto registrado na lista\n\n");

	}
	else if (n->nItens != 0){

		printf("Código do produto a ser removido: ");
		scanf("%d", &cod);
		printf("\n\n");

		if (n->nItens == 1){
			if (cod == c->info.codigo){
				c = NULL;
				n->last = c;
				n->first = c;
				n->nItens--;
				free(c);

			}

		}

		else if (n->nItens > 1){
			
			if (cod == c->info.codigo){
				n->first = c->next;
				(c->next)->prev = NULL;
				n->nItens--;
				free(c);
				return n->first;

			}

			else if (cod == k->info.codigo){

				n->last = k->prev;
				(k->prev)->next = NULL;
				n->nItens--;
				free(k);


			}else{

				while (k != NULL){

					if (cod == (k->info).codigo){
						(k->prev)->next = k->next;
						(k->next)->prev = k->prev;
						n->nItens--;
						free(k);
						break;

					}else{
						k = k->prev;
					}

				}
			}
		}
	}

	return c;
}


void mostrar(TpNodo *c){

	if (c == NULL){
		
		printf("Nenhum produto registrado na lista\n\n");
	}

	while (c != NULL){
		
		printf("Nome do produto: %s", (c->info.nome));
		printf("Código: %d\n", (c->info).codigo);
		printf("Preço: %.2f\n\n\n", (c->info).preco);

		c = c->next;
	}

	return;

}



int main(){

	TpNodo *ld;
	TpLista *cl;
	int op;

	ld = NULL;
	cl = (TpLista *)malloc(sizeof(TpLista));

	cl->first = NULL;
	cl->last = NULL;
	cl->nItens = 0;


	do{
		
		printf("            MENU PRINCIPAL\n\n\n");
		printf("1 - Adicionar produto na lista\n");
		printf("2 - Excuir produto da lista\n");
		printf("3 - Mostrar produtos\n");
		printf("0 - Sair\n\n");
		printf("Escolha uma opção: ");
		scanf("%d", &op);
		printf("\n");

		switch (op){

		case 1:
			ld = adicinar(ld, cl);
			break;

		case 2:
			ld = remover(ld, cl);
			break;

		case 3:
			mostrar(ld);
			break;
		}


	}while (op);


	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct produto{
    int codigo;
    char nome[20];
    float preco;
} tp_produto;

typedef struct nodo{
    tp_produto info;
    struct nodo *next;
    struct nodo *prev;
} tp_nodo;

typedef struct lista{
    int nItens;
    tp_nodo *first;
    tp_nodo *last;
} tp_lista;

tp_lista* push(tp_lista *lista){

    tp_nodo* nuevo = malloc(sizeof(tp_nodo));
    printf("Digite o Codigo: ");
    scanf("%d", &(nuevo->info).codigo);
    printf("Digite o Nome do produto: ");
    getchar();
    fgets((nuevo->info).nome,20,stdin);
    printf("Digite o Valor: ");
    scanf("%f", &((nuevo->info).preco));
    getchar();

    if(lista->nItens==0){
        lista->first=nuevo;
        lista->last=nuevo;
        nuevo->next=NULL;
        nuevo->prev=NULL;
    }
    else{
        lista->first->prev= nuevo;
        nuevo->next =lista->first;
        nuevo->prev =NULL;
        lista->first=nuevo;
    }
    lista->nItens++;
    return  lista;
}

tp_lista* pop(tp_lista *lista){
    if(lista->nItens==0){
        printf("Lista vazia\n");
        return lista;
    }
    int i;
    printf("A lista possui %d elementos\n", lista->nItens);
    printf("Digite o item que deseja remover: ");
    scanf("%d", &i);
    tp_nodo *p;
    p=lista->first;
    int cont=0;
    for(p;p!=NULL;p=p->next){
        cont++;
        if(cont==i)
            break;
    }
    if(p=lista->first){
        lista->first=p->prev;
        (p->prev)->next=NULL;
        lista->nItens--;
    }
    if(p=lista->last){
        lista->last=p->next;
        (p->next)->prev=NULL;
        lista->nItens--;
    }
    else{
        p->prev->next=p->next;
        p->next->prev=p->prev;
        lista->nItens--;
    }
    free(p);
}

void imprime(tp_lista *lista){
    tp_nodo *p;
    p=lista->first;
    if(lista->nItens==0){
        printf("Lista vazia\n");
    }
    else {
        for(p;p!=NULL;p=p->next){
        printf("Codigo do produto: %d\n", (p->info).codigo);
		printf("Nome: %s", (p->info).nome);
		printf("Preco: %.2f", ((p->info).preco));
		printf("\n\n");
        }
    }
}

tp_lista* sort(tp_lista* lista){
	tp_nodo *p, *i, *ultimo, *proximo;
	int codigo,cont;
	for(p=(lista->first)->next; p!=NULL; p=p->next){
		codigo=(p->info).codigo;
		i=p->prev;
		cont=0;
		ultimo=NULL;
		while(i!=NULL && ((i->info).codigo) > codigo){
			ultimo=i;
			i=i->prev;
			cont++;
		}
		if(cont>0){
			if(p->next!=NULL){
				(p->next)->prev=p->prev;
			}
			if(p->prev!=NULL){
				(p->prev)->next=p->next;
			}
			if(i==NULL){
				ultimo->prev=p;
				lista->first=p;
				p->next=ultimo;
				p->prev=i;
			}
			else{
				p->prev=i;
				p->next=i->next;
				i->next=p;
				(p->next)->prev=p;
			}
		}
	}
}


int main(){
    tp_lista *lista = malloc(sizeof(tp_lista));
    int x;
    lista->first=NULL;
    lista->last=NULL;
    lista->nItens=0;
    do{

        printf("            MENU PRINCIPAL\n\n");
        printf("1 - Inserir Elemento na Lista\n");
        printf("2 - Remover Elemento da Liata\n");
        printf("3 - Mostrar Elementos da Lista\n");
        printf("4 - Orddenar\n");
        printf("0 - Sair\n\n");
        printf("Escolha uma opção: ");
        scanf("%d", &x);
        printf("\n\n");

        switch(x){
            case 1: lista = push(lista); break;
            case 2: lista = pop(lista); break;
            case 3: imprime (lista); break;
	    	case 4: sort (lista); break;

        }
    }while(x);
}


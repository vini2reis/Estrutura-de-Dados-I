#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdio_ext.h>
#define TAM 100


typedef struct produto{

    int codigo;
    char nome[TAM];
    float preco;

}tp_produto;


typedef struct nodo{

    tp_produto produto;
    struct nodo *prox;

}tp_nodo;


tp_nodo *push(tp_nodo *p){

    tp_nodo *k;
    k = (tp_nodo *)malloc(sizeof(tp_nodo));

    printf("Informe o código do produto: ");
    scanf("%d", &(k->produto).codigo);
    __fpurge(stdin);
    printf("Digite o nome  do produto: ");
    fgets(k->produto.nome, TAM, stdin);
    __fpurge(stdin);
    printf("Informe o preço do produto: ");
    scanf("%f", &((k->produto).preco));
    __fpurge(stdin);
    printf("\n\n");

    k->prox = p;

    return k;
}



tp_nodo *pop(tp_nodo *p){

	int cod;
	tp_nodo *ant, *k;

	k = p;


	if(p == NULL){
        printf("Nenhum produto registrado na lista\n\n");

	}
	else if(p != NULL){

        printf("Código do produto a ser removido: ");
        scanf("%d", &cod);
        printf("\n\n");

        if(cod == (p->produto).codigo){
            p = p->prox;
            free(k);

        } else {
            ant = k;
            k = k->prox;

        while(k != NULL){

            if(cod == (k->produto).codigo){
                ant->prox = k->prox;
                free(k);
                break;

            }else{
                ant = k;
                k = k->prox;
            }

        }
        }
	}

    return p;
}



void display(tp_nodo *p){

    if(p == NULL){
        printf("Nenhum produto registrado na lista\n\n");
    }

    while(p != NULL){
        printf("Nome do produto: %s", (p->produto.nome));
        printf("Código: %d\n", (p->produto).codigo);
        printf("Preço: %.2f\n\n\n", (p->produto).preco);

        p = p->prox;
    }

    return;

}



int main(){

    tp_nodo *nod;
    int op;

    nod = NULL;


    do{
        printf("            MENU PRINCIPAL\n\n\n");
        printf("1 - Adicionar produto na lista\n");
        printf("2 - Excuir produto da lista\n");
        printf("3 - Mostrar produtos\n");
        printf("0 - Sair\n\n");
        printf("Escolha uma opção: ");
        scanf("%d", &op);
        printf("\n");

        switch(op){

            case 1:
                nod = push(nod);
                break;

            case 2:
                nod = pop(nod);
                break;

            case 3:
                display(nod);
                break;
        }


    }while(op);


    return 0;
}

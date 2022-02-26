#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdio_ext.h>
#define TAM 50

typedef struct _produto{

    int cod;
    char nome[TAM];
    float preco;

}tp_produto;

typedef struct _pilha{

    tp_produto *info;
    int topo;

}tp_pilha;


int Verificar(int n, tp_pilha *p){

    if(p->topo==(n-1)){
        return 1;
        }
    else if(p->topo==-1){
        return -1;
    }

   return 0;
}

void Estado(int n, tp_pilha *p){

    if(n==1){
        printf("Pilha cheia\n\n");
    }
    else if(n==-1){
        printf("Pilha vazia\n\n");

    }else{
        printf("Pilha com espaço disponivel\n\n");
    }

    return;

}

void push(int np, tp_pilha *p){

    int k;
    k = Verificar(np, p);
    
    if(k==1){
    	Estado(k, p);
    }else{
    
    p->topo += 1;
    printf("Digite o código do produto: ");
        scanf("%d", &(((p->info)+(p->topo))->cod));
        __fpurge(stdin);
        printf("Digite nome do produto: ");
        fgets(((p->info)+(p->topo))->nome, TAM, stdin);
        __fpurge(stdin);
        printf("Digite o preço do produto: ");
        scanf("%f", &(((p->info)+(p->topo))->preco));
        printf("\n\n");
    }

    return;

}

void pop(int np, tp_pilha *p){

    int k;
    k = Verificar(np, p);
    
    if(k==-1){
    	Estado(k, p);
    }else{
    p->topo -=1;
    }

    return;
}
void display(tp_pilha *p){

    int i;

    printf("Produtos da pilha\n\n");
    for(i = p->topo; i>=0; i--){
        printf("Nome do produto: %s\n", ((p->info)+i)->nome);
        printf("Código: %d\n", ((p->info)+i)->cod);
        printf("Preço: .2f\n\n", ((p->info)+i)->preco);

    }

}



int main(){

    tp_pilha *pil, *pro;
    int npro, op, op2, op3;
    printf("Informe o numero de produtos: ");
    scanf("%d", &npro);
    printf("\n\n\n");
    pil = (tp_pilha*)malloc(sizeof(tp_pilha));
    (pil->info) = (tp_produto*)malloc(sizeof(tp_produto)*npro);

    pil->topo = -1;

    do{
        printf("      MENU PRINCIPAL      \n\n\n");
        printf("1 - Adicionar produto na pilha\n");
        printf("2 - Excuir produto da pilha\n");
        printf("3 - Mostrar produtos\n");
        printf("0 - Sair\n\n");
        printf("Escolha uma opção: ");
        scanf("%d", &op);
        printf("\n");
        switch(op){
            case 1:
            printf("4 - Verificar\n");
            printf("5 - Inserir\n\n");
            printf("Escolha uma opção: ");
            scanf("%d", &op2);
            printf("\n\n");
            if(op2==4){
                Estado(Verificar(npro, pil), pil);
                break;
            }
            else if(op2==5){
                push(npro, pil);
                break;
            }
            case 2:
            printf("6 - Verificar\n");
            printf("7 - Remover\n\n");
            printf("Escolha uma opção: ");
            scanf("%d", &op3);
            printf("\n\n");
            if(op3==6){
                Estado(Verificar(npro, pil), pil);
                break;
            }
            else if(op3==7){
                pop(npro, pil);
                break;
            }
            case 3:
            display(pil);
            break;
        }

    }while(op);

    free(pil);
    free(pro->info);

    return 0;
}
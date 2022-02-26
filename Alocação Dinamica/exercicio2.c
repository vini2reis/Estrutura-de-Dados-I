#include <stdio.h>
#include <stdlib.h>

typedef struct{

    char nome[50];
    char endereco[100];
    int matricula;

} estudante;

int main()
{
    int i, ne;
    estudante *v;
    scanf("%d", &ne);

    v = (estudante *)malloc(ne * sizeof(estudante));

    for(i=0; i<ne; i++){
        __fpurge(stdin);
        printf("Digite nome: ");
        fgets((v+i)->nome, 50, stdin);
        __fpurge(stdin);
        printf("Digite endereço: ");
        fgets((v+i)->endereco, 100, stdin);
        __fpurge(stdin);
        printf("Digite matricula: ");
        scanf("%d", &((v+i)->matricula));
    }
    printf("\n\n\n");

    for(i=0; i<ne; i++){

        printf("Nome: %s", (v+i)->nome);
        printf("Endereço: %s", (v+i)->endereco);
        printf("Matrícula: %d\n\n", (v+i)->matricula);

    }
    free(v);


    return 0;
}

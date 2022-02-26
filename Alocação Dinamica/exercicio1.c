#include <stdio.h>
#include <stdlib.h>

int main(){

    int *v, i, np, val;
    printf("Digite o número de posições: ");
    scanf("%d", &np);
    printf("\n\n\n");

    v = (int *)malloc(sizeof(int));

    for(i=0; i<np; i++){

        printf("Digite um valor: ");
        scanf("%d", &val);
        *(v+i) = val;
    }
    printf("\n\n\n");

    for(i=0; i<np; i++){

        printf("Posição: %d - %d\n", i, *(v+i));

    }
    free(v);




    return 0;
}

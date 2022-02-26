#include <stdio.h>
#include <stdlib.h>

int *uniao(int *v1, int n1, int *v2, int n2){

    int *v3, i, j;

    v3 = (int *)malloc((n1+n2) * sizeof(int));

    for(i=0; i<n1; i++){
        *(v3+i) = *(v1+i);
    }

    for(j=0; j<n2; j++, i++){
        *(v3+i) = *(v2+j);
    }

    return v3;

}

int main(){

    int *v1, *v2, *v3, n1, n2, i;

    printf("Tamanho do vetor 1: ");
    scanf("%d", &n1);
    v1 = (int *)malloc(n1 * sizeof(int));
    printf("Tamanho do vetor 2: ");
    scanf("%d", &n2);
    v2 = (int *)malloc(n2 * sizeof(int));

    printf("Elementos vetor1: ");
    for(i=0; i<n1; i++){
        scanf("%d", (v1+i));
    }

    printf("Elementos vetor2: ");
    for(i=0; i<n2; i++){
        scanf("%d", (v2+i));
    }

    v3 = uniao(v1, n1, v2, n2);
    for(i=0; i<(n1+n2); i++){
        printf("%d", *(v3+i));
    }
	free(v1);
	free(v2);
	free(v3);

    return 0;
}

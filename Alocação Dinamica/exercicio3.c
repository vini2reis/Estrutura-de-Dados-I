#include <stdio.h>
#include <stdlib.h>

int main(){

    int *v, *v2, i, val, j=1, k, cont;
    scanf("%d", &val);

    v = (int *)malloc(5 * sizeof(int));

    for(i=0; val!=0; i++){

        if((i+1)%5==0){
            j++;
            k = j*5;
            printf("Realocou\n");
            v2 = realloc(v, k * sizeof(int));
            v = v2;
        }
        *(v+i) = val;
        scanf("%d", &val);
    }
    if(i!=0){
        for(cont=0; cont<i; cont++){
            printf("Posição: %d - %d\n", cont, *(v+cont));
        }

    }
    free(v);




    return 0;
}

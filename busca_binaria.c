#include <stdio.h>
#include <stdlib.h>
#define TAM 10

void InsertionSort(int *vt, int t){

    int i, j, aju;

    for(i=0; i<=t; i++){
        for(j=i; j>0; j--){
            while(vt[j]<vt[j-1]){
                aju = vt[j];
                vt[j] = vt[j-1];
                vt[j-1] = aju;
            }
        }
    }
}

int Busca(int *vt, int n, int start, int finish){

	int half;

	if(start >=finish){
		return -1;
	}
	else{
		half = (start + finish)/2;
		if(n == vt[half]){
			return half;
		}
		else if(n>vt[half]){
			return Busca(vt, n, half+1, finish);
		}
		else if(n<vt[half]){
			return Busca(vt, n, start, half-1);
		}
	}
}


int main(){

    int vet[TAM], num, busca, i;

    printf("Preencher vetor: ");
    for(i=0; i<TAM; i++){
        scanf("%d", &vet[i]);
        if(i>=1){
        	InsertionSort(vet, i);
        }
    }

    for(i=0; i<TAM; i++){
    	printf("%d ", vet[i]);
    }
    printf("\n\n");

    printf("Buscar o elemento: ");
    scanf("%d", &num);
    printf("\n\n");
    busca = Busca(vet, num, 0, TAM);
    if(busca == -1){
    	printf("Elemento não encontrado");
    }else{
    	printf("Elemento %d está na posição %d.", num, busca);
    }
}

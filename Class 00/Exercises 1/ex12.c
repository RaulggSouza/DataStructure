#include <stdio.h>

void troca(int* vet, int start, int end, int pivot){
    int i = start, j = end, aux;
    while (j >= i){
        if (vet[i] >= vet[pivot]){
            if (vet[j] <= vet[pivot]){
                aux = vet[i];
                vet[i] = vet[j];
                vet[j] = vet[i];
            }
            j--;
        } else {
            i++;
        }
    }
    
}

void quick(int* vet, int start, int len){
    int pivot = len/2, end = len-1;
    
    troca(vet, start, end, pivot);
}

int main(int argc, char const *argv[]){
    int vector[] = {1,4,5,2,3,7,4,9,2,1};
    for (int i = 0; i < 10; i++){
        printf("%d\t", vector[i]);
    }
    quick(vector, 0, 10);
    for (int i = 0; i < 10; i++){
        printf("%d\t", vector[i]);
    }
    return 0;
}

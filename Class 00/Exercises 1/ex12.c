#include <stdio.h>

void swap(int* vet, int start, int end, int* pivot){
    int i = start, j = end, aux;
    while (j >= i){
        if (vet[i] > vet[*pivot]){
            if (vet[j] <= vet[*pivot]){
                aux = vet[i];
                vet[i] = vet[j];
                vet[j] = aux;
                if (vet[j] == vet[*pivot]) {
                    *pivot = i;
                } 
            }
            j--;
        } else {
            i++;
        }
    }
}

void quick(int* vet, int start, int len){
    if (len==start){
        return;
    }
    int pivot = (len+start)/2;
    swap(vet, start, len-1, &pivot);
    printf("%d - %d - %d\n", start, len, pivot);
    quick(vet, start, pivot);
    quick(vet, pivot+1, len);
}

int main(int argc, char const *argv[]){
    //  int vector[] = {1,2,3,3,1,2,4,3};
    // int vector[] = {3,2,2,2,3,4,4,4};
    int vector[] = {8,7,6,5,4,3,2,1};
    for (int i = 0; i < 8; i++){
        printf("%d\t", vector[i]);
    }
    printf("\n");
    quick(vector, 0, 8);
    for (int i = 0; i < 8; i++){
        printf("%d\t", vector[i]);
    }
    return 0;
}

#include <stdio.h>

int is_ordenated(int* vet, int n){
    int crescent = 1;
    int decrescent = 1;

    for(int i = 0; i < n-1; i++){
        if (vet[i] < vet[i+1]){
            decrescent = 0;
        } else if (vet[i] > vet[i+1]){
            crescent = 0;
        }
    }
    if (crescent){
        return 1;
    }
    if (decrescent){
        return -1;
    }
    return 0;
}

int main(int argc, char const *argv[]){
    int vector[] = {1,1,3,1,2};
    int counter = is_ordenated(vector, 5);
    printf("%d\n", counter);
    return 0;
}

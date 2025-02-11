#include <stdio.h>

int count_occurances(int* vet, int n, int x){
    int counter = 0;
    for (int i = 0; i < n; i++){
        if (vet[i] == x){
            counter++;
        }
    }
    return counter;
}

int main(int argc, char const *argv[]){
    int vector[] = {1,2,3,4,4};
    int counter = count_occurances(vector, 5, 4);
    printf("%d\n", counter);
    return 0;
}

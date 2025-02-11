#include <stdio.h>

int factorial(int n){
    if (n < 0){
        return -1;
    }
    if (n == 1 || n == 0){
        return 1;
    }
    return n * factorial(n-1);
}

int factorial_sum(int n){
    int sum = 0;
    for (int i = 0; i <= n; i++){
        sum += factorial(i);
    }
    return sum;
}

int main(int argc, char const *argv[]){
    int sum = factorial_sum(3);
    printf("%d\n", sum);
    return 0;
}

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

int main(int argc, char const *argv[]){
    int n;
    scanf("%d", &n);
    int f = factorial(n);
    printf("%d\n", f);
    return 0;
}

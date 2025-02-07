#include <stdio.h>

int is_prime(int n){
    if (n > 1){
        for (int i = 2; i < n; i++){
            if (n % i == 0){
                return 0;
            }
        }
        return 1;
    }
    return 0;
}

int main(int argc, char const *argv[]){
    int n;
    scanf("%d", &n);
    int prime = is_prime(n);
    printf("%d\n", prime);
    return 0;
}

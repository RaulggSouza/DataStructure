#include <stdio.h>

int main(int argc, char const *argv[]){
    int num;
    int sum = 0, sum_even = 0, sum_odd = 0;
    do{
        scanf("%d",&num);
        sum += num;
        if (num % 2 == 0){
            sum_even += num;
        } else {
            sum_odd += num;
        }
    } while (num != 0);
    printf("%d, %d, %d\n", sum, sum_even, sum_odd);
    return 0;
}

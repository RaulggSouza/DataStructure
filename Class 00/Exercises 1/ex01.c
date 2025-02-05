#include <stdio.h>
int is_leap_year(int year){
    if (year < 1582){
        return -1;
    }else if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)){
        return 1;
    }
    return 0;
}
int main(int argc, char const *argv[]){
    int n = is_leap_year(2016);
    printf("%d\n", n);
    return 0;
}

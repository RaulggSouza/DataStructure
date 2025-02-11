#include <stdio.h>
#include <string.h>

int is_palindrome(char* s){
    for (int i = 0, j = strlen(s)-1; i < j; i++, j--){
        if (s[i] != s[j]){
            return 0;
        }
    }
    return 1;
}

int main(int argc, char const *argv[]){
    char* String = "teste";
    int counter = is_palindrome(String);
    printf("%d\n", counter);
    return 0;
}

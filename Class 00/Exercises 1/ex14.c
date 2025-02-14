#include <stdio.h>

int check_equal_characters(char* string){
    for (int i = 0; string[i] != '\0'; i++){
        for (int j = i+1; string[j] != '\0'; j++){
            if (string[i] == string[j]){
                return 0;
            }
        }   
    }
    return 1;
}

int main(int argc, char const *argv[]){
    char* string = "PERNAMBUCO";
    int characters = check_equal_characters(string);
    printf("%d", characters);
    return 0;
}

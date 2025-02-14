#include <stdio.h>

int is_anagram(char* a, char* b){
    for(int i = 0; a[i] != '\0'; i++){
        int counter = 0;
        for (int j = 0; a[j] != '\0'; j++){
            if (a[i] == a[j]){
                counter++;
            }
        }
        int anagram = 0;
        for (int j = 0; b[j] != '\0'; j++){
            if (a[i] == b[j]){
                anagram++;
            }
        }
        if (anagram != counter){
            return 0;
        }
    }
    return 1;
}

int main(int argc, char const *argv[]){
    char* s1 = "logaritmo";
    char* s2 = "algoritmo";
    int anagram = is_anagram(s1, s2);
    printf("%d", anagram);
    return 0;
}

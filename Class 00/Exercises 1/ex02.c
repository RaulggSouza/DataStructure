#include <stdio.h>

char* can_vote(int age){
    if (age < 16 || age > 70){
        return "Dismissed";
    } else if (age < 18){
        return "Optional vote";
    } else {
        return "Mandatory vote";
    }
}

int main(int argc, char const *argv[]){
    int age;
    scanf("%d",&age);
    char* type_of_voter = can_vote(age);
    printf("%s\n", type_of_voter);
    return 0;
}

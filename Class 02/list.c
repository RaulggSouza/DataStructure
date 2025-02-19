#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"


int main(int argc, char const *argv[]){
    t_list* list = create_list(10);

    append(list, 4);
    append(list, 5);
    append(list, 6);
    append(list, 7);
    append(list, 8);
    append(list, 9);
    append(list, 10);
    append(list, 11);
    print_list(list);
    insert(list, 3, 210);
    print_list(list);

    destroy_list(list);
    return 0;
}

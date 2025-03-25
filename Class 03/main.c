#include <stdio.h>
#include <stdlib.h>
#include "ordered_list.h"

//Rhuan A. A. Boni & Raul Souza

int main(int argc, char const *argv[])
{
    t_ordered_list *list = create_ordered_list(8);
    insert(list, 1);
    insert(list, 2);
    insert(list, 3);
    insert(list, 4);
    insert(list, 5);
    insert(list, 6);
    insert(list, 7);
    insert(list, 8);
    insert(list, 4);

    t_ordered_list *list2 = create_ordered_list(8);
    insert(list2, 1);
    insert(list2, 2);
    insert(list2, 3);
    insert(list2, 4);
    insert(list2, 5);
    insert(list2, 6);
    insert(list2, 7);
    insert(list2, 8);
    insert(list2, 4);

    print_ordered_list(list);
    print_ordered_list(list2);

    t_ordered_list* list3 = merge(list2, list);
    print_ordered_list(list3);

    return 0;
}

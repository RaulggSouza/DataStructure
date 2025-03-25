#include <stdio.h>
#include <stdlib.h>
#include "ordered_list.h"

//Rhuan A. A. Boni & Raul Souza

t_ordered_list* create_ordered_list(int max)
{
    t_ordered_list* list = (t_ordered_list*) malloc(sizeof(t_ordered_list));
    list->max = max;
    list->n = 0;
    list->items =  (int*) malloc(sizeof(int)*max);

    return list;
}

int size(t_ordered_list* list)
{
    return list->n;
}

int is_full(t_ordered_list* list){
    return size(list) == list->max;
}

int is_empty(t_ordered_list* list)
{
    return size(list) == 0;
}

void destroy(t_ordered_list* list)
{
    free(list->items);
    free(list);
}

void clear(t_ordered_list* list){
    list->n = 0;
}

int insert(t_ordered_list* list, int value)
{
    if (is_full(list))
    {
        list->max *= 2;
        list->items = (int*) realloc(list->items, sizeof(int)* list->max);
    }

    for (int i = size(list)+1; i > 0; i--)
    {   
        if (list->items[i-1] <= value)
        {
            list->items[i] = value;
            list->n++;
            return 1;
        }
        list->items[i] = list->items[i-1];
    }
    
    list->items[0] = value;
    list->n++;
    return 1;
    
}

int search(t_ordered_list* list, int value)
{

    if(is_empty(list))
    {
        return -1;
    }

    for (int i = 0; i < size(list); i++)
    {
        if (list->items[i] == value)
        {
            return i;
        }
    }
    return -1;
}

int remove_by_index(t_ordered_list* list, int index)
{
    if (is_empty(list))
    {
        return 0;
    }
    
    for (int i = index; i < size(list); i++)
    {
        list->items[i] = list->items[i+1];
    }
    list->n--;
    
    return 1;
}

int remove_by_value(t_ordered_list* list, int value){
    if(is_empty(list))
    {
        return 0;
    }

    int index = search(list, value);
    return remove_by_index(list, index);
}

int remove_end(t_ordered_list* list){
    if(is_empty(list))
    {
        return 0;
    }

    list->n--;
    return 1;
}

void print_ordered_list(t_ordered_list* list){
    printf("\n");

    for (int i = 0; i < size(list); i++)
    {
        printf("%d\t", list->items[i]);
    }

    printf("\n");
}

t_ordered_list* merge(t_ordered_list* list1, t_ordered_list* list2){
    if (is_empty(list1) && is_empty(list2)) return NULL;
    if (is_empty(list1)) return list2;
    if (is_empty(list2)) return list1;
    t_ordered_list* list3 = create_ordered_list(size(list1) + size(list2));
    int index1 = 0;
    int index2 = 0;
    int index3 = 0;
    while (index1 < size(list1) && index2 < size(list2)){
        if (list1->items[index1] <= list2->items[index2]){
            list3->items[index3++] = list1->items[index1++];
        } else {
            list3->items[index3++] = list2->items[index2++];
        }
    }
    while (index1 < size(list1)){
        list3->items[index3++] = list1->items[index1++];
    }
    while (index2 < size(list2)){
        list3->items[index3++] = list2->items[index2++];
    }
    return list3;    
}
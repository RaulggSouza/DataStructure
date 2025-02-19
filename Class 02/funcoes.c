#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

t_list* create_list(int max){
    t_list* list = (t_list*) malloc(sizeof(t_list));
    list->max = max;
    list->size = 0;
    list->items = (int*) malloc(sizeof(int)*max);
    return list;
}

void destroy_list(t_list* list){
    free(list->items);
    free(list);
}

int check_index(t_list* list, int index){
    if (index > size(list) || index < 0){
        return 0;
    }
    return 1;
}

int is_empty(t_list* list){
    return list->size <= 0;
}

int is_full(t_list* list){
    return list->size >= list->max;
}

int size(t_list* list){
    return list->size;
}

int append(t_list* list, int elem){
    if(is_full(list)){
        return 0;
    }
    list->items[list->size] = elem;
    list->size++;
    return 1;
}

int insert(t_list* list, int index, int elem){
    if(is_full(list) || check_index(list, index)){
        return 0;
    }
    for (int i = size(list); i > index; i--){
        list->items[i] = list->items[i-1];
    }
    list->items[index] = elem;
    list->size++;
    return 1;
}

int update(t_list* list, int index, int elem){
    if (check_index(list, index)){
        return 0;
    }
    list->items[index] = elem;
    return 1;
}

int index_of(t_list* list, int elem){
    if (is_empty(list)){
        return -1;
    }
    for (int i = 0; i < size(list); i++){
        if(list->items[i] == elem){
            return i;
        }
    }
    return -1;
}

int get(t_list* list, int index){
    if(check_index(list, index) || is_empty(list)){
        return 0;
    }
    return list->items[index];
}

int count(t_list* list, int elem){
    if(is_empty(list)){
        return -1;
    }
    int counter = 0;
    for (int i = 0; i < size(list); i++){
        if(list->items[i] == elem) {
            counter++;
        }
    }
    return counter;
}

int remove_by_index(t_list* list, int index){
    if(is_empty(list) || check_index(list, index)){
        return 0;
    }
    for (int i = index; i+1 < size(list); i++){
        list->items[i] = list->items[i+1];
    }
    list->size--;
    return 1;
}

int remove_by_element(t_list* list, int elem){
    int index = index_of(list, elem);
    return remove_by_index(list, index);
}

void clear(t_list* list){
    list->size = 0;
}

void print_list(t_list* list){
    for (int i = 0; i < size(list); i++){
        printf("%d\t", list->items[i]);
    }
    printf("\n");
}
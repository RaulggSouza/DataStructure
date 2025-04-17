#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int size;
    int max;
    int* vet;
}t_list;

t_list* create_list(int max){
    t_list* list = (t_list*) malloc(sizeof(t_list));
    list->max = max;
    list->size = 0;
    list->vet = (int*) malloc(sizeof(int)*max);
    return list;
}

int is_empty(t_list* list){
    return list->size <= 0;
}

int is_full(t_list* list){
    return list->size >= list->max;
}

int len(t_list* list){
    return list->size;
}

int append(t_list* list, int elem){
    if (is_full(list)){
        return 0;
    }
    list->vet[list->size++] = elem;
    return 1;
}

int insert(t_list* list, int elem, int index){
    if(is_full(list)){
        return 0;
    }
    for (int i = list->size; i > index; i--){
        list->vet[i] = list->vet[i-1];
    }
    list->vet[index] = elem;
    list->size++;
    return 1;
    
}

int update(t_list* list, int elem, int index){
    if (is_empty(list) || index >= list->max){
        return 0;
    }
    list->vet[index] = elem;
    return 1;
}

int remove_by_index(t_list* list, int index){
    if(is_empty(list) || index >= list->max){
        return 0;
    }
    for (int i = index; i+1 < list->size; i++){
        list->vet[i] = list->vet[i+1];
    }
    list->size--;
    return 1;
}

int index_of(t_list* list, int elem){
    if (is_empty(list)){
        return -1;
    }
    for (int i = 0; i < list->size; i++){
        if (list->vet[i] == elem){
            return i;
        }
    }
    return -1;
}

int remove_by_element(t_list* list, int elem){
    if (is_empty(list)){
        return 0;
    }
    int element_finded = 0;
    for (int i = 0; i < list->size; i++){
        if (list->vet[i] == elem){
            element_finded = 1;
        }
        if (element_finded){
            list->vet[i] = list->vet[i+1];
        }
    }
    list->size--;
    return 1;
}

int get(t_list* list, int index){
    return (is_empty(list) ? (int)NULL : list->vet[index]);
}

int count(t_list* list, int elem){
    if (is_empty(list)){
        return 0;
    }
    int counter = 0;
    for (int i = 0; i < list->size; i++){
        if (list->vet[i] == elem){
            counter++;
        }
    }
    return counter;
}

void clear(t_list* list){
    list->size = 0;
}

void destroy(t_list* list){
    free(list->vet);
    free(list);
}

void print_list(t_list* list){
    if (is_empty(list)){
        return;
    }
    for (int i = 0; i < list->size; i++){
        printf("%d ", list->vet[i]);
    }
}

int main(int argc, char const *argv[]){
    t_list* list = create_list(10);
    append(list, 3);
    append(list, 5);
    append(list, 6);
    insert(list, 4, 1);
    remove_by_element(list, 3);
    print_list(list);
    return 0;
}

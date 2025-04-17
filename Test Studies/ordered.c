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

int insert(t_list* list, int elem){
    if (is_full(list)){
        return 0;
    }
    for (int i = list->size; i > 0; i--){
        if (list->vet[i-1] <= elem){
            list->vet[i] = elem;
            list->size++;
            return 1;
        }
        list->vet[i] = list->vet[i-1];
    }
    list->vet[0] = elem;
    list->size++;
    return 1;
}

int merge(t_list* list1, t_list* list2){
    if (is_empty(list1) && is_empty(list2)) return NULL;
    if (is_empty(list1)) return list2;
    if (is_empty(list2)) return list1;
    t_list* list3 = create_list(list1->max + list2->max);
    int i = 0, j = 0, k = 0;
    while(i < list1->size && j < list2->size){
        list3->vet[k++] = (list1->vet[i] <= list2->vet[j] ? list1->vet[i++] : list2->vet[j++]);
    }
    while(i < list1->size){
        list3->vet[k++] = list1->vet[i++];
    }
    while(j < list2->size){
        list3->vet[k++] = list2->vet[j++];
    }
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
    insert(list, 1);
    insert(list, 2);
    insert(list, 3);
    insert(list, 0);
    print_list(list);
    return 0;
}

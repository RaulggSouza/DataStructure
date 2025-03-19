#include <stdio.h>
#include <stdlib.h>

typedef struct _node{
    int item;
    struct _node* next;
} t_node;

typedef struct {
    t_node* head;
    t_node* tail;
    int size;
}t_list;

t_list* create_list(){
    t_list* list = (t_list*) malloc(sizeof(t_list));
    list->size = 0;
    list->head = NULL;
    list->tail = NULL;
}

int is_empty(t_list* list){
    return list->size == 0;
}

int size(t_list* list){
    return list->size;
}

void insert(int elem, int index, t_list* list){
    t_node* node = (t_node*) malloc(sizeof(t_node));
    node->item = elem;
    node->next = NULL;
    if (is_empty(list)){
        list->head = node;
    } else if (index == 0){
        t_node* aux = list->head;
        list->head = node;
    } else {
        
    }
    list->size++;
}

void append(int elem, t_list* list){
    t_node* node = (t_node*) malloc(sizeof(t_node));
    node->item = elem;
    node->next = NULL;
    if (is_empty(list)){
        list->head = node;
    } else {
        list->tail->next = node;
    }
    list->tail = node;
    list->size++;
}

int remove_item(t_list* list, t_node* elem){
    if(is_empty(list)){
        return 0;
    }
    t_node* aux = list->head;
    if (aux->item == elem){
        list->head = aux->next;
        free(aux);
        return 1;
    }
    while (aux->next->item != elem){
        aux = aux->next;
    }
    t_node* node = aux->next;
    aux->next = node->next;
    free(node);
    return 1;
}

t_node* get_node_item(t_list* list, int elem){
    if (is_empty(list)){
        return 0;
    }
    t_node* aux = list->head;
    while (aux->item != elem){
        aux = aux->next;
    }
    return aux;
}

t_node* get_item_by_index(t_list* list, int index){
    if (is_empty(list)){
        return 0;
    }
    t_node* aux = list->head;

}

void print_list(t_list* list){
    t_node* node = list->head;
    while(node != NULL){
        printf("%d ", node->item);
        node = node->next;
    }
}

void destroy_node(t_list* list, t_node* node){
    if (node->next == NULL){
        free(node);
    } else {
        destroy_node(list, node->next);
    }
}

void destroy_list(t_list* list){
    destroy_node(list, list->head);
    free(list);
}

int main(int argc, char const *argv[]){
    t_list* list = create_list();
    append_tail(3, list); 
    append_tail(4, list);
    append_tail(5, list);
    append_tail(6, list);
    print_list(list);
    return 0;
}

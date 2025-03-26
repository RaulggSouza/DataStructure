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

t_node* get_item_by_index(t_list* list, int index){
    if (is_empty(list)){
        return NULL;
    }
    t_node* aux = list->head;
    int i = 0;
    while (aux != NULL){
        if (i == index){
            return aux;
        }
        aux = aux->next;
        i++;
    }
    return aux;
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

int reverse(t_list* list){
    if (is_empty(list)){
        return 0;
    }
    t_node* next = NULL;
    t_node* prev = NULL;
    t_node* current = list->head;
    
    t_node* aux = list->head;
    list->head = list->tail;
    list->tail = aux;

    while (current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
}

int find(t_list* list, int elem){
    if (is_empty(list)){
        return 0;
    }
    t_node* aux = list->head;
    while (aux != NULL){
        if (aux->item == elem){
            return 1;
        }
        aux = aux->next;
    }
    return 0;
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

void insert(int elem, int index, t_list* list){
    t_node* node = (t_node*) malloc(sizeof(t_node));
    node->item = elem;
    node->next = NULL;
    if (is_empty(list)){
        list->head = node;
    } else if (index == 0){
        t_node* aux = list->head;
        list->head = node;
        node->next = aux;
    } else if (index >= size(list)){
        append(elem, list);
        return;
    } else {
       t_node* aux = get_item_by_index(list, index);
       node->next = aux->next;
       aux->next = node;
    }
    list->size++;
}

int remove_item(t_list* list, int elem){
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
    list->tail = (aux->next == NULL ? aux : aux->next);
    list->size--;
    return 1;
}

int remove_at(t_list* list, int index){
    t_node* node = get_item_by_index(list, index);
    if (node != NULL){
        remove_item(list, node->item);
    }
}

t_node* peek_front(t_list* list){
    return list->head;
}

t_node* peek_back(t_list* list){
    return list->tail;
}

t_node* pop_front(t_list *list){
    t_node* front = list->head;
    list->head = front->next;
    return front;
}

t_node* pop_back(t_list *list){
    t_node* back = list->tail;
    list->tail = get_item_by_index(list, size(list)-2);
    return back;
}

void print_list(t_list* list){
    t_node* node = list->head;
    while(node != NULL){
        printf("%d ", node->item);
        node = node->next;
    }
    printf("\n");
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

void clear(t_list* list){
    destroy_node(list, list->head);
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}

int main(int argc, char const *argv[]){
    t_list* list = create_list();
    append(3, list); 
    append(4, list);
    append(5, list);
    append(6, list);
    insert(23, 0, list);
    insert(42, 3, list);
    insert(56, 10, list);
    print_list(list);
    reverse(list);
    print_list(list);
    return 0;
}

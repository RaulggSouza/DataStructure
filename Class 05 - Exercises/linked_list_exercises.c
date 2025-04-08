#include <stdio.h>
#include <stdlib.h>

typedef struct _node{
    int item;
    struct _node* next;
} t_node;

typedef struct {
    t_node* head;
    t_node* tail;
}t_list;

t_list* create_list(){
    t_list* list = (t_list*) malloc(sizeof(t_list));
    list->head = NULL;
    list->tail = NULL;
    return list;
}

int len(t_list* list){
    t_node* node = list->head;
    int size = 0;
    while (node != NULL){
        size++;
        node = node->next;
    }
    return size;
}

int is_empty(t_list* list){
    return len(list) == 0;
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
}

int insert_ordered(t_list* list, int elem, t_node* node){
    if (is_empty(list)){       
        append(elem, list);
    } else if (node == list->tail){
        t_node* new = (t_node*) malloc(sizeof(t_node));
        new->item = elem;
        node->next = new;
        list->tail = new;
        new->next = NULL;
    } else if (elem < list->head->item){
        t_node* new = (t_node*) malloc(sizeof(t_node));
        new->item = elem;
        t_node* aux = list->head;
        list->head = new;
        new->next = aux;
    } else {
        t_node* new = (t_node*) malloc(sizeof(t_node));
        new->item = elem;
        if (elem < node->next->item){
            t_node* aux = node->next;
            node->next = new;
            new->next = aux;
        } else {
            insert_ordered(list, elem, node->next);
        }
    }
    return 1;
}

void swap(t_node* current, t_node* prev, t_node* next){
    if (current == NULL){
        return;
    }
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
    swap(current, prev, next);
}

int reverse_list(t_list* list){
    if (is_empty(list)){
        return 0;
    }
    t_node* current = list->head;
    t_node* prev = NULL;
    t_node* next = NULL;
    
    t_node* aux = list->head;
    list->head = list->tail;
    list->tail = aux;
    swap(current, prev, next);
    return 1;
}

int remove_element(t_list* list, int elem, t_node* node){
    if (node->item == elem && node == list->head){
        t_node* aux = list->head;
        list->head = node->next;
        free(aux);
    } else if (node->next->item == elem && node->next == list->tail){
        free(node->next);
        node->next = NULL;
        list->tail = node;
    } else {
        if (node->next->item == elem){
            t_node* aux = node->next->next;
            free(node->next);
            node->next = aux;
        }else{
            remove_element(list, elem, node->next);
        }
    }
    return 1;
}

t_node* get_node_item(t_list* list, int elem, t_node* node){
    if (is_empty(list)){
        return NULL;
    }
    if (node->item == elem){
        return node;
    }
    return get_node_item(list, elem, node->next);
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

int main(int argc, char const *argv[]){
    t_list* list = create_list();
    append(3,list);
    append(5,list);
    append(7,list);
    append(9,list);
    append(11,list);
    print_list(list);
    reverse_list(list);
    print_list(list);
    return 0;
}

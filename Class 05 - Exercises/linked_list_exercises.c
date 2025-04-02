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
    insert_ordered(list, 12, list->head);
    print_list(list);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

typedef struct t_n{
    int item;
    struct t_n* next;
}t_node;

typedef struct{
    t_node* head;
    t_node* tail;
} t_list;

t_list* create_list(){
    t_list* list = (t_list*) malloc(sizeof(t_list));
    list->head = NULL;
    list->tail = NULL;
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
}

int len(t_list* list){
    int counter = 0;
    t_node* node = list->head;
    while (node != NULL){
        counter++;
    }
}

int is_cicle(t_node* head){
    t_node* fast = head;
    t_node* slow = head;
    while(fast->next != NULL && fast != NULL){
        if (fast == slow){
            return 1;
        }
        fast = fast->next->next;
        slow = slow->next;
    }
    return 0;
}

void destroy_node(t_node* node){
    if(node->next == NULL){
        free(node);
    }
    destroy_node(node->next);
}

void destroy_list(t_list* list){
    destroy_node(list->head);
    free(list);
}

int main(int argc, char const *argv[]){
    t_list* list = create_list();
    return 0;
}

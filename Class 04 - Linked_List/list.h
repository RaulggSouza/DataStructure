#ifndef LIST_H
#define LIST_H

typedef struct _node{
    int item;
    struct _node* next;
} t_node;

typedef struct {
    t_node* head;
    int size;
}t_list;

#endif;
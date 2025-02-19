#ifndef FUNCOES_H
#define FUNCOES_H

typedef struct {
    int max;
    int size;
    int* items;
}t_list;

t_list* create_list(int max);

void destroy_list(t_list* list);

int append(t_list* list, int elem);

int insert(t_list* list, int index, int elem);

int update(t_list* list, int index, int elem);

int remove_by_index(t_list* list, int index);

int remove_by_element(t_list* list, int elem);

int index_of(t_list* list, int elem);

int get(t_list* list, int index);

int count(t_list* list, int elem);

int size(t_list* list);

int is_empty(t_list* list);

int is_full(t_list* list);

void clear(t_list* list);

void print_list(t_list* list);

#endif
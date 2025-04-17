#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start;
    int end;
    int* vet;
    int max;
    int size;
} t_queue;

int create_queue(int max){
    t_queue* queue = (t_queue*) malloc(sizeof(t_queue));
    queue->max = max;
    queue->vet = (int*) malloc(sizeof(int)*max);
    queue->start = 0;
    queue->end = 0;
    queue->size = 0;
    return queue;
}

int is_full(t_queue* queue){
    return queue->size >= queue->max;
}

int is_empty(t_queue* queue){
    return queue->size <= 0;
}

int in(t_queue* queue, int elem){
    if (is_full(queue)){
        return 0;
    }
    queue->vet[queue->end] = elem;
    queue->end = (queue->end + 1) % queue->max;
    queue->size++;
    return 1;
}

int out(t_queue* queue, int *elem){
    if (is_empty(queue)){
        return 0;
    }
    *elem = queue->vet[queue->start];
    queue->start = (queue->start + 1) % queue->max;
    queue->size--;
    return 1;
}

void clear(t_queue* queue){
    queue->start = 0;
    queue->end = 0;
    queue->size = 0;
}

int main(int argc, char const *argv[]){
    
    return 0;
}

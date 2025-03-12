#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int max;
    int top_index;
    int* vet;
} t_stack; 

t_stack* create_stack(int max){
    t_stack* stack = (t_stack*) malloc(sizeof(t_stack));
    stack->max = max;
    stack->top_index = -1;
    stack->vet = (int*) malloc(sizeof(int)*max);
}

int is_full(t_stack* stack){
    return stack->top_index++ == stack->max;
}

int is_empty(t_stack* stack){
    return stack->top_index < 0;
}

int push(t_stack* stack, int elem){
    if (is_full(stack)){
        return 0;
    }
    stack->vet[++stack->top_index] = elem;
    return 1;
}

int pop(t_stack* stack, int* elem){
    if (is_empty(stack)) {
        return 0;
    }
    *elem = stack->vet[stack->top_index];
    stack->top_index--;
    return 1;
}

int top(t_stack* stack){
    if (is_empty(stack)) return 0;
    return stack->vet[stack->top_index];
}

int size(t_stack* stack){
    stack->top_index++;
}

void clear(t_stack* stack){
    stack->top_index = -1;
}

void destroy(t_stack* stack){
    free(stack->vet);
    free(stack);
}

int main(int argc, char const *argv[]){
    t_stack* stack = create_stack(10);
    return 0;
}

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
    stack->vet = malloc(sizeof(int)*max);
}

int is_empty(t_stack* stack){
    return stack->top_index < 0;
}

int is_full(t_stack* stack){
    return stack->top_index+1 == stack->max;
}

int push(t_stack* stack, int elem){
    if (is_full(stack)){
        return 0;
    }
    stack->vet[++stack->top_index] = elem;
    return 1;
}

int pop(t_stack* stack, int *elem){
    if (is_empty(stack)){
        return 0;
    }
    *elem = stack->vet[stack->top_index--];
    return 1;
}

int top(t_stack* stack){
    if(is_empty(stack)){
        return -1;
    }
    return stack->vet[stack->top_index];
}

int main(int argc, char const *argv[]){
    
    return 0;
}

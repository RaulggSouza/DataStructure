#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
    int item;
    struct _node* left;
    struct _node* right;
} t_node;

typedef struct {
    t_node* root;
} t_tree;

t_node* create_node(int item) {
    t_node* node = (t_node*) malloc(sizeof(t_node));
    node->item = item;
    node->left = NULL;
    node->right = NULL;

    return node;
}

t_tree *create_tree() {
    t_tree* tree = (t_tree*) malloc(sizeof(t_tree));
    tree->root = NULL;

    return tree;
}

t_node* insert_rec(t_node* node, int item){
    if (node == NULL){
        return create_node(item);
    }

    if(item < node->item){
        node->left = insert_rec(node->left, item);
    } else if(item > node->item){
        node->right = insert_rec(node->right, item);
    }
    return node;
}

void insert(t_tree* tree, int item){
    tree->root = insert_rec(tree->root, item);
}

t_node* binary_search(t_node* parent_node, int item){
    if (parent_node == NULL || parent_node->item == item){
        return parent_node;
    }
    if (item < parent_node->item){
        return binary_search(parent_node->left, item);
    }else{
        return binary_search(parent_node->right, item);
    }
}

t_node* search(t_tree* tree, int item){
    return binary_search(tree->root, item);
}

void pre_order(t_node* node){
    if (node != NULL) {
        printf("%d ", node->item);
        pre_order(node->left);
        pre_order(node->right);
    }
}

void in_order(t_node* node){
    if (node != NULL) {
        in_order(node->left);
        printf("%d ", node->item);
        in_order(node->right);
    }
}

void post_order(t_node* node){
    if (node != NULL) {
        post_order(node->left);
        post_order(node->right);
        printf("%d ", node->item);
    }
}

int count_side(t_node* node){
    if (node != NULL) {
        int left_height = count_side(node->left);
        int right_height = count_side(node->right);

        if (left_height > right_height) {
            return 1 + left_height;
        }
        return 1 + right_height;
    }

    return 0;
}

int tree_height(t_tree* tree){
    if (tree) {
        return count_side(tree->root);
    }
    
    return 0;
}

// Exercicios: Completar funcoes abaixo:

// Função para desalocar uma árvore
void clear_rec(t_node *node) {
}

// Função para buscar um elemento na árvore (versão não recursiva)
t_node* search_v2(t_tree *tree, int item) {
    return NULL;
}

// Função para inserir um elemento em uma árvore (versão não recursiva)
void insert_v2(t_tree *tree, int item) {
    t_node* node = tree->root;
    t_node* parent_node;
    while(node != NULL){
        parent_node = node;
        if (item < node->item){
            node = node->left;
        }else if (item > node->item){
            node = node->right;
        }
    }
    node = create_node(item);
    if (node->item < parent_node->item){
        parent_node->left = node;
    }else if (node->item > parent_node->item){
        parent_node->right = node;
    }
}

// Função para remover um elemento da árvore (versão não recursiva)
void remove_from_tree_v2(t_tree *tree, int item) {
}

// Função para remover um elemento da árvore (versão recursiva)
void remove_from_tree(t_tree *tree, int item) {
}

// Função para encontrar o menor elemento da árvore


// Função para encontrar o menor elemento da árvore


// Função para retornar a soma dos elementos da árvore


// Função para retornar a quantidade de nós folha


// Função para retornar a altura da árvore
int height(t_node *p){
}


void destroy_nodes(t_node* node){
    if (node != NULL) {
        destroy_nodes(node->left);
        destroy_nodes(node->right);
        free(node);
    }
}

void destroy_tree(t_tree* tree){
    if (tree != NULL) {
        destroy_nodes(tree->root);
    }
    
    free(tree);

}

int main(int argc, char const *argv[]){
    t_node* tree = create_tree();

    t_node* node_a = create_node(36);
    t_node* node_b = create_node(12);
    t_node* node_c = create_node(6);
    t_node* node_d = create_node(24);
    t_node* node_f = create_node(64);
    t_node* node_g = create_node(55);
    t_node* node_h = create_node(69);



    return 0;
}

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
    if (node == NULL){
        return;
    }
    clear_rec(node->left);
    clear_rec(node->right);
    free(node);
}

//Se for para desalocar a árvore
void clear(t_tree* tree){
    clear_rec(tree->root);
    free(tree);
}

// Função para buscar um elemento na árvore (versão não recursiva)
t_node* search_v2(t_tree *tree, int item) {
    t_node* node = tree->root;
    while(node != NULL && node->item != item){
        if (item < node->item){
            node = node->left;
        }
    }
    return node;
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
t_node* remove_node(t_node* node, int item) {
    if (node == NULL){
        return NULL;
    }
    if (node->item == item){
        if (node->left == NULL && node->right == NULL){
            free(node);
            return NULL;
        }else if(node->left != NULL && node->right != NULL){
            t_node* prev = node;
            t_node* replacer = find_big(node->left);
            node = find_big(node->left);
            replacer = NULL;
            free(prev);
            return node;
        } else {
            t_node* remaining_node = (node->left != NULL ? node->left : node->right);
            free(node);
            return remaining_node;
        }
    }
    if (item < node->item){
        node->left = remove_node(node->left, item);
    } else {
        node->right = remove_node(node->right, item);
    }
}

void remove_from_tree(t_tree* tree, int item){
    remove_node(tree->root, item);
}

// Função para encontrar o maior elemento da árvore
// t_node* find_big(t_node* node){
//     if (node->right == NULL){
//         return node;
//     } else {
//         return find_big(node->right);
//     }
// }

t_node* biggest(t_tree* tree) {
    return find_big(tree->root);
}
// Função para encontrar o menor elemento da árvore
t_node* find_smallest(t_node* node){
    if (node->left == NULL){
        return node;
    } else {
        return find_smallest(node->left);
    }
}

t_node* smallest(t_tree* tree) {
    return find_smallest(tree->root);
}

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
    t_tree* tree = create_tree();

    insert(tree, 36);
    insert(tree, 12);
    insert(tree, 6);
    insert(tree, 3);
    insert(tree, 9);
    insert(tree, 24);
    insert(tree, 64);
    insert(tree, 55);
    insert(tree, 69);
    
    pre_order(tree->root);

    // t_node* node = search_v2(tree, 6);
    // if (node == NULL) {
    //     printf("\nEmpty node");
    // }else{
    //     printf("\n%d", node->item);
    // }

    remove_from_tree(tree, 69);
    remove_from_tree(tree, 64);

    printf("\n");

    pre_order(tree->root);
    return 0;
}

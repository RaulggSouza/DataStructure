#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
    int item;
    struct _node* left;
    struct _node* right;
} t_node;

typedef struct{

} t_queue;

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

void print_level(t_tree*){

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

void insert_iterative(t_tree* tree, int item){
    t_node* node = tree->root;
    while(node != NULL){
        if (item < node->item){
            if (node->left == NULL){
                node->left = create_node(item);
            }
            node = node->left;
        } else if (item > node->item){
            if (node->right == NULL){
                node->right = create_node(item);
            }
            node = node->right;
        }
    }
}

void remove_from_tree(t_tree* tree, int item){}

int get_node_height(t_node* node){}

t_node* get_min_item(t_tree* tree){}

t_node* get_max_item(t_tree* tree){}



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
    
    return 0;
}

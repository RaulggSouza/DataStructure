#include <stdio.h>
#include <stdlib.h>

typedef struct _node{
    int item;
    struct _node* right;
    struct _node* left; 
}t_node;


typedef struct{
    t_node* root;
} t_tree;


t_tree* create_tree(){
    t_tree* tree = (t_tree*) malloc(sizeof(t_tree));
    tree->root = NULL;
    return tree;
}

t_node* create_node(int item){
    t_node* node = (t_node*) malloc(sizeof(t_node));
    node->item = item;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int is_empty(t_tree* tree){
    return tree->root == NULL;
}

void insert_right(t_node* node, t_node* parent_node){
    parent_node->right = node;
}

void insert_left(t_node* node, t_node* parent_node){
    parent_node->left = node;
}

void pre_order(t_node* node){
    if (node != NULL) {
        printf("%c ", node->item);
        pre_order(node->left);
        pre_order(node->right);
    }
}

void in_order(t_node* node){
    if (node != NULL) {
        in_order(node->left);
        printf("%c ", node->item);
        in_order(node->right);
    }
}

void post_order(t_node* node){
    if (node != NULL) {
        post_order(node->left);
        post_order(node->right);
        printf("%c ", node->item);
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


int main(int argc, char const *argv[]) {
    t_tree *tree = create_tree();
    
    t_node* node_a = create_node('A');
    t_node* node_b = create_node('B');
    t_node* node_c = create_node('C');
    t_node* node_d = create_node('D');
    t_node* node_e = create_node('E');
    t_node* node_f = create_node('F');
    t_node* node_g = create_node('G');
    t_node* node_h = create_node('H');
    t_node* node_i = create_node('I');
    t_node* node_j = create_node('J');


    tree->root = node_a;
    insert_right(node_c, node_a);
    insert_left(node_b, node_a);

    insert_right(node_e, node_b);
    insert_left(node_d, node_b);

    insert_right(node_g, node_c);
    insert_left(node_f, node_c);

    insert_left(node_h, node_d);

    insert_right(node_j, node_g);
    insert_left(node_i, node_g);

    pre_order(tree->root);
    printf("\n");
    in_order(tree->root);
    printf("\n");
    post_order(tree->root);

    printf("%d", tree_height(tree));

    return 0;
}

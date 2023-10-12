#include <bits/stdc++.h>
typedef struct node_s{
    int x;
    struct node_s *left;
    struct node_s *right;
} node_t
node_t *tree;
tree->left = NULL;
tree->right = NULL;

node_t* order(node_t* root,int key){
    root->x = key;
    root = order(root->right);
    root = order(root)
}

void after(){

}

int main(){

}
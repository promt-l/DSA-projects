#include<stdio.h>
#include<stdlib.h>
struct BST{
    int data;
    struct BST *left;
    struct BST *right;
};
struct BST *createnode(int val){
    struct BST *new = malloc(sizeof(struct BST));
    new->data = val;
    new->left = NULL;
    new->right = NULL;
}
void insert(int val, struct BST *root){
    if(root->data == val)  return;
    else if(root->data > val){
        root->left = insert(val,root->left); 
    }
    else{
        root->right = insert(val,root->right);
    }
}
int main(){
    struct BST *root = createnode(10);
    root->left = createnode(8);
    root->right = createnode(12);
    root->left->left = createnode(5);
    root->left->right = createnode(9);
    root->right->right = createnode(14);
    insert(11,root);
}
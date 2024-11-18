#include<stdio.h>
#include<stdlib.h>
#define max 20
int i = -1;
int store[max];
int n, count = 0;
struct tree{
    int data;
    struct tree *left;
    struct tree *right;
};
struct tree* createnode(int val){
    struct tree* node = malloc(sizeof(struct tree));
    node->data = val;
    node->left = NULL;
    node->right = NULL;
}
void inorder(struct tree* root){
    if(root!=NULL){
    inorder(root->left);
    store[++i] = root->data;
    printf("%d ",store[i]);
    inorder(root->right);
    }
}

int noOfNodes(struct tree *root){
    if(root == NULL) return 0;
    else{
        int lc = noOfNodes(root->left);
        int rc = noOfNodes(root->right);

        return lc + rc+1;
    }
}
 
void isBst(){
    for(int i = 1; i<n; i++){
        if(store[i-1]<store[i]) count++;
    }
    if(count+1 == n) printf("Yes it is a BST\n");
    else printf("It is not a BST\n");
} 
int main(){
    struct tree* root = createnode(8);
    root->left = createnode(6);
    root->right = createnode(10);
    root->left->left = createnode(5);
    root->left->right = createnode(7);
    root->right->left = createnode(9);
    root->right->right = createnode(11);
    inorder(root);
    printf("\n");
    n = noOfNodes(root);
    isBst();
}
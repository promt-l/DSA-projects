#include<stdio.h>
#include<stdlib.h>
int count = 0;
struct tree{
    int data;
    struct tree *left;
    struct tree *right;
};
struct tree *createnode(int val){
    struct tree* node = malloc(sizeof(struct tree));
    node->data = val;
    node->left = NULL;
    node->right = NULL;
} 
int inorder(struct tree* root){
    if(root == NULL) return count ++;
    static int print = 0;
    if(print == 0){
        printf("Inoder Traversal: ");
        print = 1;
    }
    if(root!=NULL){
    inorder(root->left);
    printf("%d ",root->data);
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
int main(){
    struct tree* root = createnode(8);
    root->left = createnode(6);
    root->right = createnode(10);
    root->left->left = createnode(5);
    root->left->right = createnode(7);
    root->right->left = createnode(9);
    root->right->right = createnode(12);
    
    int noOfLeaf = inorder(root);

    printf("No. of leaf nodes:_%d",noOfLeaf);
}
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
void inorder(struct tree* root){
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
void preorder(struct tree* root){
    static int print = 0;
    if(print == 0){
        printf("Preorder Traversal: ");
        print = 1;
    }
    if(root!=NULL){
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
    }
}
void postorder(struct tree* root){
    static int print = 0;
    if(print == 0){
        printf("Postorder Traversal: ");
        print = 1;
    }
    if(root!=NULL){
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
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
///////////////////*********another way to cal no. of nodes************////////////// 
// int noOfNodes(struct tree* root){
//     if(root!=NULL){
//         noOfNodes(root->left);
//         noOfNodes(root->right);
//         count++;
//     }
//     return count;
// }
int heightOfTree(struct tree* root){
    int ls,rs;
    if(root!=NULL){
    ls = heightOfTree(root->left);
    rs = heightOfTree(root->right);
    if(ls>rs) return ls+1;
    else return rs+1;
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
    inorder(root);
    printf("\n");
    preorder(root);
    printf("\n");
    postorder(root);
    printf("\n");

    printf("No. of Nodes = %d\n",noOfNodes(root));
    int height = heightOfTree(root);
    printf("Height Of tree = %d\n",height-1);
}
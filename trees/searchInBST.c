#include<stdio.h>
#include<stdlib.h>
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
//////////////////******search recursively******////////////
int searchInBST(struct tree* root, int val){
    if(root == NULL) return 0;
    else if(root->data == val) return 1;
    else if(root->data > val){
        searchInBST(root->left , val);
    }
    else if(root->data < val){
        searchInBST(root->right , val);
    }
}
//////////////////******search iteratively******////////////
// int searchInBST(struct tree* root, int val){
//     while(root!=NULL){
//         if(root->data == val) return 1;
//         else if(root->data < val) root = root->right;
//         else root = root->left;
//     }
//     return 0;
// }

int main(){
    struct tree* root = createnode(8);
    root->left = createnode(6);
    root->right = createnode(10);
    root->left->left = createnode(5);
    root->left->right = createnode(7);
    root->right->left = createnode(9);
    root->right->right = createnode(11);
    printf("Enter value to search in BST__\n");
    int search;
    scanf("%d",&search);
    int tf = searchInBST(root , search);
    if(tf == 1) printf("Yes, value found\n");
    else printf("Not found\n");
}
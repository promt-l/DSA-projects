#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
}*top = NULL;
void push(int val){
    struct node *newnode = malloc(sizeof(struct node));
    newnode->data = val;
    newnode->next = NULL;
    newnode->next = top;
    top = newnode;
}

void print(){
    struct node *temp;
    temp = top;
    while(temp){
        printf("%d",temp->data);
        temp = temp->data;
    }
}

void reverse(){
    struct node *temp;
    struct node *temp2;
    temp = top;
    while(temp){
        
    }
}

int main(){
    printf("Enter no. of values to push\n");
    int n;
    scanf("%d",&n);
    int val[n];
    for(int i=0;i<n;i++){
    scanf("%d",&val[i]);
    push(val);
    }
    print();
    reverse();
}
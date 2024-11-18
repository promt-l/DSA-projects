#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
}*top = NULL;

int isEmpty(){
    if(top == NULL)
    return 1;
    else
    return 0;
}
void push(int val){
    struct node* new_node = malloc(sizeof(struct node));
    new_node->data = val;
    new_node->next = NULL;
    new_node->next = top;
    top = new_node;
} 
int pop(){
    if(isEmpty()){
        printf("Stack is empty\n");
    }
    else{
    struct node*temp;
    temp = top;
    int deleted = temp->data;
    top = top->next;
    free(temp);
    return deleted;
    }
}
int peek(){
    struct node* temp;
    temp = top;
    if(isEmpty()){
        printf("Stack_underflow\n");
    }
    else{
        return top->data;
    }
}
void print(){
    if(isEmpty()){
        printf("Stack is empty\n");
        exit(1);
    }
    struct node* temp = malloc(sizeof(struct node));
    temp = top;
    while(temp){
        printf("%d\n",temp->data);
        temp = temp->next;
    }
}
int main(){
    while(1){
    printf("1. Push\n");
    printf("2. Print\n");
    printf("3. Pop\n");
    printf("4. Top_element\n");
    printf("5. Exit\n");
    int choice;
    printf("Enter your choice__");
    scanf("%d",&choice);
    switch(choice){
        case 1:
        printf("Enter the element to be pushed\n");
        int new;
        scanf("%d",&new);
        push(new);
        break;
        case 2:
        print();
        break;
        case 3:
        printf("%d\n",pop());
        break;
        case 4:
        printf("%d\n",peek());
        break;
        case 5:
        exit(1);
        default:
        printf("Wrong choice!");
    }
    }
    
}
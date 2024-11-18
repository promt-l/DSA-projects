#include<stdio.h>
#include<stdlib.h>
struct queue{
    int data;
    struct queue *next;
}*tail = NULL,*head=NULL;

int isEmpty(){
    if(head == NULL){
        return 1;
    }
    else return 0;
}
void enqueue(int val){
    struct queue *newnode = malloc(sizeof(struct queue));
    newnode->data = val;
    newnode->next = NULL;
    if(head == NULL){
        head = newnode;
    }
    else{
        tail->next = newnode;
    }
    tail = newnode;
}
void dequeue(){
    if(isEmpty()){
        printf("Queue is underflow\n");
    }
    struct queue *temp = head;
    int deleted = temp->data;
    temp = temp->next;
    head = head->next;
}
void display(){
    if(isEmpty()){
        printf("Queue is underflow\n");
    }
    struct queue *temp = head; 
    while (temp != NULL) {
        printf("%d ", temp->data);  
        temp = temp->next;  
    }
    printf("\n");
}

int main(){
    enqueue(9);
    enqueue(7);
    enqueue(6);
    enqueue(3);
    enqueue(4);
    enqueue(22);
    enqueue(5);
    enqueue(1);
    display();
    dequeue();
    dequeue();
    display();
}
#include<stdio.h>
#define max 5
int front = -1;
int rear  = -1;
int i;
int queue[max];
int isEmpty(){
    if(front == -1 && rear == -1) return 1;
    else return 0;
}
int isFull(){
    if((front == rear + 1) || (front == 0 && rear == max - 1)) return 1;
    else return 0;
}
void enqueue(int val){
    if(isFull()){
        printf("Queue overflow\n");
        return;
    }
    else{
        if(front == -1) front = 0;
        rear = (rear + 1) % max;
        queue[rear] = val;
    }
}
int dequeue(){
    if(isEmpty()){
        printf("Queue underflow\n");
    }
    else{
        int del = queue[front];
        front = (front+1)%max;
        return del;
    }
    
}
void display(){
    if(isEmpty()){
        printf("Queue is empty\n");
    }
    else{
        for(i=front;i!=rear;i=(i+1)%max){
            printf("%d ",queue[i]);
        }
        printf("%d ",queue[i]);
    }
    printf("\n");
}
int main(){
    enqueue(8);
    enqueue(80);
    enqueue(87);
    enqueue(4);
    enqueue(5);
    display();
    // enqueue(74);
    
    // display();
    // enqueue(11);
    dequeue();
    enqueue(32);
    display();
}

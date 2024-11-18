#include<stdio.h>
#include<stdlib.h>
#define max 5
//globally declared variable
int arr[max];
int idx=-1;
void isEmpty(){
    if(idx<0){
        printf("Stack underflow");
        exit(1);
    }
}
void isFull(){
    if(idx==max-1){
        printf("stack is overflow\n");
    }
    return;
}
void push(int val){
    isFull(idx);
    idx++;
    arr[idx] = val;
    return;
}
// int top(){
//     return arr[idx];
// }
int pop(){
    isEmpty();
    int value = arr[idx--];
    return value;
}
// int size(){
//     return idx+1;
// }
int main(){
    int arr[max];
    int idx =-1;
    push(50);
    push(63);
    push(54);
    push(72);
    push(45);
    int data=pop();
    data=pop();
    data=pop();
    data=pop();
    data=pop();
    data=pop();
    printf("Deleted element %d\n",data);
    // top(idx ,arr);
    // size(idx);
}
#include<stdio.h>
#define max 30

int stack[max];
int i=0;
int count = 0;

void push(int rem){
    stack[i] = rem;
    i++;
    return;
}
int pop(){
    return stack[--i];
}
void print(){
    for(int j=0;j<count;j++){
    printf("%d ",pop());
    }
}
int main(){
    int n;
    int rem;
    scanf("%d",&n);
    while(n!=0){
        push(n%2);
        n = n/2;
        count++;
    }
    print();
}
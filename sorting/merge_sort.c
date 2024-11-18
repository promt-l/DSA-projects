#include<stdio.h>
#include<stdlib.h>

void sorted_merge(int a[], int b[], int arr[] , int n1, int n2){
    int i = 0;
    int j = 0;
    int k = 0;
  
    while(i<n1 && j<n2){
        if(a[i]<b[j]){
            arr[k++] = a[i++];
        }
        else{
            arr[k++] = b[j++];
        }
    }
    if(i == n1){
        while(j<n2)
        {arr[k++] = b[j++];}
    }
    if(j == n2){
        while(i<n1)
        {arr[k++] = a[i++];}
    }

}

void divide(int arr[], int n){
    if(n==1) return;
    int n1 = n/2;
    int n2 = n - n/2;
    int a[n1];
    int b[n2];
    for(int i=0;i<n1;i++){
        a[i] = arr[i];
    }
    for(int j=0;j<n2;j++){
        b[j] = arr[j+n1];
    }
    divide(a,n1);
    divide(b,n2);
    sorted_merge(a,b,arr,n1,n2);
}
int main(){
    int arr[] = {9,8,3,64,5,52,4};
    int size = sizeof(arr)/sizeof(arr[0]);
    divide(arr,size);
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
}

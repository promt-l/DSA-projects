#include<stdio.h>
#include<stdlib.h>
void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int arr[], int si, int ei){
    int pivot = arr[si];
    int count = 0;
    for(int i=si+1;i<=ei;i++){
        if(arr[i]<=pivot) count++;
    }
    int i = si;
    int j = ei;
    int pivotIdx = count + si;
    swap(&arr[si],&arr[pivotIdx]);
    while(i<pivotIdx && j>pivotIdx){
        if(arr[i]<=pivot) i++;
        if(arr[j]>pivot) j--;
        else if(arr[i]>pivot && arr[j]<=pivot){
            swap(&arr[i],&arr[j]);
            i++;
            j--;
        }
    }

    return pivotIdx;

}
void quick_sort(int arr[], int si, int ei){
    if(si>=ei) return;
    int pi = partition(arr,si,ei);

    quick_sort(arr,si,pi-1);
    quick_sort(arr,pi+1,ei);
}
int main(){
    int arr[] = {9,6,8,2,3,4,7};
    int size = sizeof(arr)/sizeof(arr[0]);
    quick_sort(arr,0,size-1);
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
}
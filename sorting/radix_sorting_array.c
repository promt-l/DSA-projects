#include<stdio.h>
#include<stdlib.h>

int get_max(int a[],int n){
    int max = a[0];
    for(int i=0;i<n;i++){
        if(a[i]>max) max = a[i];
    }

    return max;
}

void print(int a[], int n){
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
}

void counting_sort(int a[], int exp, int n){
    int count[10] = {0};
    int b[n];
    for(int i=0;i<n;i++){
        count[(a[i]/exp)%10]++;
    }
    for(int i=1;i<10;i++){
        count[i] = count[i] + count[i-1];
    }
    for(int i=n-1;i>=0;i--){
        b[--count[(a[i]/exp)%10]] = a[i];
    }
    for(int i=0;i<n;i++){
        a[i] = b[i];
    }
    
}

void radix_sort(int a[], int n){
    int max = get_max(a,n);

    for(int exp=1; max/exp>0; exp *= 10){
        counting_sort(a,exp,n);
    }
}

int main(){
    printf("Enter no. of integers you want to sort:\n");
    int n;
    scanf("%d",&n);
    int a[n];
    printf("Enter integers:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    radix_sort(a,n);
    print(a,n);
}

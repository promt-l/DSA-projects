#include <stdio.h>

#define MAX 100
int a[MAX];
int size = 0;

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void deleteRoot() {
    if (size <= 0) {
        printf("Heap is empty!\n");
        return;
    }

    swap(&a[0], &a[size - 1]);
    size--;
 
    int i = 0;

    while (2 * i + 1 < size) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = i;

        if (left < size && a[left] < a[smallest]) {
            smallest = left;
        }
        if (right < size && a[right] < a[smallest]) {
            smallest = right;
        }

        if (smallest == i) {
            break;
        }

        swap(&a[i], &a[smallest]);
        i = smallest;
    }
   
}

void insert(int val) {
    if (size >= MAX) {
        printf("Heap overflow!\n");
        return;
    }

    a[size] = val;
    int i = size;

    while (i > 0 && a[(i - 1) / 2] > a[i]) {
        swap(&a[(i - 1) / 2], &a[i]);
        i = (i - 1) / 2;
    }

    size++;
}

void printHeap() {
    printf("Min Heap: ");
    for (int i = 0; i < 9; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main() {
    insert(70);
    insert(50);
    insert(16);
    insert(10);
    insert(9);
    insert(45);
    insert(35);
    insert(39);
    insert(40);

    printHeap();
    for(int i=0;i<9;i++){
        deleteRoot();
    }
    

    printHeap();

    return 0;
}

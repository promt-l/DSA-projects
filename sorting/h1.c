#include <stdio.h>
#include <stdlib.h>

int *heap;       // Array to represent the heap
int heapSize;    // Current size of the heap
int capacity;    // Capacity of the heap

// Function to swap two integers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify-down function to maintain min-heap property
void heapifyDown(int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < heapSize && heap[left] < heap[smallest]) {
        smallest = left;
    }
    if (right < heapSize && heap[right] < heap[smallest]) {
        smallest = right;
    }
    if (smallest != index) {
        swap(&heap[smallest], &heap[index]);
        heapifyDown(smallest);
    }
}

// Heapify-up function to maintain min-heap property
void heapifyUp(int index) {
    int parent = (index - 1) / 2;
    if (index > 0 && heap[index] < heap[parent]) {
        swap(&heap[index], &heap[parent]);
        heapifyUp(parent);
    }
}

// Insert a value into the min-heap
void insertHeap(int val) {
    if (heapSize < capacity) {
        heap[heapSize] = val;
        heapifyUp(heapSize);
        heapSize++;
    } else if (val > heap[0]) {
        heap[0] = val;   // Replace root with the new value if it's larger
        heapifyDown(0);
    }
}

// Add a new element and return the kth largest element
int add(int val) {
    insertHeap(val);
    return heap[0];  // Root of the min-heap is the kth largest element
}

// Function to initialize the heap
void kthLargestCreate(int k, int* nums, int numsSize) {
    heap = (int*)malloc(sizeof(int) * k);  // Allocate memory for the heap
    heapSize = 0;
    capacity = k;

    // Insert elements from the initial nums array into the heap
    for (int i = 0; i < numsSize; i++) {
        insertHeap(nums[i]);
    }
}

// Free the allocated memory
void kthLargestFree() {
    free(heap);
}

// Test the functionality
int main() {
    int nums[] = {4, 5, 8, 2};
    int k = 3;

    // Initialize the heap
    kthLargestCreate(k, nums, 4);

    // Test the add functionality and print kth largest element after each insertion
    printf("%d\n", add(3));  // return 4
    printf("%d\n", add(5));  // return 5
    printf("%d\n", add(10)); // return 5
    printf("%d\n", add(9));  // return 8
    printf("%d\n", add(4));  // return 8

    // Free memory
    kthLargestFree();
    return 0;
}

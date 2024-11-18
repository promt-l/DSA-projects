#include <stdio.h>

#define MAX_HEAP_SIZE 100

int heap[MAX_HEAP_SIZE];  // Array to store heap elements
int size = 0;  // Current size of the heap

// Function to swap two elements
void swap(int *h, int *y, int z) {
    int temp = *h;
    *h = *y;
    *y = temp;
}

// Downward Heapify (Max-Heap) from index i
void heapify(int i) {
    int largest = i;  // Initialize largest as root
    int left = 2 * i + 1;  // Left child index
    int right = 2 * i + 2;  // Right child index

    // Check if left child exists and is greater than root
    if (left < size && heap[left] > heap[largest]) {
        largest = left;
    }

    // Check if right child exists and is greater than largest so far
    if (right < size && heap[right] > heap[largest]) {
        largest = right;
    }

    // If largest is not root, swap and continue heapifying
    if (largest != i) {
        swap(&heap[i], &heap[largest],2);
        heapify(largest);  // Recursively heapify the affected subtree
    }
}

// Upward Heapify (Max-Heap) after insertion
void upHeapify(int i) {
    while (i > 0 && heap[(i - 1) / 2] < heap[i]) {
        swap(&heap[i], &heap[(i - 1) / 2],2);
        i = (i - 1) / 2;  // Move to parent index
    }
}

// Function to insert a new value into the heap
void insert(int val) {
    if (size >= MAX_HEAP_SIZE) {
        printf("Heap overflow!\n");
        return;
    }

    heap[size] = val;  // Insert at the end
    size++;
    upHeapify(size - 1);  // Restore heap property
}

// Function to delete the root of the heap
void deleteRoot() {
    if (size <= 0) {
        printf("Heap is empty!\n");
        return;
    }

    heap[0] = heap[size - 1];  // Move last element to root
    size--;  // Reduce heap size
    heapify(0);  // Restore heap property from the root
}

// Function to print the heap
void printHeap() {
    printf("Heap: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", heap[i]);
    }
    printf("\n");
}

// Main function to demonstrate heap operations
int main() {
    insert(50);
    insert(30);
    insert(40);
    insert(70);
    insert(10);
    insert(60);

    printf("Initial Heap:\n");
    printHeap();  // Print heap after insertion

    deleteRoot();
    printf("Heap after deleting root:\n");
    printHeap();  // Print heap after deletion

    return 0;
}

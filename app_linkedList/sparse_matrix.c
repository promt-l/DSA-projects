#include <stdio.h>
#include <stdlib.h>

// Define the structure of a Node
struct Node {
    int row;
    int col;
    int value;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int row, int col, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->row = row;
    newNode->col = col;
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node into the list in row-major order
void insertNode(struct Node** head, int row, int col, int value) {
    struct Node* newNode = createNode(row, col, value);

    // Special case for the head end
    if (*head == NULL || (*head)->row > row || 
        ((*head)->row == row && (*head)->col > col)) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    struct Node* current = *head;
    while (current->next != NULL && 
          (current->next->row < row || 
          (current->next->row == row && current->next->col < col))) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
}

// Function to display the sparse matrix
void displaySparseMatrix(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("Element at (%d, %d) = %d\n", current->row, current->col, current->value);
        current = current->next;
    }
}

// Function to add two sparse matrices
struct Node* addSparseMatrices(struct Node* head1, struct Node* head2) {
    struct Node* headResult = NULL;
    struct Node* current1 = head1;
    struct Node* current2 = head2;

    while (current1 != NULL || current2 != NULL) {
        if (current1 == NULL) {
            insertNode(&headResult, current2->row, current2->col, current2->value);
            current2 = current2->next;
        } else if (current2 == NULL) {
            insertNode(&headResult, current1->row, current1->col, current1->value);
            current1 = current1->next;
        } else if (current1->row < current2->row || 
                  (current1->row == current2->row && current1->col < current2->col)) {
            insertNode(&headResult, current1->row, current1->col, current1->value);
            current1 = current1->next;
        } else if (current1->row > current2->row || 
                  (current1->row == current2->row && current1->col > current2->col)) {
            insertNode(&headResult, current2->row, current2->col, current2->value);
            current2 = current2->next;
        } else {
            int sumValue = current1->value + current2->value;
            if (sumValue != 0) {
                insertNode(&headResult, current1->row, current1->col, sumValue);
            }
            current1 = current1->next;
            current2 = current2->next;
        }
    }

    return headResult;
}

// Main function to demonstrate sparse matrix operations
int main() {
    struct Node* sparseMatrix1 = NULL;
    struct Node* sparseMatrix2 = NULL;
    struct Node* resultMatrix = NULL;

    // Insert elements into the first sparse matrix
    insertNode(&sparseMatrix1, 0, 1, 5);
    insertNode(&sparseMatrix1, 1, 2, 8);
    insertNode(&sparseMatrix1, 2, 3, 3);

    // Insert elements into the second sparse matrix
    insertNode(&sparseMatrix2, 0, 1, 7);
    insertNode(&sparseMatrix2, 1, 2, -8);
    insertNode(&sparseMatrix2, 2, 3, 6);

    // Display the first sparse matrix
    printf("Sparse Matrix 1:\n");
    displaySparseMatrix(sparseMatrix1);

    // Display the second sparse matrix
    printf("Sparse Matrix 2:\n");
    displaySparseMatrix(sparseMatrix2);

    // Add the two sparse matrices
    resultMatrix = addSparseMatrices(sparseMatrix1, sparseMatrix2);

    // Display the result sparse matrix
    printf("Resultant Sparse Matrix (Sum):\n");
    displaySparseMatrix(resultMatrix);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    int priority;
    struct Node* next;
};

struct Node* newNode(int d, int p) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = d;
    temp->priority = p;
    temp->next = NULL;
    return temp;
}

struct Node* push(struct Node* head, int d, int p) {
    struct Node* temp = head;
    struct Node* nn = newNode(d, p);

    if (head == NULL || head->priority > p) {
        nn->next = head;
        head = nn;
    } else {
        while (temp->next != NULL && temp->next->priority <= p) {
            temp = temp->next;
        }
        nn->next = temp->next;
        temp->next = nn;
    }
    return head;
}

int peek(struct Node* head) {
    if (head == NULL) {
        printf("Priority queue is empty.\n");
        return -1;
    }
    return head->data;
}

void display(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("Data: %d Priority: %d\n", temp->data, temp->priority);
        temp = temp->next;
    }
}

int main() {
    struct Node* pq = NULL;

    pq = push(pq, 14, 8);
    pq = push(pq, 55, 5);
    pq = push(pq, 26, 0);
    pq = push(pq, 17, 1);
    pq = push(pq, 63, 6);
    pq = push(pq, 99, 2);

    printf("Priority Queue:\n");
    display(pq);

    printf("\nElement with highest priority is %d\n", peek(pq));

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

struct node {
    int val;
    int pow;
    struct node* next;
};

void print(struct node* head) {
    struct node* temp = head;
    while (temp != NULL) {
        printf("%dx^%d + ", temp->val, temp->pow);
        temp = temp->next;
    }
    printf("\n");
}

struct node* insert(struct node* head, int num, int exp) {
    struct node* new_node = malloc(sizeof(struct node));
    new_node->val = num;
    new_node->pow = exp;
    new_node->next = NULL;
    if (head == NULL || head->pow < exp) {
        new_node->next = head;
        head = new_node;
    } else {
        struct node* ptr = head;
        while (ptr->next != NULL && ptr->next->pow > exp) {
            ptr = ptr->next;
        }
        new_node->next = ptr->next;
        ptr->next = new_node;
    }
    return head;
}

struct node* addPoly(struct node* head1, struct node* head2) {
    struct node* ptr1 = head1;
    struct node* ptr2 = head2;
    struct node* add = NULL;

    while (ptr1 != NULL && ptr2 != NULL) {
        if (ptr1->pow == ptr2->pow) {
            add = insert(add, ptr1->val + ptr2->val, ptr1->pow);
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        } else if (ptr1->pow > ptr2->pow) {
            add = insert(add, ptr1->val, ptr1->pow);
            ptr1 = ptr1->next;
        } else {
            add = insert(add, ptr2->val, ptr2->pow);
            ptr2 = ptr2->next;
        }
    }

    // Add remaining terms of first polynomial
    while (ptr1 != NULL) {
        add = insert(add, ptr1->val, ptr1->pow);
        ptr1 = ptr1->next;
    }

    // Add remaining terms of second polynomial
    while (ptr2 != NULL) {
        add = insert(add, ptr2->val, ptr2->pow);
        ptr2 = ptr2->next;
    }

    return add;
}

int main() {
    struct node* head1 = NULL;
    struct node* head2 = NULL;
    int n, m;
    printf("Enter no. of terms\n");
    scanf("%d %d", &n, &m);
    int val, exp;
    
    printf("Enter 1st polynomial val & powers\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &val, &exp);
        head1 = insert(head1, val, exp);
    }

    printf("Enter 2nd polynomial val & powers\n");
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &val, &exp);
        head2 = insert(head2, val, exp);
    }

    printf("First Polynomial: ");
    print(head1);

    printf("Second Polynomial: ");
    print(head2);

    struct node* sum = addPoly(head1, head2);
    printf("Sum of Polynomials: ");
    print(sum);

    return 0;
}

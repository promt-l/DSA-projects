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
        printf("%dx^%d ", temp->val, temp->pow);
        temp = temp->next;
    }
    printf("\n");
}

struct node* insert(struct node* head, int num, int exp) {
    struct node* new_node = malloc(sizeof(struct node));
    new_node->val = num;
    new_node->pow = exp;
    new_node->next = NULL;
    if (head == NULL) {
        head = new_node;
    }
    
    else {
        struct node* ptr = head;
        while (ptr->next!=NULL) {
            ptr = ptr->next;
        }
        ptr->next = new_node;
    }
    return head;
}

struct node* mulPoly(struct node* head1, struct node* head2) {
    struct node* ptr1 = head1;
    struct node* ptr2 = head2;
    struct node* mul = NULL;

    while (ptr1 != NULL) {
    
        while(ptr2!=NULL){
            mul = insert(mul, (ptr1->val * ptr2->val), (ptr1->pow + ptr2->pow));
            ptr2 = ptr2->next;
        }
        ptr2 = head2;
        ptr1 = ptr1->next;
    }
 
    return mul;
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

    struct node* sum = mulPoly(head1, head2);
    printf("Multiplication of Polynomials: ");
    print(sum);

    return 0;
}

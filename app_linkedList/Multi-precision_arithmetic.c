#include <stdio.h>
#include <stdlib.h>

struct node {
    int val;
    struct node* next;
};

struct node* createN(int val){
    struct node* newnode = malloc(sizeof(struct node));
    newnode->val = val;
    newnode->next = NULL;
    return newnode;
}

void displaySum(struct node* result){
    struct node* temp = result;
    while(temp!=NULL){
        printf("%d",temp->val);
        temp=temp->next;
    }
}

struct node* insert(struct node* head, int val){
    struct node* nn = createN(val);
    if(head == NULL){
        head = nn;
    }
    else{
        struct node* temp = head;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->next = nn;
    }
    return head;
}

struct node *reverse(struct node *num){
    struct node* f = NULL;
    struct node* current = num;
    struct node* l = NULL;
    while(current!=NULL){
        l = current->next;
        current->next = f;
        f = current;
        current = l;
    }
    
    return f;
}
struct node* add(struct node* num1,struct node* num2){
    num1 = reverse(num1);
    num2 = reverse(num2);

    struct node* res = NULL;
    // struct node* ptr2 = NULL;
    int carry = 0;

    while(num1!=NULL || num2!=NULL || carry != 0){
        int sum = carry;
        if(num1!=NULL){
            sum = sum + num1->val;
            num1 = num1->next;
        }
        if(num2!=NULL){
            sum = sum + num2->val;
            num2 = num2->next;
        }

        carry = sum/10;
        sum = sum%10;
        res = insert(res,sum);
    }
    res = reverse(res);
    return res;

}

int main(){
    struct node* num1 = NULL;
    struct node* num2 = NULL;

//  5926374 + 2546973  = 8473347
    num1 = insert(num1,5);
    num1 = insert(num1,9);
    num1 = insert(num1,2);
    num1 = insert(num1,6);
    num1 = insert(num1,3);
    num1 = insert(num1,7);
    num1 = insert(num1,4);

    num2 = insert(num2,2);
    num2 = insert(num2,5);
    num2 = insert(num2,4);
    num2 = insert(num2,6);
    num2 = insert(num2,9);
    num2 = insert(num2,7);
    num2 = insert(num2,3);

    struct node* result = add(num1,num2);

    displaySum(result);
}
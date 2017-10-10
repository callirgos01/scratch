#include <stdio.h>
#include <stdlib.h>  

/*
ou are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
*/

struct ListNode {
    int val;
    struct ListNode *next;
};

static struct ListNode nodes[50];

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* toReturn = (struct ListNode*)calloc(1,16);
    struct ListNode* iterator = toReturn;
    int carry = 0;
    while((l1)||(l2)||(carry != 0)) {
        int value1 = 0;
        int value2 = 0;
        if(l1!=NULL){
            value1 = l1->val;
        }
        if(l2!=NULL) {
            value2 = l2->val;
        }
        int sum = carry + value1 + value2;
        carry = sum / 10;
        iterator->val = sum % 10;
        if(l1!=NULL){
            l1=l1->next;
        }
        if(l2!=NULL) {
            l2=l2->next;
        }
        if(l1||l2||(carry != 0)) {
            iterator->next = (struct ListNode*)calloc(1,16);
            iterator = iterator->next;
        }
    }
    return toReturn;
    
}

void PrintLinkedList( struct ListNode *toPrint ) {
    //printf("somerhting\r\n");
    while(toPrint) {
        printf("%u", toPrint->val);
        toPrint = toPrint->next;
    }

}

int main( void ) {
    struct ListNode *result;
    struct ListNode *l1 = (struct ListNode*)calloc(1,16);
    struct ListNode *l1Next = (struct ListNode*)calloc(1,16);
    struct ListNode *l1NextNext = (struct ListNode*)calloc(1,16);
    struct ListNode *l2 = (struct ListNode*)calloc(1,16);
    struct ListNode *l2Next = (struct ListNode*)calloc(1,16);
    struct ListNode *l2NextNext = (struct ListNode*)calloc(1,16);
    //Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
    l1->val = 2;
    l1->next = l1Next;
    l1Next->val = 4;
    l1Next->next = l1NextNext;
    l1NextNext->val = 3;

    l2->val = 5;
    l2->next = l2Next;
    l2Next->val = 6;
    l2Next->next = l2NextNext;
    l2NextNext->val = 4;

    PrintLinkedList(l1);
    printf(" -> ");
    PrintLinkedList(l2);
    printf(" = ");
    result = addTwoNumbers(l1,l2);
    PrintLinkedList(result);
    printf("\r\n");
}
//FormAI DATASET v1.0 Category: Data mining ; Style: recursive
#include<stdio.h>
#include<stdlib.h>

typedef struct LinkedListNode {
    int value;
    struct LinkedListNode *next;
} LinkedListNode;

LinkedListNode* createLinkedList(int arr[], int n) {
    if(n == 0) {
        return NULL;
    }
    LinkedListNode *head = (LinkedListNode*)malloc(sizeof(LinkedListNode));
    head->value = arr[0];
    head->next  = createLinkedList(arr+1, n-1);
    return head;
}

void printLinkedList(LinkedListNode *head) {
    if(head == NULL) {
        printf("\n");
        return;
    }
    printf("%d -> ", head->value);
    printLinkedList(head->next);
}

int maxValueInLinkedList(LinkedListNode *head, int maxValue) {
    if(head == NULL) {
        return maxValue;
    }
    if(head->value > maxValue) {
        maxValue = head->value;
    }
    return maxValueInLinkedList(head->next, maxValue);
}

int main() {
    int arr[5] = {23, 17, 38, 42, 19};
    LinkedListNode *head = createLinkedList(arr, 5);
    printf("The linked list is: ");
    printLinkedList(head);
    printf("The maximum value in the linked list is: %d\n", maxValueInLinkedList(head, -1));
    return 0;
}
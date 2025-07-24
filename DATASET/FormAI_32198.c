//FormAI DATASET v1.0 Category: Linked list operations ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

void addNode(struct ListNode **head, int value) {
    struct ListNode *newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = value;
    newNode->next = NULL;

    if (*head == NULL) { // List is empty
        *head = newNode;
    } else {
        struct ListNode *currentNode = *head;
        while (currentNode->next != NULL) { // Traverse to end of list
            currentNode = currentNode->next;
        }
        currentNode->next = newNode; // Add new node to end
    }
}

void removeNode(struct ListNode **head, int value) {
    struct ListNode *currentNode = *head;
    struct ListNode *prevNode = NULL;

    while (currentNode != NULL && currentNode->val != value) { // Traverse to node to remove
        prevNode = currentNode;
        currentNode = currentNode->next;
    }

    if (currentNode == NULL) { // Node not found
        return;
    }

    if (prevNode == NULL) { // Removing first node
        *head = currentNode->next;
    } else {
        prevNode->next = currentNode->next;
    }

    free(currentNode);
}

void printList(struct ListNode *head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    while (head != NULL) { // Traverse and print all nodes
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct ListNode *head = NULL;

    addNode(&head, 3);
    addNode(&head, 7);
    addNode(&head, 5);
    addNode(&head, 2);

    printf("Initial List: ");
    printList(head);

    removeNode(&head, 7);

    printf("List after removing 7: ");
    printList(head);

    removeNode(&head, 3);

    printf("List after removing 3: ");
    printList(head);

    return 0;
}
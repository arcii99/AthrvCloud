//FormAI DATASET v1.0 Category: Memory management ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void addNode(struct Node** headRef, int newData) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = *headRef;
    *headRef = newNode;
}

int main() {
    struct Node* head = NULL;
    int numNodes, i, data;

    printf("Enter the number of nodes: ");
    scanf("%d", &numNodes);

    for (i = 0; i < numNodes; i++) {
        printf("Enter data for node %d: ", i+1);
        scanf("%d", &data);
        addNode(&head, data);
    }

    printf("\nLinked List: ");
    struct Node* curNode = head;
    while (curNode != NULL) {
        printf("%d  ", curNode->data);
        curNode = curNode->next;
    }
    printf("\n");

    return 0;
}
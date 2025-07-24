//FormAI DATASET v1.0 Category: Data structures visualization ; Style: innovative
#include<stdio.h>

// Defining a structure for the node in the Linked List
struct node {
    int data;
    struct node* next;
};

// Function to create a new node
struct node* createNewNode(int value) {
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to visualize the Linked List
void visualizeLinkedList(struct node* head) {
    struct node* temp = head;

    printf("\n\n");

    // Printing the arrow symbols and node values for better visualization
    while (temp != NULL) {
        printf("   -> %d ", temp->data);
        temp = temp->next;
    }

    printf("   -> NULL\n");
}

int main() {
    // Creating a Linked List with 5 nodes
    struct node* head = createNewNode(1);
    head->next = createNewNode(2);
    head->next->next = createNewNode(3);
    head->next->next->next = createNewNode(4);
    head->next->next->next->next = createNewNode(5);

    // Visualizing the Linked List
    visualizeLinkedList(head);

    return 0;
}
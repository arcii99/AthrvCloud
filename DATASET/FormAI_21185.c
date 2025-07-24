//FormAI DATASET v1.0 Category: Data structures visualization ; Style: innovative
#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* next;
};

/* Function to create a new node */
struct node* createNode(int data) {
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    newNode -> next = NULL;
    newNode -> data = data;
    return newNode;
}

/* Function to display the linked list */
void displayList(struct node* head) {
    struct node* current = head;
    printf("Linked List : ");
    while(current != NULL) {
        printf("%d -> ", current -> data);
        current = current -> next;
    }
    printf("NULL\n");
}

/* Main function */
int main() {

    // Initializing linked list
    struct node* head = createNode(1);
    head -> next = createNode(2);
    head -> next -> next = createNode(3);
    head -> next -> next -> next = createNode(4);
    head -> next -> next -> next -> next = createNode(5);


    // Displaying the linked list
    displayList(head);

    /* Output:
     * Linked List : 1 -> 2 -> 3 -> 4 -> 5 -> NULL
     */

    return 0;
}
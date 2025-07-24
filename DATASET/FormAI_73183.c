//FormAI DATASET v1.0 Category: Data structures visualization ; Style: configurable
#include <stdio.h>

// Define the structure for a person
typedef struct Person {
    char name[20];
    int age;
} Person;

// Define the structure for a node in a linked list
typedef struct Node {
    Person data;
    struct Node* next;
} Node;

// Define the functions for a linked list
void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%s, %d\n", current->data.name, current->data.age);
        current = current->next;
    }
}

void insertNode(Node** head, Person data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = (*head);
    (*head) = newNode;
}

int main() {
    // Create a linked list of people
    Node* head = NULL;
    insertNode(&head, (Person) {"Alice", 25});
    insertNode(&head, (Person) {"Bob", 30});
    insertNode(&head, (Person) {"Charlie", 20});

    // Print the linked list
    printf("List of people:\n");
    printList(head);

    return 0;
}
//FormAI DATASET v1.0 Category: Mailing list manager ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char* email;
    struct Node* next;
} Node;

Node* head;

void addEmail(char* email) {
    Node* temp = (Node*) malloc(sizeof(Node));
    temp->email = (char*) malloc(strlen(email) + 1);
    strcpy(temp->email, email);
    temp->next = head;
    head = temp;
}

void removeEmail(char* email) {
    Node* current = head;
    Node* previous = NULL;
    while (current != NULL) {
        if (strcmp(current->email, email) == 0) {
            if (previous == NULL)
                head = current->next;
            else
                previous->next = current->next;
            free(current->email);
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
}

void printList() {
    Node* temp = head;
    while (temp != NULL) {
        printf("%s\n", temp->email);
        temp = temp->next;
    }
}

int main() {
    head = NULL;

    addEmail("example1@gmail.com");
    addEmail("example2@yahoo.com");
    addEmail("example3@hotmail.com");
    addEmail("example4@aol.com");

    printf("Initial email list:\n");
    printList();

    printf("\nRemoving example2@yahoo.com from the list.\n");
    removeEmail("example2@yahoo.com");

    printf("\nUpdated email list:\n");
    printList();

    printf("\nAdding example5@gmail.com to the list.\n");
    addEmail("example5@gmail.com");

    printf("\nUpdated email list:\n");
    printList();

    return 0;
}
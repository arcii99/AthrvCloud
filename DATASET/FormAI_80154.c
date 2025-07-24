//FormAI DATASET v1.0 Category: Spam Detection System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024
#define SPAM_THRESHOLD 10

typedef struct node {
    char *word;
    int count;
    struct node *next;
} Node;

// A function to create a new node
Node* createNode(char *word, int count) {
    Node *newNode = (Node*) malloc(sizeof(Node));

    if(newNode == NULL) {
        printf("Error creating new node. Out of memory.\n");
        exit(0);
    }

    newNode->word = (char*) malloc(strlen(word) + 1);
    strcpy(newNode->word, word);

    newNode->count = count;

    newNode->next = NULL;

    return newNode;
}

// A function to insert a node at the end of the list
void insertNode(Node **headRef, char *word, int count) {
    Node *newNode = createNode(word, count);
    Node *lastNode = *headRef;

    // If the list is empty, set the head to be the new node
    if(lastNode == NULL) {
        *headRef = newNode;
        return;
    }

    // Otherwise, traverse the list to find the last node
    while(lastNode->next != NULL) {
        lastNode = lastNode->next;
    }

    // Insert the new node at the end of the list
    lastNode->next = newNode;
}

// A function to print the entire list
void printList(Node *head) {
    Node *currentNode = head;

    while(currentNode != NULL) {
        printf("%s: %d\n", currentNode->word, currentNode->count);

        currentNode = currentNode->next;
    }
}

int main() {
    int count = 0;
    char buffer[BUFFER_SIZE];
    Node *head = NULL;

    printf("Enter some text. Type \"quit\" to exit.\n");

    // Keep reading text until the user types "quit"
    while(1) {
        fgets(buffer, BUFFER_SIZE, stdin);

        // Remove the newline character from the end of the buffer
        buffer[strcspn(buffer, "\n")] = '\0';

        // If the user has typed "quit", stop reading text
        if(strcmp(buffer, "quit") == 0) {
            break;
        }

        // Split the buffer into words and count each occurrence
        char *word = strtok(buffer, " ");

        while(word != NULL) {
            // Ignore any words that are less than 3 characters long
            if(strlen(word) >= 3) {
                Node *currentNode = head;
                Node *prevNode = NULL;
                int found = 0;

                // Traverse the list to find the current word
                while(currentNode != NULL && !found) {
                    if(strcmp(currentNode->word, word) == 0) {
                        found = 1;
                    }
                    else {
                        prevNode = currentNode;
                        currentNode = currentNode->next;
                    }
                }

                // If the word is already in the list, increment its count
                if(found) {
                    currentNode->count++;
                }
                // Otherwise, add a new node to the end of the list
                else {
                    insertNode(&head, word, 1);
                }
            }

            // Get the next word in the buffer
            word = strtok(NULL, " ");
        }

        count++;

        // Print the current list every SPAM_THRESHOLD iterations
        if(count % SPAM_THRESHOLD == 0) {
            printf("SPAM DETECTION:\n");

            printList(head);

            printf("\n");

            // Reset the list
            Node *currentNode = head;
            Node *nextNode = NULL;

            while(currentNode != NULL) {
                nextNode = currentNode->next;
                free(currentNode);
                currentNode = nextNode;
            }

            head = NULL;
        }
    }

    return 0;
}
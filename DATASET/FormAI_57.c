//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Define a linked list data structure to store words and their frequency
typedef struct Node {
    char *word;
    int freq;
    struct Node *next;
} Node;

// Create a new Node with the given word and set frequency to 1
Node *createNode(char *word) {
    Node *new_node = malloc(sizeof(Node));
    new_node->word = word;
    new_node->freq = 1;
    new_node->next = NULL;
    return new_node;
}

// Free the memory used by the linked list
void freeList(Node *head) {
    Node *current = head;
    while (current != NULL) {
        Node *next = current->next;
        free(current->word);
        free(current);
        current = next;
    }
}

// Convert all characters in a string to lowercase
void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

int main() {
    printf("Welcome to the Happy Word Frequency Counter!\n\n");

    // Create a linked list to store words and their frequency
    Node *head = NULL;
    Node *current = NULL;

    // Read input from the user until they enter an empty line
    char line[1000];
    while (1) {
        printf("Enter a line of text (empty line to stop): ");
        fgets(line, 1000, stdin);

        // Exit loop if user entered an empty line
        if (line[0] == '\n') break;

        // Tokenize the line into words
        char *word = strtok(line, " \t\n");
        while (word != NULL) {
            // Convert word to lowercase
            toLowerCase(word);

            // Check if word is already in the linked list
            current = head;
            while (current != NULL) {
                if (strcmp(current->word, word) == 0) {
                    // Increment frequency if word is already in list
                    current->freq++;
                    break;
                }
                current = current->next;
            }

            // Create a new Node for the word if it isn't already in the list
            if (current == NULL) {
                Node *new_node = createNode(strdup(word));
                new_node->next = head;
                head = new_node;
            }

            // Tokenize the next word in the line
            word = strtok(NULL, " \t\n");
        }
    }

    // Print the word frequency counts
    printf("\nWord Frequency Counts:\n");
    current = head;
    while (current != NULL) {
        printf("'%s': %d\n", current->word, current->freq);
        current = current->next;
    }

    // Free the memory used by the linked list
    freeList(head);

    printf("\nThank you for using the Happy Word Frequency Counter!\n");

    return 0;
}
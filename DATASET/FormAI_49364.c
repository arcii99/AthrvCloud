//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_WORD_LENGTH 50 

// Node struct for a linked list
struct node {
    char word[MAX_WORD_LENGTH];
    int count;
    struct node *next;
};

// Function to add a new node to the linked list
void add_node(struct node **head_ref, char new_word[MAX_WORD_LENGTH]) {
    // Check if the linked list is empty
    if (*head_ref == NULL) {
        struct node *new_node = (struct node *) malloc(sizeof(struct node));
        strcpy(new_node->word, new_word);
        new_node->count = 1;
        new_node->next = NULL;
        *head_ref = new_node;
        return;
    }

    struct node *current_node = *head_ref;
    // Traverse the linked list to find if the word already exists
    while (current_node != NULL) {
        if (strcmp(current_node->word, new_word) == 0) {
            current_node->count++;
            return;
        }
        current_node = current_node->next;
    }

    // If the word does not exist, add it to the linked list
    struct node *new_node = (struct node *) malloc(sizeof(struct node));
    strcpy(new_node->word, new_word);
    new_node->count = 1;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

// Function to print the linked list
void print_list(struct node *head) {
    struct node *current_node = head;
    while (current_node != NULL) {
        printf("%s: %d\n", current_node->word, current_node->count);
        current_node = current_node->next;
    }
}

int main() {
    // Initialize variables
    char input[10000];
    struct node *head = NULL;
    // Prompt the user for input
    printf("Enter a string: ");
    fgets(input, 10000, stdin);
    // Tokenize the input string into words
    char *word = strtok(input, " .,!?\n");

    // Loop through all the words in the input string
    while (word != NULL) {
        add_node(&head, word);
        word = strtok(NULL, " .,!?\n");
    }

    // Print the word frequency count
    print_list(head);

    return 0;
}
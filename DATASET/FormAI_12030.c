//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define a linked list node structure to store word and its count
struct Node {
    char *word;
    int count;
    struct Node *next;
};

// Function to create a new node with given word and count
struct Node* newNode(char *word, int count) {
    struct Node *new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->word = (char*) malloc(strlen(word)+1);
    strcpy(new_node->word, word);
    new_node->count = count;
    new_node->next = NULL;
    return new_node;
}

// Function to insert a new node at the beginning of linked list
void insertNode(struct Node **head_ref, char *word, int count) {
    struct Node *new_node = newNode(word, count);
    new_node->next = *head_ref;
    *head_ref = new_node;
}

// Function to print the word frequency count
void printWordFrequency(struct Node *head) {
    struct Node *current = head;
    printf("--------------------------------------\n");
    printf("|    Word    |    Frequency    |\n");
    printf("--------------------------------------\n");
    while(current != NULL) {
        printf("|%-12s|%-16d|\n", current->word, current->count);
        current = current->next;
    }
    printf("--------------------------------------\n");
}

int main() {
    // Initialize the linked list head as NULL
    struct Node *head = NULL;

    // Prompt user for input text
    printf("Welcome to the Word Frequency Counter!\n\n");
    printf("Please enter your text:\n");
    char text[10000];
    fgets(text, 10000, stdin);

    // Tokenize the input text into words and count their frequency
    char *token = strtok(text, " ,.!?\n");
    while(token != NULL) {
        // Convert the word to lowercase and remove trailing punctuation
        int len = strlen(token);
        char last_char = token[len-1];
        while(!isalpha(last_char) && !isdigit(last_char)) {
            token[len-1] = '\0';
            len--;
            last_char = token[len-1];
        }
        for(int i=0; i<len; i++) {
            token[i] = tolower(token[i]);
        }

        // Check if the word is already present in the linked list
        struct Node *current = head;
        while(current != NULL) {
            if(strcmp(current->word, token) == 0) {
                current->count++;
                break;
            }
            current = current->next;
        }
        if(current == NULL) { // word not found in linked list
            // Insert the new word at the beginning of the linked list
            insertNode(&head, token, 1);
        }

        // Get the next word token
        token = strtok(NULL, " ,.!?\n");
    }

    // Print the word frequency count
    printWordFrequency(head);

    return 0;
}
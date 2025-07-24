//FormAI DATASET v1.0 Category: Spell checking ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define a linked list structure to store each word and its occurrence count
struct WordNode {
    char *word;
    int count;
    struct WordNode *next;
};

// Function to add a new word to the linked list
struct WordNode *addWord(struct WordNode *head, char *word) {
    struct WordNode *curr = head;

    // Convert word to lowercase for case-insensitive comparison
    for (int i = 0; word[i]; i++) {
        word[i] = tolower(word[i]);
    }

    // Search for the word in the linked list
    while (curr != NULL) {
        if (strcmp(curr->word, word) == 0) {
            // Word already exists, update its occurrence count
            curr->count++;
            return head;
        }
        curr = curr->next;
    }

    // Word doesn't exist in the linked list, create a new node
    struct WordNode *newNode = (struct WordNode *) malloc(sizeof(struct WordNode));
    newNode->word = word;
    newNode->count = 1;
    newNode->next = NULL;

    // Add the new node to the end of the linked list
    if (head == NULL) {
        head = newNode;
    } else {
        curr = head;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = newNode;
    }

    return head;
}

int main() {
    char text[1000];
    printf("Enter text to spell check:\n");
    fgets(text, 1000, stdin);

    // Tokenize the input string into words
    char *token, *delim = " .,:;!?-()\n";
    struct WordNode *head = NULL;
    token = strtok(text, delim);
    while (token != NULL) {
        // Remove leading and trailing whitespace from each word
        int i = 0;
        while (isspace(token[i])) {
            i++;
        }
        char *word = &token[i];
        int len = strlen(word);
        while (len > 0 && isspace(word[len-1])) {
            len--;
        }
        word[len] = '\0';

        // Check if the word contains any non-alphabetic characters
        int valid = 1;
        for (int j = 0; word[j]; j++) {
            if (!isalpha(word[j])) {
                valid = 0;
                break;
            }
        }

        // Add the word to the linked list if it is valid
        if (valid) {
            head = addWord(head, word);
        }

        // Get the next token
        token = strtok(NULL, delim);
    }

    // Print the words and their occurrence counts
    printf("Spell checking complete:\n");
    struct WordNode *curr = head;
    while (curr != NULL) {
        printf("%s: %d\n", curr->word, curr->count);
        curr = curr->next;
    }

    return 0;
}
//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1000

// A linked list to store each word found and its frequency
struct word_frequency {
    char word[MAX_LINE_LENGTH];
    int frequency;
    struct word_frequency *next;
};

typedef struct word_frequency word_frequency;

// Function to add a new node to the linked list or increment frequency if the word already exists
void add_word(word_frequency **head, char *word) {
    word_frequency *current = *head;

    while (current != NULL) {
        if (strcmp(current->word, word) == 0) {
            current->frequency++;
            return;
        }
        current = current->next;
    }

    word_frequency *new_word = (word_frequency *) malloc(sizeof(word_frequency));
    strcpy(new_word->word, word);
    new_word->frequency = 1;
    new_word->next = *head;
    *head = new_word;
}

// Function to print the linked list and free its memory
void print_word_frequency(word_frequency **head) {
    word_frequency *current = *head;

    while (current != NULL) {
        printf("%s: %d\n", current->word, current->frequency);
        word_frequency *temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    char line[MAX_LINE_LENGTH];
    word_frequency *word_list = NULL;

    while (fgets(line, MAX_LINE_LENGTH, stdin)) {
        char *token = strtok(line, " \t\n");

        while (token != NULL) {
            // Convert token to lowercase
            for (int i = 0; token[i]; i++)
                token[i] = tolower(token[i]);

            // Add the word to the linked list or increment its frequency
            add_word(&word_list, token);

            token = strtok(NULL, " \t\n");
        }
    }

    // Print the word frequency list and free its memory
    print_word_frequency(&word_list);

    return 0;
}
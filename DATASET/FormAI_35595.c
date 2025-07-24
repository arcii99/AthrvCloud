//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LEN 50

typedef struct node {
    char word[MAX_WORD_LEN];
    int frequency;
    struct node *next;
} node;

node *create_node(char *word) {
    node *new_node = (node*) malloc(sizeof(node));
    strcpy(new_node->word, word);
    new_node->frequency = 1;
    new_node->next = NULL;
    return new_node;
}

void insert_after(node *prev_node, node *new_node) {
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

void add_word(node **head, char *word) {
    if (*head == NULL) {
        *head = create_node(word);
    }
    else {
        node *current_node = *head;
        while (current_node != NULL) {
            if (strcmp(current_node->word, word) == 0) {
                current_node->frequency++;
                return;
            }
            current_node = current_node->next;
        }
        // word not found, create new node
        node *new_node = create_node(word);
        insert_after(*head, new_node);
    }
}

void print_frequencies(node *head) {
    node *current_node = head;
    while (current_node != NULL) {
        printf("%s: %d\n", current_node->word, current_node->frequency);
        current_node = current_node->next;
    }
}

int main() {

    char input_string[] = "A cat and a dog were both hungry. The cat ate a fish, and the dog ate a bone. Then the cat slept and the dog played.";
    char *word;
    node *head = NULL;

    word = strtok(input_string, " ,.-");
    while (word != NULL) {
        for (int i = 0; i < strlen(word); i++) {
            word[i] = tolower(word[i]);  // convert word to all lowercase
        }
        add_word(&head, word);
        word = strtok(NULL, " ,.-");
    }

    print_frequencies(head);

    return 0;
}
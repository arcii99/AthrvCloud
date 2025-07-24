//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50

typedef struct word_node {
    char word[MAX_WORD_LENGTH];
    int frequency;
    struct word_node *next;
} WordNode;

void add_word(WordNode **word_list, char *new_word) {
    // Check if the word is already in the list
    WordNode *cur_node = *word_list;
    while (cur_node != NULL) {
        if (strcmp(cur_node->word, new_word) == 0) {
            cur_node->frequency++;
            return;
        }
        cur_node = cur_node->next;
    }

    // Add the new word to the list
    WordNode *new_node = malloc(sizeof(WordNode));
    if (new_node == NULL) {
        printf("Error: Out of memory\n");
        return;
    }

    strcpy(new_node->word, new_word);
    new_node->frequency = 1;
    new_node->next = *word_list;
    *word_list = new_node;
}

void strip_punc(char *word) {
    int len = strlen(word);
    int i, index = 0;

    for (i = 0; i < len; i++) {
        if (isalpha(word[i])) {
            word[index++] = tolower(word[i]);
        }
    }
    word[index] = '\0';
}

void update_word_list(WordNode **word_list, char *line) {
    char *word;
    char *delim = " \t\n\r\f\v";
    word = strtok(line, delim);
    while (word != NULL) {
        strip_punc(word);
        if (strlen(word) > 0) {
            add_word(word_list, word);
        }
        word = strtok(NULL, delim);
    }
}

void print_word_list(WordNode *word_list) {
    WordNode *cur_node = word_list;
    while (cur_node != NULL) {
        printf("%s: %d\n", cur_node->word, cur_node->frequency);
        cur_node = cur_node->next;
    }
}

int main() {
    WordNode *word_list = NULL;
    char line[1024];

    while (fgets(line, 1024, stdin)) {
        update_word_list(&word_list, line);
    }

    print_word_list(word_list);

    return 0;
}
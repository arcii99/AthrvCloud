//FormAI DATASET v1.0 Category: Spell checking ; Style: standalone
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 50
#define MAX_LINE_LENGTH 1000
#define DICTIONARY "dictionary.txt"

typedef struct node {
    char word[MAX_WORD_LENGTH];
    struct node *next;
} node;

int check_dictionary(char *word, node **dict) {
    node *curr = dict[(tolower(word[0]) - 'a')];

    while (curr != NULL) {
        if (strcmp(curr->word, word) == 0)
            return 1;
        curr = curr->next;
    }

    return 0;
}

void addToDictionary(char *word, node **dict) {
    int index = tolower(word[0]) - 'a';
    node *new_node = malloc(sizeof(node));
    strcpy(new_node->word, word);
    new_node->next = dict[index];
    dict[index] = new_node;
}

void load_dictionary(char *filename, node **dict) {
    FILE *fp = fopen(filename, "r");
    char word[MAX_WORD_LENGTH];

    while (!feof(fp)) {
        fscanf(fp, "%s", word);
        addToDictionary(word, dict);
    }

    fclose(fp);
}

int main() {
    node *dict[26];
    for (int i = 0; i < 26; ++i)
        dict[i] = NULL;

    load_dictionary(DICTIONARY, dict);

    char line[MAX_LINE_LENGTH];
    printf("Enter a line of text: ");
    fgets(line, MAX_LINE_LENGTH, stdin);

    char *token = strtok(line, " ,.\n");

    while (token != NULL) {
        if (!check_dictionary(token, dict))
            printf("Misspelled word: %s\n", token);

        token = strtok(NULL, " ,.\n");
    }

    return 0;
}
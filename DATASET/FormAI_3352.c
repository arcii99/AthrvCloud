//FormAI DATASET v1.0 Category: Spell checking ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LEN 50
#define HASHTABLE_SIZE 50000

typedef struct node {
    char word[MAX_WORD_LEN];
    struct node *next;
} Node;

int hash(char *word)
{
    int h = 0;
    for (int i = 0; i < strlen(word); i++) {
        h += (int)word[i];
    }
    return h % HASHTABLE_SIZE;
}

void add_word(Node **hashtable, char *word)
{
    int h = hash(word);
    if (hashtable[h] == NULL) {
        Node *new_node = malloc(sizeof(Node));
        strncpy(new_node->word, word, MAX_WORD_LEN);
        new_node->next = NULL;
        hashtable[h] = new_node;
    } else {
        Node *current = hashtable[h];
        while (current->next != NULL) {
            current = current->next;
        }
        Node *new_node = malloc(sizeof(Node));
        strncpy(new_node->word, word, MAX_WORD_LEN);
        new_node->next = NULL;
        current->next = new_node;
    }
}

int is_word_in_dictionary(Node **hashtable, char *word)
{
    int h = hash(word);
    Node *current = hashtable[h];
    while (current != NULL) {
        if (strcmp(current->word, word) == 0) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}

void free_hashtable(Node **hashtable)
{
    for (int i = 0; i < HASHTABLE_SIZE; i++) {
        Node *current = hashtable[i];
        while (current != NULL) {
            Node *next = current->next;
            free(current);
            current = next;
        }
    }
}

void spell_check_file(Node **hashtable, char *filename)
{
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }
    char current_word[MAX_WORD_LEN];
    int line_num = 1;
    int word_num = 1;
    while (fscanf(fp, "%s", current_word) != EOF) {
        if (!is_word_in_dictionary(hashtable, current_word)) {
            printf("Line %d, word %d: %s is not in the dictionary\n", line_num, word_num, current_word);
        }
        if (current_word[strlen(current_word)-1] == '\n') {
            line_num++;
            word_num = 1;
        } else {
            word_num++;
        }
    }
    fclose(fp);
}

int main(int argc, char *argv[])
{
    if (argc != 3) {
        printf("Usage: %s dictionary_file input_file\n", argv[0]);
        exit(1);
    }
    Node **hashtable = calloc(HASHTABLE_SIZE, sizeof(Node *));
    FILE *dict_file = fopen(argv[1], "r");
    if (dict_file == NULL) {
        printf("Error opening dictionary file %s\n", argv[1]);
        exit(1);
    }
    char current_word[MAX_WORD_LEN];
    while (fscanf(dict_file, "%s", current_word) != EOF) {
        add_word(hashtable, current_word);
    }
    fclose(dict_file);
    spell_check_file(hashtable, argv[2]);
    free_hashtable(hashtable);
    return 0;
}
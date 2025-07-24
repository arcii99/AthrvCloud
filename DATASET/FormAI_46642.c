//FormAI DATASET v1.0 Category: Spell checking ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define HASH_SIZE 10000
#define MAX_WORD_LEN 50

typedef struct node {
    char *word;
    struct node *next;
} Node;

int hash(char *s) {
    unsigned long hashval;
    for (hashval = 0; *s != '\0'; s++)
        hashval = *s + 31 * hashval;
    return hashval % HASH_SIZE;
}

void insert(Node **table, char *word) {
    int h = hash(word);
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->word = strdup(word);
    new_node->next = table[h];
    table[h] = new_node;
}

int lookup(Node **table, char *word) {
    int h = hash(word);
    Node *p = table[h];
    while (p != NULL) {
        if (strcmp(p->word, word) == 0)
            return 1;
        p = p->next;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <dictionary file> <text file>\n", argv[0]);
        exit(1);
    }
    Node *table[HASH_SIZE];
    for (int i = 0; i < HASH_SIZE; i++)
        table[i] = NULL;
    FILE *dict_file = fopen(argv[1], "r");
    if (dict_file == NULL) {
        fprintf(stderr, "Cannot open dictionary file\n");
        exit(1);
    }
    char dict_word[MAX_WORD_LEN];
    while (fscanf(dict_file, "%s", dict_word) == 1)
        insert(table, dict_word);
    fclose(dict_file);
    FILE *text_file = fopen(argv[2], "r");
    if (text_file == NULL) {
        fprintf(stderr, "Cannot open text file\n");
        exit(1);
    }
    char text_word[MAX_WORD_LEN];
    int line = 1, col = 1, word_num = 0, misspelled = 0;
    while (fscanf(text_file, "%s", text_word) == 1) {
        if (!isalpha(text_word[0]))
            continue;  // not a word
        char word[MAX_WORD_LEN];
        int i, j;
        for (i = 0, j = 0; text_word[i] != '\0'; i++, j++) {
            if (isupper(text_word[i]))
                word[j] = tolower(text_word[i]);
            else
                word[j] = text_word[i];
        }
        word[j] = '\0';
        if (!lookup(table, word)) {
            printf("Misspelled word: %s at line %d, col %d, word %d\n",
                   text_word, line, col, word_num);
            misspelled = 1;
        }
        for (i = 0; word[i] != '\0'; i++) {
            if (word[i] == '\n') {
                line++;
                col = 1;
            } else {
                col++;
            }
        }
        word_num++;
    }
    if (!misspelled)
        printf("No misspelled words found\n");
    fclose(text_file);
    return 0;
}
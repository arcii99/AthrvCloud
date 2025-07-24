//FormAI DATASET v1.0 Category: Spell checking ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_SIZE 50

struct node {
    char word[MAX_WORD_SIZE];
    struct node *next;
};

struct hash_table {
    int size;
    struct node **table;
};

void create_table(struct hash_table *ht, int size) {
    ht->size = size;
    ht->table = calloc(size, sizeof(struct node *));
}

void insert_word(struct hash_table *ht, char *word) {
    int idx = 0;
    struct node *tmp = NULL;
    struct node *ptr = NULL;

    idx = strlen(word) % ht->size;

    tmp = ht->table[idx];
    while (tmp) {
        if (strcmp(tmp->word, word) == 0) {
            return;
        }
        ptr = tmp;
        tmp = tmp->next;
    }

    tmp = calloc(1, sizeof(struct node));
    strncpy(tmp->word, word, MAX_WORD_SIZE);
    if (ptr) {
        ptr->next = tmp;
    } else {
        ht->table[idx] = tmp;
    }
}

bool check_word(struct hash_table *ht, char *word) {
    int idx = 0;
    struct node *tmp = NULL;

    idx = strlen(word) % ht->size;

    tmp = ht->table[idx];
    while (tmp) {
        if (strcmp(tmp->word, word) == 0) {
            return true;
        }
        tmp = tmp->next;
    }
    return false;
}

void print_error(char *word) {
    printf("\nUnknown word: %s\n", word);
}

void spell_check(char *filename, struct hash_table *ht) {
    FILE *fptr = NULL;
    char buffer[MAX_WORD_SIZE];
    char ch;

    fptr = fopen(filename, "r");
    if (fptr == NULL) {
        printf("Unable to open the file %s\n", filename);
        return;
    }

    memset(buffer, 0, MAX_WORD_SIZE);

    ch = fgetc(fptr);
    while (ch != EOF) {
        if (isalpha(ch)) {
            strncat(buffer, &ch, 1);
        } else {
            if (strlen(buffer) > 0) {
                if (!check_word(ht, buffer)) {
                    print_error(buffer);
                }
                memset(buffer, 0, MAX_WORD_SIZE);
            }
        }
        ch = fgetc(fptr);
    }

    fclose(fptr);
}

int main() {
    char *filename = "sample.txt";
    struct hash_table ht;

    create_table(&ht, 100);

    insert_word(&ht, "hello");
    insert_word(&ht, "world");
    insert_word(&ht, "this");
    insert_word(&ht, "is");
    insert_word(&ht, "a");
    insert_word(&ht, "test");

    spell_check(filename, &ht);
    return 0;
}
//FormAI DATASET v1.0 Category: Text processing ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// We'll create a program that processes a text file and extracts all the unique words from it
// We'll use a hash table to store the words we encounter, and a dynamic array to keep track of the words in order

#define MAX_WORD_LENGTH 256
#define HASH_TABLE_SIZE 1024

typedef struct WordNode {
    char word[MAX_WORD_LENGTH];
    struct WordNode *next;
} WordNode;

typedef struct HashTable {
    WordNode *buckets[HASH_TABLE_SIZE];
} HashTable;

int hash(char *s) {
    int hash = 1;
    for (int i = 0; i < strlen(s); i++) {
        hash = (hash * 31 + s[i]) % HASH_TABLE_SIZE;
    }
    return hash;
}

void initHashTable(HashTable *table) {
    memset(table->buckets, 0, sizeof(WordNode*) * HASH_TABLE_SIZE);
}

void insertHashTable(HashTable *table, char *word) {
    int h = hash(word);
    WordNode *node = table->buckets[h];
    while (node) {
        if (strcmp(node->word, word) == 0) {
            return; // already exists
        }
        node = node->next;
    }
    node = (WordNode*) malloc(sizeof(WordNode));
    strcpy(node->word, word);
    node->next = table->buckets[h];
    table->buckets[h] = node;
}

void freeHashTable(HashTable *table) {
    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
        WordNode *node = table->buckets[i];
        while (node) {
            WordNode *next = node->next;
            free(node);
            node = next;
        }
        table->buckets[i] = NULL;
    }
}

typedef struct WordList {
    char **words;
    int count;
    int capacity;
} WordList;

void initWordList(WordList *list) {
    list->words = NULL;
    list->count = 0;
    list->capacity = 0;
}

void addWordToList(WordList *list, char *word) {
    if (list->count == list->capacity) {
        list->words = (char**) realloc(list->words, sizeof(char*) * (list->capacity + 10));
        list->capacity += 10;
    }
    list->words[list->count++] = strdup(word);
}

void freeWordList(WordList *list) {
    for (int i = 0; i < list->count; i++) {
        free(list->words[i]);
    }
    free(list->words);
}

void readTextFile(char *filename, HashTable *table, WordList *list) {
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        printf("Failed to open file %s\n", filename);
        return;
    }
    char word[MAX_WORD_LENGTH];
    while (fscanf(fp, "%s", word) == 1) {
        insertHashTable(table, word);
    }
    fclose(fp);
    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
        WordNode *node = table->buckets[i];
        while (node) {
            addWordToList(list, node->word);
            node = node->next;
        }
    }
}

int main() {
    HashTable table;
    initHashTable(&table);
    WordList list;
    initWordList(&list);
    readTextFile("input.txt", &table, &list);
    for (int i = 0; i < list.count; i++) {
        printf("%s\n", list.words[i]);
    }
    freeWordList(&list);
    freeHashTable(&table);
    return 0;
}
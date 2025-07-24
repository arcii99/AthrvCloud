//FormAI DATASET v1.0 Category: Spell checking ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_SIZE 100 // maximum size of a word
#define MAX_LINE_SIZE 1000 // maximum size of a sentence/line
#define MAX_DICT_SIZE 10000 // maximum size of dictionary

// Node structure for storing words in the dictionary
typedef struct Node {
    char word[MAX_WORD_SIZE];
    struct Node *next;
} Node;

// Hash table structure for storing words in the dictionary
typedef struct HashTable {
    Node *entries[MAX_DICT_SIZE];
} HashTable;

// Hash function to calculate the index for a given word
int hash(char *word) {
    unsigned long hash = 5381;
    int c;
    while ((c = *word++)) {
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    }
    return hash % MAX_DICT_SIZE;
}

// Function to add a word to the dictionary
void addToDict(HashTable *dict, char *word) {
    int index = hash(word);
    Node *head = dict->entries[index];
    Node *curr = head;
    while (curr != NULL) {
        if (strcmp(curr->word, word) == 0) {
            return; // word already in dictionary
        }
        curr = curr->next;
    }
    Node *newNode = malloc(sizeof(Node));
    strcpy(newNode->word, word);
    newNode->next = head;
    dict->entries[index] = newNode;
}

// Function to check if a word is in the dictionary
int isInDict(HashTable *dict, char *word) {
    int index = hash(word);
    Node *head = dict->entries[index];
    Node *curr = head;
    while (curr != NULL) {
        if (strcmp(curr->word, word) == 0) {
            return 1; // word found in dictionary
        }
        curr = curr->next;
    }
    return 0; // word not in dictionary
}

// Main function to check spelling of words in a sentence
void checkSpelling(char *line, HashTable *dict) {
    char *word;
    char *delimiters = " ,.!?\n";
    word = strtok(line, delimiters);
    while (word != NULL) {
        if (!isInDict(dict, word)) {
            printf("Misspelled word: %s\n", word);
        }
        word = strtok(NULL, delimiters);
    }
}

int main() {
    HashTable dict;
    memset(dict.entries, 0, sizeof(dict.entries)); // initialize hash table to empty
    FILE *dictFile = fopen("dictionary.txt", "r");
    if (dictFile == NULL) {
        printf("Error: Failed to open dictionary file\n");
        return 1;
    }
    char line[MAX_LINE_SIZE];
    char *word;
    char *delimiters = " ,.!?\n";
    while (fgets(line, MAX_LINE_SIZE, dictFile) != NULL) {
        word = strtok(line, delimiters);
        while (word != NULL) {
            addToDict(&dict, word);
            word = strtok(NULL, delimiters);
        }
    }
    fclose(dictFile); // close dictionary file
    printf("Dictionary loaded with %d words\n", MAX_DICT_SIZE);
    char sentence[MAX_LINE_SIZE];
    printf("Enter a sentence to check spelling:\n> ");
    fgets(sentence, MAX_LINE_SIZE, stdin);
    checkSpelling(sentence, &dict);
    return 0;
}
//FormAI DATASET v1.0 Category: Spell checking ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASH_TABLE_SIZE 1024

typedef struct hashtable_entry_t {
    char* key;
    struct hashtable_entry_t* next;
} hashtable_entry_t;

typedef struct hashtable_t {
    hashtable_entry_t* buckets[HASH_TABLE_SIZE];
} hashtable_t;

// Function to compute a hash code for a string
unsigned int hash(char* str) {
    unsigned int hashval = 0;
    for (int i = 0; i < strlen(str); i++) {
        hashval = hashval * 37 + str[i];
    }
    return hashval % HASH_TABLE_SIZE;
}

// Function to insert a key-value pair into the hashtable
void hashtable_put(hashtable_t* ht, char* key) {
    unsigned int hashval = hash(key);
    hashtable_entry_t* entry = (hashtable_entry_t*)malloc(sizeof(hashtable_entry_t));
    entry->key = strdup(key);
    entry->next = ht->buckets[hashval];
    ht->buckets[hashval] = entry;
}

// Function to check if a key exists in the hashtable
int hashtable_contains(hashtable_t* ht, char* key) {
    unsigned int hashval = hash(key);
    hashtable_entry_t* entry = ht->buckets[hashval];
    while (entry != NULL) {
        if (strcmp(entry->key, key) == 0) {
            return 1;
        }
        entry = entry->next;
    }
    return 0;
}

int main() {
    // Create a hashtable to store the dictionary of correctly spelled words
    hashtable_t dictionary;
    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
        dictionary.buckets[i] = NULL;
    }
    // Load the dictionary from a file (one word per line)
    FILE* dictionary_file = fopen("dictionary.txt", "r");
    char buffer[100];
    while (fgets(buffer, 100, dictionary_file) != NULL) {
        buffer[strcspn(buffer, "\r\n")] = '\0'; // remove trailing newline
        hashtable_put(&dictionary, buffer);
    }
    fclose(dictionary_file);
    // Prompt the user for input and check each word against the dictionary
    char input[1000];
    printf("Enter text to spell check:\n");
    fgets(input, 1000, stdin);
    char* word = strtok(input, " ,;:\t\r\n");
    while (word != NULL) {
        if (!hashtable_contains(&dictionary, word)) {
            printf("Unknown word: %s\n", word);
        }
        word = strtok(NULL, " ,;:\t\r\n");
    }
    return 0;
}
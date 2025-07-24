//FormAI DATASET v1.0 Category: Text processing ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of words in our dictionary
#define MAX_WORDS 1000

// Define the maximum length of each word
#define MAX_WORD_LENGTH 100

// Define the size of our hash table
#define HASH_TABLE_SIZE 1000

// Define a struct to store a word and its frequency
typedef struct WordFrequency {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

// Define a struct to represent a node in our hash table (linked list)
typedef struct HashNode {
    WordFrequency data;
    struct HashNode* next;
} HashNode;

// Define our hash table (array of linked lists)
HashNode* hashTable[HASH_TABLE_SIZE];

// Define a function to calculate the hash value of a given key (i.e. a word)
int getHash(char* key) {
    int hash = 0;
    int i = 0;
    while (key[i] != '\0') {
        hash = (hash * 31 + key[i]) % HASH_TABLE_SIZE;
        i++;
    }
    return hash;
}

// Define a function to insert a word into our dictionary
void insertWord(char* word) {
    // Calculate the hash value of the word
    int hash = getHash(word);

    // Search for the word in the linked list at the corresponding hash value
    HashNode* currentNode = hashTable[hash];
    while (currentNode != NULL) {
        if (strcmp(currentNode->data.word, word) == 0) {
            // The word already exists in our dictionary, so just increment its frequency
            currentNode->data.frequency++;
            return;
        }
        currentNode = currentNode->next;
    }

    // The word does not yet exist in our dictionary, so create a new node for it
    HashNode* newNode = (HashNode*)malloc(sizeof(HashNode));
    strncpy(newNode->data.word, word, MAX_WORD_LENGTH);
    newNode->data.frequency = 1;
    newNode->next = NULL;

    // Insert the new node at the head of the linked list
    newNode->next = hashTable[hash];
    hashTable[hash] = newNode;
}

// Define a function to print the contents of our dictionary
void printDictionary() {
    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
        HashNode* currentNode = hashTable[i];
        while (currentNode != NULL) {
            printf("%s: %d\n", currentNode->data.word, currentNode->data.frequency);
            currentNode = currentNode->next;
        }
    }
}

// Define the main function
int main() {
    // Initialize our hash table to contain NULL pointers
    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
        hashTable[i] = NULL;
    }

    // Create a buffer to read input text into
    char buffer[MAX_WORD_LENGTH];

    // Read text from standard input until no more input is available
    while (scanf("%s", buffer) != EOF) {
        // Convert the text to lower case
        for (int i = 0; buffer[i]; i++) {
            buffer[i] = tolower(buffer[i]);
        }

        // Remove any punctuation marks from the text
        int j = 0;
        for (int i = 0; buffer[i]; i++) {
            if (buffer[i] >= 'a' && buffer[i] <= 'z') {
                buffer[j] = buffer[i];
                j++;
            }
        }
        buffer[j] = '\0';

        // Insert the cleaned-up word into our dictionary
        if (strcmp(buffer, "") != 0) {
            insertWord(buffer);
        }
    }

    // Print the contents of our dictionary
    printDictionary();

    return 0;
}
//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LEN 50
#define MAX_NUM_WORDS 10000

// Node structure to store each word and its frequency
struct Node {
    char word[MAX_WORD_LEN + 1];
    int count;
    struct Node* next;
};

// Hash table to store nodes
struct Node* hashtable[MAX_NUM_WORDS] = { NULL };

// Global variables
int num_words = 0; // total number of words
int num_unique_words = 0; // number of unique words

// Hash function to calculate index from the given word using djb2 algorithm
unsigned long hash(char* str) {
    unsigned long hash = 5381;
    int c;
    while ((c = *str++))
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    return hash % MAX_NUM_WORDS;
}

// Search for a node in the hashtable
struct Node* lookup(char* word) {
    unsigned long index = hash(word);
    struct Node* ptr = hashtable[index];
    while (ptr != NULL) {
        if (strcmp(ptr->word, word) == 0)
            return ptr;
        ptr = ptr->next;
    }
    return ptr; // return NULL if not found
}

// Insert a node into hashtable
void insert(char* word) {
    // search if node already exists
    struct Node* ptr = lookup(word);
    if (ptr != NULL) {
        // increment count if node already exists
        ptr->count++;
    }
    else {
        // create a new node and insert into hashtable
        struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
        strcpy(newnode->word, word);
        newnode->count = 1;
        newnode->next = hashtable[hash(word)];
        hashtable[hash(word)] = newnode;
        num_unique_words++;
    }
    num_words++;
}

// Free the memory allocated to the nodes
void cleanup() {
    for (int i = 0; i < MAX_NUM_WORDS; i++) {
        struct Node* ptr = hashtable[i];
        while (ptr != NULL) {
            struct Node* temp = ptr;
            ptr = ptr->next;
            free(temp);
        }
    }
}

int main() {
    printf("Enter a sentence: ");
    char sentence[MAX_WORD_LEN*MAX_NUM_WORDS];
    fgets(sentence, MAX_WORD_LEN*MAX_NUM_WORDS, stdin);

    // Split the sentence into words and insert into hashtable
    char* tok = strtok(sentence, " \n");
    while (tok != NULL) {
        // Convert all characters to lowercase for case-insensitive comparison
        for (int i = 0; tok[i]; i++)
            tok[i] = tolower(tok[i]);

        // Remove punctuations from the word
        size_t len = strlen(tok);
        char* end = tok + len;
        while (--end >= tok && ispunct(*end)) {
            *end = '\0';
            len--;
        }
        while (ispunct(*tok)) {
            tok++;
            len--;
        }

        if (len > 0)
            insert(tok);
        tok = strtok(NULL, " \n");
    }

    // Print the word frequency table sorted by frequency in descending order
    printf("%-20s%s\n", "Word", "Frequency");
    printf("--------------------------------\n");
    while (num_unique_words > 0) {
        int max_count = 0;
        struct Node* max_node = NULL;
        for (int i = 0; i < MAX_NUM_WORDS; i++) {
            struct Node* ptr = hashtable[i];
            while (ptr != NULL) {
                if (ptr->count > max_count) {
                    max_count = ptr->count;
                    max_node = ptr;
                }
                ptr = ptr->next;
            }
        }
        printf("%-20s%d\n", max_node->word, max_node->count);
        max_node->count = -1; // mark node as visited
        num_unique_words--;
    }

    printf("Total number of words: %d\n", num_words);
    printf("Total number of unique words: %d\n", num_unique_words);

    // Free the memory allocated to the nodes
    cleanup();

    return 0;
}
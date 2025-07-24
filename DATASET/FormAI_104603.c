//FormAI DATASET v1.0 Category: Spell checking ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 50
#define DICTIONARY_FILE_NAME "dictionary.txt"

// Node definition for our dictionary hash table
typedef struct node {
    char word[MAX_WORD_LENGTH];
    struct node* next;
} Node;

// Hash function that converts a string to an index in the hash table
int hash(char* word) {
    int sum = 0;
    while (*word != '\0') {
        sum += (int)(*word);
        word++;
    }
    return sum % 1000;
}

// Function that initializes a new node
Node* create_node(char* word) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    strcpy(new_node->word, word);
    new_node->next = NULL;
    return new_node;
}

// Function that inserts a new word into the hash table
void insert_word(Node** hash_table, char* word) {
    int index = hash(word);
    Node* node = create_node(word);
    if (hash_table[index] == NULL) {
        hash_table[index] = node;
    } else {
        Node* current = hash_table[index];
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = node;
    }
}

// Function that loads the dictionary file and populates the hash table
void load_dictionary_file(Node** hash_table) {
    FILE* file;
    char* line = NULL;
    size_t len = 0;
    ssize_t read;
    file = fopen(DICTIONARY_FILE_NAME, "r");
    if (file == NULL) {
        printf("Failed to open dictionary file\n");
        exit(EXIT_FAILURE);
    }
    while ((read = getline(&line, &len, file)) != -1) {
        line[strcspn(line, "\r\n")] = '\0'; // Remove newline characters
        insert_word(hash_table, line);
    }
    fclose(file);
    if (line) {
        free(line);
    }
}

// Function that checks if a word is spelled correctly
int is_spelled_correctly(Node** hash_table, char* word) {
    int index = hash(word);
    Node* current = hash_table[index];
    while (current != NULL) {
        if (strcmp(current->word, word) == 0) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}

int main() {
    Node* hash_table[1000];
    memset(hash_table, 0, sizeof(hash_table));
    load_dictionary_file(hash_table);
    printf("Spell checker ready to go!\n");

    while (1) {
        printf("Enter a word to spell check (type 'exit' to quit): ");
        char input[MAX_WORD_LENGTH];
        fgets(input, MAX_WORD_LENGTH, stdin);
        input[strcspn(input, "\r\n")] = '\0'; // Remove newline characters
        if (strcasecmp(input, "exit") == 0) {
            break;
        }
        if (is_spelled_correctly(hash_table, input)) {
            printf("Correct spelling!\n");
        } else {
            printf("Incorrect spelling\n");
        }
    }

    return 0;
}
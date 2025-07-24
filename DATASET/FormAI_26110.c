//FormAI DATASET v1.0 Category: Spell checking ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define DICT_SIZE 50000 // size of the dictionary array

// hash function for the dictionary
unsigned long hash(const char *str) {
    unsigned long hash = 5381;
    int c;

    while ((c = *str++))
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash;
}

// struct representing a word entry in the dictionary
typedef struct word_entry_t { 
    char word[MAX_WORD_LENGTH];
    struct word_entry_t *next;
} word_entry;

// function to insert a word into the dictionary
void insert_word(word_entry** dict, const char* word) {
    // calculate the hash value of the word
    unsigned long hash_value = hash(word) % DICT_SIZE;

    // create a new word entry
    word_entry* new_word = (word_entry*) malloc(sizeof(word_entry));
    strcpy(new_word->word, word);
    new_word->next = NULL;

    // insert the word at the head of the linked list at the corresponding index
    if (dict[hash_value] == NULL) {
        dict[hash_value] = new_word;
    } else {
        new_word->next = dict[hash_value];
        dict[hash_value] = new_word;
    }
}

// function to check if a word is spelled correctly
int check_word(word_entry** dict, const char* word) {
    // calculate the hash value of the word
    unsigned long hash_value = hash(word) % DICT_SIZE;

    // iterate through the linked list at the corresponding index to find the word
    word_entry* current_word = dict[hash_value];
    while (current_word != NULL) {
        if (strcmp(current_word->word, word) == 0) {
            return 1;
        }
        current_word = current_word->next;
    }

    return 0;
}

int main() {
    // initialize the dictionary array
    word_entry* dict[DICT_SIZE];
    for (int i = 0; i < DICT_SIZE; i++) {
        dict[i] = NULL;
    }

    // read the dictionary from file
    FILE *dict_file = fopen("dictionary.txt", "r");
    if (dict_file == NULL) {
        printf("Error: Could not open dictionary file.\n");
        exit(1);
    }
    char dict_word[MAX_WORD_LENGTH];
    while (fgets(dict_word, MAX_WORD_LENGTH, dict_file) != NULL) {
        // remove the newline character from the end of the word
        if (dict_word[strlen(dict_word)-1] == '\n') {
            dict_word[strlen(dict_word)-1] = '\0';
        }
        insert_word(dict, dict_word);
    }
    fclose(dict_file);

    // read input from file
    FILE *input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        printf("Error: Could not open input file.\n");
        exit(1);
    }
    char input_word[MAX_WORD_LENGTH];
    while (fscanf(input_file, "%s", input_word) != EOF) {
        // remove any punctuation from the word
        int len = strlen(input_word);
        for (int i = 0; i < len; i++) {
            if (!isalpha(input_word[i])) {
                input_word[i] = '\0';
                break;
            }
            input_word[i] = tolower(input_word[i]);
        }

        // check if the word is spelled correctly and output the result
        if (check_word(dict, input_word)) {
            printf("%s is spelled correctly.\n", input_word);
        } else {
            printf("%s is misspelled.\n", input_word);
        }
    }
    fclose(input_file);

    return 0;
}
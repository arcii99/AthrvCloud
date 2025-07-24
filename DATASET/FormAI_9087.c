//FormAI DATASET v1.0 Category: Spell checking ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define MAX_DICT_WORDS 150000

/* Node structure for the linked list */
struct Node {
    char word[MAX_WORD_LENGTH];
    struct Node* next;
};

/* Hash table size */
#define SIZE 65536
/* Hash table array of linked lists */
struct Node* hash_table[SIZE];

/* Hash function. It returns an index between 0 and SIZE-1 */
unsigned int hash(char* word) {
    unsigned int hashval = 0;
    for (; *word != '\0'; word++)
        hashval = *word + 31*hashval;
    return hashval % SIZE;
}

/* Add a new word to the dictionary */
void add_word(char* word) {
    /* Allocate memory for a new node */
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    /* Copy the word into the node */
    strcpy(new_node->word, word);
    /* Compute the hash index */
    unsigned int index = hash(new_node->word);
    /* Insert the node at the beginning of the list */
    new_node->next = hash_table[index];
    hash_table[index] = new_node;
}

/* Load the dictionary from a file */
int load_dict(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        return 0;
    }
    char word[MAX_WORD_LENGTH];
    int count = 0;
    while (fscanf(file, "%s", word) != EOF) {
        add_word(word);
        count++;
    }
    fclose(file);
    return count;
}

/* Check if a word is correctly spelled */
int check_word(char* word) {
    /* Convert the word to lowercase */
    for (int i = 0; word[i]; i++) {
        word[i] = tolower(word[i]);
    }
    /* Compute the hash index */
    unsigned int index = hash(word);
    /* Search for the word in the list */
    struct Node* node = hash_table[index];
    while (node != NULL) {
        if (strcmp(node->word, word) == 0) {
            return 1;
        }
        node = node->next;
    }
    return 0;
}

/* Check a text file for spelling errors */
void spell_check(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Could not open file %s", filename);
        return;
    }
    char word[MAX_WORD_LENGTH];
    int line_number = 1;
    while (fgets(word, MAX_WORD_LENGTH, file)) {
        char* start = word;
        char* end = strpbrk(start, " \t\n");
        while (end != NULL) {
            *end = '\0';
            if (!check_word(start)) {
                printf("Error: word '%s' on line %d is misspelled\n", start, line_number);
            }
            start = end + 1;
            end = strpbrk(start, " \t\n");
        }
        if (*start != '\0') {
            if (!check_word(start)) {
                printf("Error: word '%s' on line %d is misspelled\n", start, line_number);
            }
        }
        line_number++;
    }
    fclose(file);
}

int main() {
    /* Initialize the hash table */
    for (int i = 0; i < SIZE; i++) {
        hash_table[i] = NULL;
    }
    /* Load the dictionary */
    int count = load_dict("dictionary.txt");
    printf("Dictionary loaded (%d words)\n\n", count);
    /* Check a text file */
    spell_check("text.txt");
    return 0;
}
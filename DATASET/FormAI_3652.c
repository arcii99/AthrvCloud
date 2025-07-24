//FormAI DATASET v1.0 Category: Spell checking ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LEN 1024
#define MAX_WORD_LEN 50
#define MAX_DICT_WORDS 10000

struct Node {
    char word[MAX_WORD_LEN];
    struct Node* next;
};
typedef struct Node Node;

/* Function prototypes */
void read_words(char* filename, Node** dict);
int hash(char* word);
void add_word(Node** dict, char* word);
int contains_word(Node** dict, char* word);
int is_valid_word(char* word);
void strip_punctuation(char* word);
void to_lower_case(char* word);

int main(int argc, char** argv) {
    Node* dict[MAX_DICT_WORDS] = {0};

    if (argc != 3) {
        printf("Usage: %s <dictionaryfile> <textfile>\n", argv[0]);
        return 1;
    }

    /* Read the dictionary words into a hash table */
    read_words(argv[1], dict);

    /* Read each line of the text file, and check for spelling errors */
    FILE* fp = fopen(argv[2], "r");
    if (fp == NULL) {
        printf("Could not open file %s\n", argv[2]);
        return 1;
    }
    char line[MAX_LINE_LEN];
    while (fgets(line, MAX_LINE_LEN, fp)) {
        char* word = strtok(line, " \n");
        while (word != NULL) {
            strip_punctuation(word);
            to_lower_case(word);
            if (is_valid_word(word) && !contains_word(dict, word)) {
                printf("Spelling error: %s\n", word);
            }
            word = strtok(NULL, " \n");
        }
    }
    fclose(fp);

    /* Free the dictionary words linked list */
    for (int i = 0; i < MAX_DICT_WORDS; i++) {
        Node* node = dict[i];
        while (node != NULL) {
            Node* temp = node;
            node = node->next;
            free(temp);
        }
    }

    return 0;
}

/* Reads words from a file and inserts them into a hash table */
void read_words(char* filename, Node** dict) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Could not open file %s\n", filename);
        exit(1);
    }
    char line[MAX_LINE_LEN];
    while (fgets(line, MAX_LINE_LEN, fp)) {
        char* word = strtok(line, " \n");
        while (word != NULL) {
            add_word(dict, word);
            word = strtok(NULL, " \n");
        }
    }
    fclose(fp);
}

/* Hash function for a string */
int hash(char* word) {
    int sum = 0;
    for (int i = 0; i < strlen(word); i++) {
        sum += word[i];
    }
    return sum % MAX_DICT_WORDS;
}

/* Adds a word to a hash table */
void add_word(Node** dict, char* word) {
    int index = hash(word);
    Node* node = malloc(sizeof(Node));
    strncpy(node->word, word, MAX_WORD_LEN);
    node->next = dict[index];
    dict[index] = node;
}

/* Checks if a hash table contains a word */
int contains_word(Node** dict, char* word) {
    int index = hash(word);
    Node* node = dict[index];
    while (node != NULL) {
        if (strcmp(node->word, word) == 0) {
            return 1;
        }
        node = node->next;
    }
    return 0;
}

/* Checks if a word contains only letters and is not too long */
int is_valid_word(char* word) {
    int len = strlen(word);
    if (len > MAX_WORD_LEN || len == 0) {
        return 0;
    }
    for (int i = 0; i < len; i++) {
        if (!isalpha(word[i])) {
            return 0;
        }
    }
    return 1;
}

/* Strips punctuation from a string */
void strip_punctuation(char* word) {
    int len = strlen(word);
    for (int i = 0; i < len; i++) {
        if (ispunct(word[i])) {
            memmove(&word[i], &word[i+1], len-i);
            len--;
            i--;
        }
    }
}

/* Converts a string to lower case */
void to_lower_case(char* word) {
    int len = strlen(word);
    for (int i = 0; i < len; i++) {
        word[i] = tolower(word[i]);
    }
}
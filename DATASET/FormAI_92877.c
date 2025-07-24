//FormAI DATASET v1.0 Category: Spell checking ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* dictionary[10000];
int dict_size;

/* Hash function to map words to indices in the dictionary */
unsigned long hash(char *s) {
    unsigned long hash = 5381;
    int c;
    while ((c = *s++))
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    return hash % dict_size;
}

/* Function to load the dictionary from a file */
void load_dictionary(char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }

    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    while ((read = getline(&line, &len, file)) != -1) {
        line[strcspn(line, "\r\n")] = 0; // remove newline character
        dictionary[hash(line)] = strdup(line);
    }

    fclose(file);

    printf("Dictionary loaded successfully.\n");
}

/* Function to check if a given word is in the dictionary */
int is_word(char *word) {
    char *s = word;
    while (*s) {
        if (!isalpha(*s)) return 0;
        *s = tolower(*s);
        s++;
    }
    return dictionary[hash(word)] && strcmp(dictionary[hash(word)], word) == 0;
}

/* Function to print suggestions for a misspelled word */
void suggest_words(char *word) {
    printf("Did you mean:\n");
    int count = 0;

    /* Check for words with one letter added */
    for (int i = 0; i <= strlen(word); i++) {
        for (char c = 'a'; c <= 'z'; c++) {
            char *new_word = calloc(strlen(word) + 2, sizeof(char));
            strncpy(new_word, word, i);
            new_word[i] = c;
            strncpy(new_word + i + 1, word + i, strlen(word) - i + 1);

            if (is_word(new_word)) {
                printf("- %s\n", new_word);
                count++;
            }
            free(new_word);
        }
    }

    /* Check for words with one letter removed */
    for (int i = 0; i < strlen(word); i++) {
        char *new_word = calloc(strlen(word), sizeof(char));
        strncpy(new_word, word, i);
        strncpy(new_word + i, word + i + 1, strlen(word) - i);

        if (is_word(new_word)) {
            printf("- %s\n", new_word);
            count++;
        }
        free(new_word);
    }

    /* Check for words with one letter replaced */
    for (int i = 0; i < strlen(word); i++) {
        for (char c = 'a'; c <= 'z'; c++) {
            char *new_word = strdup(word);
            new_word[i] = c;

            if (is_word(new_word)) {
                printf("- %s\n", new_word);
                count++;
            }
            free(new_word);
        }
    }

    if (count == 0) printf("No suggestions found.\n");
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s dictionary_file text_file\n", argv[0]);
        return 1;
    }

    dict_size = 10000;
    for (int i = 0; i < dict_size; i++) {
        dictionary[i] = NULL;
    }

    load_dictionary(argv[1]);

    FILE *file = fopen(argv[2], "r");
    if (!file) {
        printf("Error: Could not open file %s\n", argv[2]);
        exit(1);
    }

    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    while ((read = getline(&line, &len, file)) != -1) {
        char *token = strtok(line, " \t\n\r");
        while (token) {
            if (!is_word(token)) {
                printf("Misspelled word: %s\n", token);
                suggest_words(token);
            }
            token = strtok(NULL, " \t\n\r");
        }
    }

    fclose(file);

    return 0;
}
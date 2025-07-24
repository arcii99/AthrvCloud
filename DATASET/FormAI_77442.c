//FormAI DATASET v1.0 Category: Spell checking ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 50
#define DICTIONARY_SIZE 100

char dictionary[DICTIONARY_SIZE][MAX_WORD_LENGTH];
int dict_count = 0;

void load_dictionary(char* filename) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Could not open dictionary file.\n");
        exit(1);
    }

    char line[MAX_WORD_LENGTH];
    while (fgets(line, MAX_WORD_LENGTH, fp)) {
        line[strcspn(line, "\r\n")] = 0; // Remove trailing newline
        strcpy(dictionary[dict_count], line);
        dict_count++;
    }

    fclose(fp);
}

int is_in_dictionary(char* word) {
    for (int i = 0; i < dict_count; i++) {
        if (strcmp(dictionary[i], word) == 0) {
            return 1;
        }
    }
    return 0;
}

void check_spelling(char* filename) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Could not open input file.\n");
        exit(1);
    }

    char line[MAX_WORD_LENGTH];
    while (fgets(line, MAX_WORD_LENGTH, fp)) {
        char* token = strtok(line, " \t\n");
        while (token != NULL) {
            if (!is_in_dictionary(token)) {
                printf("Misspelled word: %s\n", token);
            }
            token = strtok(NULL, " \t\n");
        }
    }

    fclose(fp);
}

int main(int argc, char** argv) {
    if (argc != 3) {
        printf("Usage: ./spell_check dictionary.txt input.txt\n");
        exit(1);
    }

    load_dictionary(argv[1]);
    check_spelling(argv[2]);

    return 0;
}
//FormAI DATASET v1.0 Category: Spell checking ; Style: minimalist
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LEN 50
#define MAX_DICT_LEN 100

int dictionary_size = 0;
char dictionary[MAX_DICT_LEN][MAX_WORD_LEN];

int read_dictionary(char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file %s\n", filename);
        return 0;
    }

    int i = 0;
    char buffer[MAX_WORD_LEN];
    while (fgets(buffer, MAX_WORD_LEN, file)) {
        int len = strlen(buffer);
        if (len > 0 && buffer[len-1] == '\n') {
            buffer[len-1] = '\0';
        }
        if (isalpha(buffer[0])) {
            strcpy(dictionary[i], buffer);
            i++;
        }
        if (i == MAX_DICT_LEN) {
            break;
        }
    }

    fclose(file);
    dictionary_size = i;

    return 1;
}

int is_in_dictionary(char* word) {
    int i;
    for (i = 0; i < dictionary_size; i++) {
        if (strcmp(word, dictionary[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

int is_uppercase(char* word) {
    int i;
    for (i = 0; i < strlen(word); i++) {
        if (islower(word[i])) {
            return 0;
        }
    }
    return 1;
}

int is_spelled_correctly(char* word) {
    if (is_in_dictionary(word)) {
        return 1;
    } else if (is_uppercase(word) && is_in_dictionary(word+1)) {
        return 1;
    } else {
        return 0;
    }
}

int main(int argc, char** argv) {
    if (argc != 3) {
        printf("Usage: spellcheck <dictionary_file> <input_file>\n");
        return 1;
    }

    char* dictionary_filename = argv[1];
    char* input_filename = argv[2];

    if (!read_dictionary(dictionary_filename)) {
        return 1;
    }

    FILE* file = fopen(input_filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file %s\n", input_filename);
        return 1;
    }

    char buffer[MAX_WORD_LEN];
    while (fscanf(file, "%s", buffer) != EOF) {
        if (!isalpha(buffer[0])) {
            continue;
        }

        if (!is_spelled_correctly(buffer)) {
            printf("Misspelled word: %s\n", buffer);
        }
    }

    fclose(file);

    return 0;
}
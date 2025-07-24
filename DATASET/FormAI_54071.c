//FormAI DATASET v1.0 Category: Spell checking ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define MAX_DICT_SIZE 1000

/*
 * This is a spell-check program written in C. It uses a dictionary to check the spelling of words
 * entered by the user. If a word is not found in the dictionary, it is marked as incorrect.
 * The program prompts the user to enter a sentence, which it then tokenizes into individual words
 * and checks each word against the dictionary.
 */

void to_lower_case(char *word) {
    int i;
    for (i = 0; word[i] != '\0'; i++) {
        word[i] = tolower(word[i]);
    }
}

void strip_punctuation(char *word) {
    int i, j;
    for (i = 0, j = 0; word[i] != '\0'; i++) {
        if (isalpha(word[i])) {
            word[j++] = word[i];
        }
    }
    word[j] = '\0';
}

int is_in_dict(char *word, char **dict, int dict_size) {
    int i;
    for (i = 0; i < dict_size; i++) {
        if (strcmp(word, dict[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

int main() {
    FILE *dict_file = fopen("dictionary.txt", "r");
    if (dict_file == NULL) {
        printf("Could not open dictionary file.\n");
        return 1;
    }

    char *dict[MAX_DICT_SIZE];
    int dict_size = 0;
    char buffer[MAX_WORD_LENGTH];

    // Load dictionary
    while (fgets(buffer, MAX_WORD_LENGTH, dict_file) != NULL) {
        buffer[strcspn(buffer, "\n")] = '\0'; // Remove newline character
        dict[dict_size] = strdup(buffer); // Add word to dictionary
        dict_size++;
    }

    fclose(dict_file);

    printf("Enter a sentence: ");
    char sentence[1000];
    fgets(sentence, 1000, stdin);

    char *word;
    char *delim = " \n";
    word = strtok(sentence, delim);

    while (word != NULL) {
        to_lower_case(word);
        strip_punctuation(word);

        if (!is_in_dict(word, dict, dict_size)) {
            printf("Incorrect spelling: %s\n", word);
        }

        word = strtok(NULL, delim);
    }

    // Free memory allocated for dictionary
    int i;
    for (i = 0; i < dict_size; i++) {
        free(dict[i]);
    }

    return 0;
}
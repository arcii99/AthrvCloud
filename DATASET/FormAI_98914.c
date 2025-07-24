//FormAI DATASET v1.0 Category: Spell checking ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_SIZE 100
#define MAX_DICT_SIZE 10000

int load_dictionary(char *filename, char **dict);
int check_word(char *word, char **dict, int dict_size);

int main(void) {
    char *dict[MAX_DICT_SIZE], *filename = "dictionary.txt";
    int dict_size = load_dictionary(filename, dict);
    char input[MAX_WORD_SIZE];

    while (1) {
        printf("Enter a word to check (or q to quit): ");
        scanf("%s", input);
        if (strcmp(input, "q") == 0) break;
        if (check_word(input, dict, dict_size)) {
            printf("%s is spelled correctly.\n", input);
        } else {
            printf("%s is not spelled correctly.\n", input);
        }
    }

    for (int i = 0; i < dict_size; i++) {
        free(dict[i]);
    }
    return 0;
}

int load_dictionary(char *filename, char **dict) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening dictionary file");
        exit(EXIT_FAILURE);
    }

    char word[MAX_WORD_SIZE];
    int i = 0;
    while (fgets(word, MAX_WORD_SIZE, fp) != NULL && i < MAX_DICT_SIZE) {
        word[strcspn(word, "\n")] = '\0'; // Remove trailing newline
        dict[i] = malloc(strlen(word) + 1);
        strcpy(dict[i], word);
        i++;
    }

    fclose(fp);
    return i;
}

int check_word(char *word, char **dict, int dict_size) {
    for (int i = 0; i < dict_size; i++) {
        if (strcmp(word, dict[i]) == 0) {
            return 1; // Word found in dictionary
        }
    }
    return 0; // Word not found in dictionary
}
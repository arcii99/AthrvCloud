//FormAI DATASET v1.0 Category: Spell checking ; Style: careful
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LEN 50
#define MAX_DICT_SIZE 10000

/* Function to read dictionary file and save words in dictionary */
int read_dictionary(char* file_path, char dictionary[MAX_DICT_SIZE][MAX_WORD_LEN]) {
    FILE* fp;
    fp = fopen(file_path, "r");
    if (fp == NULL) {
        printf("Error opening dictionary file\n");
        return 1;
    }
    int i = 0;
    while (fgets(dictionary[i], MAX_WORD_LEN, fp) != NULL) {
        /* Remove newline character from the end of the word */
        dictionary[i][strcspn(dictionary[i], "\n")] = 0;
        i++;
    }
    printf("Dictionary loaded successfully!\n");
    fclose(fp);
    return 0;
}

/* Function to check if a word is present in the dictionary */
int is_word_present(char* word, char dictionary[MAX_DICT_SIZE][MAX_WORD_LEN], int dict_size) {
    for (int i = 0; i < dict_size; i++) {
        if (strcmp(word, dictionary[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

/* Function to check and suggest corrections for a word */
void check_word(char* word, char dictionary[MAX_DICT_SIZE][MAX_WORD_LEN], int dict_size) {
    char new_word[MAX_WORD_LEN];

    /* Convert word to lowercase */
    for (int i = 0; i < strlen(word); i++) {
        new_word[i] = tolower(word[i]);
    }

    if (is_word_present(new_word, dictionary, dict_size)) {
        printf("%s is spelled correctly!\n", word);
    } else {
        printf("%s is misspelled. Suggestions:\n", word);
        /* Generate suggestions by swapping adjacent letters */
        for (int i = 0; i < strlen(new_word)-1; i++) {
            char temp = new_word[i];
            new_word[i] = new_word[i+1];
            new_word[i+1] = temp;
            if (is_word_present(new_word, dictionary, dict_size)) {
                printf("- %s\n", new_word);
            }
            new_word[i+1] = new_word[i];
            new_word[i] = temp;
        }
    }
}

/* Main function */
int main() {
    /* Dictionary file path */
    char* dictionary_file = "dictionary.txt";

    /* Array to store dictionary words */
    char dictionary[MAX_DICT_SIZE][MAX_WORD_LEN];

    /* Read dictionary from file */
    if (read_dictionary(dictionary_file, dictionary) != 0) {
        return 1;
    }

    /* Input loop */
    while (1) {
        char input[MAX_WORD_LEN];
        printf("Enter word to check (enter q to quit): ");
        scanf("%s", input);

        /* Exit loop if user inputs q */
        if (strcmp(input, "q") == 0) {
            break;
        }

        check_word(input, dictionary, MAX_DICT_SIZE);
    }

    return 0;
}
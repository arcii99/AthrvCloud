//FormAI DATASET v1.0 Category: Spell checking ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define MAX_DICT_WORDS 2000

// Structure for storing dictionary words
struct dict {
    char word[MAX_WORD_LENGTH];
};

// Function to load dictionary words into the array
int load_dict(struct dict *dict_arr, FILE *dict_file) {
    char line[MAX_WORD_LENGTH];
    int i = 0;
    while (fgets(line, MAX_WORD_LENGTH, dict_file) != NULL) {
        line[strcspn(line, "\n")] = '\0';  // Remove newline character
        strcpy(dict_arr[i].word, line);
        i++;
    }
    return i;
}

// Function to check if the given word is in the dictionary
int is_word_in_dict(struct dict *dict_arr, int dict_size, char *word) {
    for (int i = 0; i < dict_size; i++) {
        if (strcmp(dict_arr[i].word, word) == 0) {
            return 1;
        }
    }
    return 0;
}

// Function to print a paranoid warning message
void print_warning() {
    printf("\nWARNING: The word you entered may be misspelled!\n");
    printf("Please verify that the spelling is correct before proceeding.\n\n");
}

// Main function
int main(void) {
    FILE *dict_file;
    char word[MAX_WORD_LENGTH];
    struct dict dict_arr[MAX_DICT_WORDS];
    int dict_size;

    // Open dictionary file and load words into array
    dict_file = fopen("dictionary.txt", "r");
    if (dict_file == NULL) {
        printf("Error: Dictionary file cannot be opened.\n");
        exit(EXIT_FAILURE);
    }
    dict_size = load_dict(dict_arr, dict_file);
    fclose(dict_file);

    // Get input word from user
    printf("Enter a word to check for spelling errors: ");
    scanf("%s", word);

    // Change input word to lowercase for case-insensitivity
    for (int i = 0; i < MAX_WORD_LENGTH; i++) {
        word[i] = tolower(word[i]);
    }

    // Check if word is in dictionary
    if (!is_word_in_dict(dict_arr, dict_size, word)) {
        // Print paranoid warning message if not in dictionary
        print_warning();
    } else {
        printf("The spelling of \"%s\" is correct.\n", word);
    }

    return 0;
}
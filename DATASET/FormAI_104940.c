//FormAI DATASET v1.0 Category: Spell checking ; Style: secure
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

#define MAX_WORD_SIZE 50
#define MAX_DICT_SIZE 5000

// Function prototypes
char *read_word(void);
void to_lower_case(char *word);
bool spell_check(char *word, char dict[MAX_DICT_SIZE][MAX_WORD_SIZE], int dict_size);

int main(void) {
    // Initialize dictionary with known words
    char dictionary[MAX_DICT_SIZE][MAX_WORD_SIZE] = {
        "apple", "banana", "cherry", "lemon", "orange", "pear", "pineapple"
    };
    int dict_size = 7;  // Number of words in the dictionary
    
    // Read user input and convert to lowercase for case-insensitive comparison
    char *input_word = read_word();
    to_lower_case(input_word);
    
    // Run spell check on the input word using the dictionary
    bool is_spelled_correctly = spell_check(input_word, dictionary, dict_size);
    
    // Print result to user
    if (is_spelled_correctly) {
        printf("%s is spelled correctly!\n", input_word);
    } else {
        printf("Did you mean ");
        for (int i = 0; i < dict_size; i++) {
            if (strncmp(input_word, dictionary[i], strlen(input_word)) == 0) {
                printf("%s ? ", dictionary[i]);
            }
        }
        printf("\n");
    }
    
    return 0;
}

// Function to read a single word from user input
char *read_word(void) {
    char *word = malloc(MAX_WORD_SIZE);
    printf("Enter a word to spell check: ");
    scanf("%s", word);
    return word;
}

// Function to convert a string to lowercase
void to_lower_case(char *word) {
    int len = strlen(word);
    for (int i = 0; i < len; i++) {
        word[i] = tolower(word[i]);
    }
}

// Function to check if a word is spelled correctly using a dictionary
bool spell_check(char *word, char dict[MAX_DICT_SIZE][MAX_WORD_SIZE], int dict_size) {
    for (int i = 0; i < dict_size; i++) {
        if (strcmp(word, dict[i]) == 0) {
            return true;
        }
    }
    return false;
}
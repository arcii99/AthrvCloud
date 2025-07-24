//FormAI DATASET v1.0 Category: Spell checking ; Style: expert-level
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LEN 50
#define DICTIONARY_SIZE 10000

char dictionary[DICTIONARY_SIZE][MAX_WORD_LEN];
int dict_size = 0;

/**
 * Adds a word to the dictionary.
 */
void add_word_to_dictionary(char word[]) {
    if (dict_size == DICTIONARY_SIZE) {
        printf("Error: Dictionary full.\n");
        return;
    }

    strcpy(dictionary[dict_size], word);
    dict_size++;
}

/**
 * Searches for a word in the dictionary.
 */
int find_word_in_dictionary(char word[]) {
    for (int i = 0; i < dict_size; i++) {
        if (strcmp(word, dictionary[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

/**
 * Checks if a character is valid.
 */
int is_valid_character(char c) {
    return isalpha(c) || c == '-';
}

/**
 * Checks if a word is spelled correctly.
 */
int check_spelling(char word[]) {
    int len = strlen(word);
    if (len == 0 || len > MAX_WORD_LEN) {
        return 0;
    }

    if (!is_valid_character(word[0]) || !is_valid_character(word[len-1])) {
        return 0;
    }

    for (int i = 1; i < len-1; i++) {
        if (!is_valid_character(word[i])) {
            return 0;
        }
    }

    if (find_word_in_dictionary(word)) {
        return 1;
    }

    return 0;
}

int main() {
    add_word_to_dictionary("apple");
    add_word_to_dictionary("banana");
    add_word_to_dictionary("cherry");
    add_word_to_dictionary("grape");
    add_word_to_dictionary("orange");
    add_word_to_dictionary("pear");
    add_word_to_dictionary("pineapple");
    add_word_to_dictionary("strawberry");

    char input[1000];
    printf("Enter text to spell check:\n");
    fgets(input, 1000, stdin);

    char word[MAX_WORD_LEN];
    int word_len = 0;

    for (int i = 0; i < strlen(input); i++) {
        char c = input[i];
        if (is_valid_character(c)) {
            word[word_len] = tolower(c);
            word_len++;
        } else {
            word[word_len] = '\0';
            word_len = 0;
            if (!check_spelling(word)) {
                printf("Misspelled word: %s\n", word);
            }
        }
    }

    if (word_len > 0 && !check_spelling(word)) {
        printf("Misspelled word: %s\n", word);
    }

    return 0;
}
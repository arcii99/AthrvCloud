//FormAI DATASET v1.0 Category: Spell checking ; Style: secure
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_DICT_WORDS 10000

char dictionary[MAX_DICT_WORDS][MAX_WORD_LENGTH];
int dict_size = 0;

void add_word_to_dictionary(char word[]) {
    if (dict_size == MAX_DICT_WORDS) {
        printf("Dictionary is full!\n");
        return;
    }
    strcpy(dictionary[dict_size], word);
    dict_size++;
}

int is_word_in_dictionary(char word[]) {
    for (int i = 0; i < dict_size; i++) {
        if (strcmp(word, dictionary[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

void remove_last_character(char s[]) {
    int len = strlen(s);
    s[len - 1] = '\0';
}

void lowercase_string(char s[]) {
    for (int i = 0; i < strlen(s); i++) {
        s[i] = tolower(s[i]);
    }
}

int is_valid_word(char word[]) {
    lowercase_string(word);
    if (!is_word_in_dictionary(word)) {
        return 0;
    }
    // more validation rules can go here if needed
    return 1;
}

void spell_check(char input[]) {
    char word[MAX_WORD_LENGTH] = "";
    int in_word = 0;
    int num_errors = 0;
    for (int i = 0; i <= strlen(input); i++) {
        if (input[i] == ' ' || input[i] == '\0') {
            if (in_word) {
                word[strlen(word) - 1] = '\0'; // remove trailing comma/dot/etc.
                if (!is_valid_word(word)) {
                    printf("Misspelled word: %s\n", word);
                    num_errors++;
                }
                in_word = 0;
            }
        } else {
            in_word = 1;
            strncat(word, &input[i], 1);
        }
    }
    if (num_errors == 0) {
        printf("No spelling errors found.\n");
    }
}

int main() {
    add_word_to_dictionary("hello");
    add_word_to_dictionary("world");
    add_word_to_dictionary("programming");
    add_word_to_dictionary("computer");
    add_word_to_dictionary("security");
    add_word_to_dictionary("algorithm");
    add_word_to_dictionary("data");
    add_word_to_dictionary("machine");
    add_word_to_dictionary("learning");

    char input[1000];
    printf("Enter some text to spell check:\n");
    fgets(input, 1000, stdin);
    spell_check(input);

    return 0;
}
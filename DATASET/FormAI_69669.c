//FormAI DATASET v1.0 Category: Spell checking ; Style: happy
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_SIZE 50
#define MAX_DICTIONARY_WORDS 2000

void remove_trailing_newline(char* s) {
    size_t len = strlen(s);
    if (len > 0 && s[len-1] == '\n') {
        s[len-1] = '\0';
    }
}

void normalize_word(char* word) {
    int i = 0;
    while (word[i] != '\0') {
        word[i] = tolower(word[i]);
        i++;
    }
}

int is_word_in_dictionary(char* dictionary[], int dict_size, char* word) {
    for (int i = 0; i < dict_size; i++) {
        if (strcmp(word, dictionary[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

int main() {
    char* dictionary[MAX_DICTIONARY_WORDS];
    int dict_size = 0;

    // Read dictionary words from file
    FILE* dictionary_file = fopen("dictionary.txt", "r");
    if (dictionary_file == NULL) {
        printf("Couldn't open dictionary file\n");
        return 1;
    }
    char line[MAX_WORD_SIZE];
    while (fgets(line, MAX_WORD_SIZE, dictionary_file) != NULL) {
        remove_trailing_newline(line);
        dictionary[dict_size] = strdup(line);
        dict_size++;
    }
    fclose(dictionary_file);

    printf("Welcome to the Happy Spell Checker!\n");
    printf("Enter some text below and we'll check it for spelling errors.\n\n");

    // Read input text from user
    char word[MAX_WORD_SIZE];
    int line_number = 1;
    int word_number = 1;
    char c = getchar();
    while (c != EOF) {
        if (isspace(c)) { // End of word
            normalize_word(word);
            if (!is_word_in_dictionary(dictionary, dict_size, word)) {
                printf("Oops! Found spelling error on line %d, word %d: %s\n", line_number, word_number, word);
            }
            memset(word, 0, sizeof(word)); // Clear word buffer
            word_number++;
        } else { // Part of a word
            strncat(word, &c, 1);
        }
        if (c == '\n') { // End of line
            line_number++;
            word_number = 1;
        }
        c = getchar();
    }

    printf("\nThanks for using Happy Spell Checker! Have a great day!\n");

    // Free dictionary memory
    for (int i = 0; i < dict_size; i++) {
        free(dictionary[i]);
    }

    return 0;
}
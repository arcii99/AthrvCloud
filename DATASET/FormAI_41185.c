//FormAI DATASET v1.0 Category: Spell checking ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LEN 50
#define MAX_DICT_WORDS 1000

char dictionary[MAX_DICT_WORDS][MAX_WORD_LEN];
int dict_words_count = 0;

void add_to_dictionary(char word[]) {
    if (dict_words_count < MAX_DICT_WORDS) {
        strcpy(dictionary[dict_words_count++], word);
    }
}

int is_word_misspelled(char word[]) {
    for (int i = 0; i < dict_words_count; i++) {
        if (strcmp(word, dictionary[i]) == 0) {
            return 0;
        }
    }
    return 1;
}

void check_spelling(char text[]) {
    char word[MAX_WORD_LEN];
    int start_index = 0;
    for (int i = 0; i <= strlen(text); i++) {
        if (text[i] == ' ' || text[i] == '\0') {
            strncpy(word, text + start_index, i - start_index);
            word[i - start_index] = '\0';
            start_index = i + 1;
            if (strlen(word) > 0 && is_word_misspelled(word)) {
                printf("Did you mean: %s?\n", dictionary[rand() % dict_words_count]);
            }
        }
    }
}

int main() {
    printf("Welcome to the Spell Checker Wonderland - where words are not what they seem...\n");
    sleep(1);
    printf("Let us add some words to our unconventional dictionary...\n");
    sleep(1);
    add_to_dictionary("banana");
    add_to_dictionary("umbrella");
    add_to_dictionary("penguin");
    add_to_dictionary("giraffe");
    add_to_dictionary("flamingo");
    printf("Great! Our dictionary now has %d words.\n", dict_words_count);
    sleep(1);
    printf("Enter some text and we will check it for spelling errors:\n");
    char text[1000];
    fgets(text, 1000, stdin);
    check_spelling(text);
    printf("Thanks for playing in our surreal world of spelling...\n");
    return 0;
}
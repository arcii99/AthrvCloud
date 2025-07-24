//FormAI DATASET v1.0 Category: Spell checking ; Style: inquisitive
#include <stdio.h>
#include <string.h>
#define MAX_WORDS 1000
#define MAX_LEN 100

char dictionary[MAX_WORDS][MAX_LEN];
int dictionary_index = 0;

void add_to_dictionary(char* word) {
    strcpy(dictionary[dictionary_index++], word);
}

int is_in_dictionary(char* word) {
    for (int i = 0; i < dictionary_index; i++) {
        if (strcmp(word, dictionary[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

void spell_check(char* sentence) {
    char* word;
    word = strtok(sentence, " .,!?");
    while (word != NULL) {
        if (!is_in_dictionary(word)) {
            printf("Did you mean '%s'?\n", word);
        }
        word = strtok(NULL, " .,!?");
    }
}

int main() {
    add_to_dictionary("hello");
    add_to_dictionary("world");
    add_to_dictionary("how");
    add_to_dictionary("are");
    add_to_dictionary("you");
    char* sentence = "Hello, world! How are u?";
    spell_check(sentence);
    return 0;
}
//FormAI DATASET v1.0 Category: Spell checking ; Style: Alan Touring
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

#define N 100

// function to determine if a word is spelled correctly
bool is_spelled_correctly(char *word) {
    char dictionary[N][N] = {"apple", "banana", "cherry", "orange", "peach"};
    int size = sizeof(dictionary) / sizeof(dictionary[0]);
    for (int i=0; i<size; i++) {
        if (strcmp(dictionary[i], word) == 0) {
            return true;
        }
    }
    return false;
}

// function to print the corrected word
void print_correction(char *word) {
    char dictionary[N][N] = {"apple", "banana", "cherry", "orange", "peach"};
    int size = sizeof(dictionary) / sizeof(dictionary[0]);
    for (int i=0; i<size; i++) {
        if (strncasecmp(dictionary[i], word, strlen(word)) == 0) {
            printf("Did you mean %s?\n", dictionary[i]);
            return;
        }
    }
    printf("Sorry, no correction available.\n");
}

// main function to spell check a sentence
int main() {
    char sentence[N];
    printf("Enter a sentence to be spell checked: ");
    fgets(sentence, N, stdin);
    char *word = strtok(sentence, " ,.-\n\r");
    while (word != NULL) {
        if (!is_spelled_correctly(word)) {
            printf("'%s' is misspelled.\n", word);
            print_correction(word);
        }
        word = strtok(NULL, " ,.-\n\r");
    }
    return 0;
}
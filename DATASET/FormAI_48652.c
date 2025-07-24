//FormAI DATASET v1.0 Category: Spell checking ; Style: future-proof
#include <stdio.h>
#include <ctype.h>
#include <string.h>

// function prototypes
void process_word(char *word);
void suggest_corrections(char *word);

int main() {
    char input[100];

    printf("Enter a sentence to spell check:\n");
    fgets(input, 100, stdin); // read user input

    // tokenize input sentence
    char *token = strtok(input, " ,.?!;:\n");

    while (token != NULL) {
        // process each token
        process_word(token);
        token = strtok(NULL, " ,.?!;:\n");
    }

    return 0;
}

// function to process a word
void process_word(char *word) {
    int len = strlen(word);
    int i;

    // check if word contains any non-alpha characters
    for (i = 0; i < len; i++) {
        if (!isalpha(word[i])) {
            printf("%s", word); // non-alpha characters found, no correction suggested
            return;
        }
    }

    // word contains only alphabets
    suggest_corrections(word);
}

// function to suggest corrections for a word
void suggest_corrections(char *word) {
    char *dict[] = {"apple", "banana", "orange", "grape", "mango", "avocado"}; // sample dictionary
    int dict_size = sizeof(dict) / sizeof(dict[0]); // size of dictionary
    int i, j;
    int len = strlen(word);
    char temp;

    // check for exact match with dictionary words
    for (i = 0; i < dict_size; i++) {
        if (strcmp(word, dict[i]) == 0) {
            printf("%s ", word); // exact match found, no correction suggested
            return;
        }
    }

    // check for one character replacement
    for (i = 0; i < len; i++) {
        for (j = 0; j < 26; j++) {
            temp = word[i];
            word[i] = 'a' + j;
            for (int k = 0; k < dict_size; k++) {
                if (strcmp(word, dict[k]) == 0) {
                    printf("%s ", word); // correction found, suggest corrected word
                    return;
                }
            }
            word[i] = temp; // restore original character
        }
    }

    // unable to find any correction, print original word
    printf("%s ", word);
}
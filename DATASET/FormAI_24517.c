//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 1000

typedef struct Word {
    char string[MAX_WORD_LENGTH];
    int count;
} Word;

void to_lower(char* str) {
    for(int i = 0; str[i]; i++){
        str[i] = tolower(str[i]);
    }
}

// This function returns the index of the word in the array with the given string.
// If it does not exist yet, it will create a new one and return its index.
int get_word_index(char* str, Word* words, int* num_words) {
    to_lower(str);
    for(int i = 0; i < *num_words; i++) {
        if(strcmp(str, words[i].string) == 0) {
            return i;
        }
    }
    strcpy(words[*num_words].string, str);
    words[*num_words].count = 0;
    (*num_words)++;
    return (*num_words) - 1;
}

int main() {
    char input[MAX_WORD_LENGTH], c;
    Word words[MAX_WORDS];
    int num_words = 0;
    
    // Use a while loop to read input character by character until EOF is reached.
    while((c = getchar()) != EOF) {
        if(isalpha(c)) {
            // If the character is part of a word, add it to input string.
            input[strlen(input)] = c;
        } else if(strlen(input) > 0) {
            // If the input string has characters and a non-alphabetic character is found,
            // the word in the input string is complete.
            input[strlen(input)] = '\0';
            int index = get_word_index(input, words, &num_words);
            words[index].count++;
            memset(input, 0, strlen(input));
        }
    }
    
    printf("WORD\t\tFREQUENCY\n");
    printf("----\t\t---------\n");
    for(int i = 0; i < num_words; i++) {
        printf("%-15s%d\n", words[i].string, words[i].count);
    }

    return EXIT_SUCCESS;
}
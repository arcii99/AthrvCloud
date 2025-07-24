//FormAI DATASET v1.0 Category: Spell checking ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_SIZE 50
#define MAX_NUM_WORDS 10000

int numWords = 0;
char** words;
char* dictionary[] = {"hello", "world", "goodbye"};

void addWord(char* word) {
    words[numWords++] = strdup(word);
}

void checkWord(char* word) {
    int i;
    for (i = 0; i < sizeof(dictionary) / sizeof(dictionary[0]); i++) {
        if (strcmp(word, dictionary[i]) == 0) {
            printf("Word '%s' is spelled correctly.\n", word);
            return;
        }
    }
    printf("Word '%s' is spelled incorrectly.\n", word);
}

int main() {
    char input[MAX_WORD_SIZE];
    words = malloc(MAX_NUM_WORDS * sizeof(char*));
    
    printf("Enter a sentence: ");
    fgets(input, MAX_WORD_SIZE, stdin);
    
    char* token = strtok(input, " ,.-\n");
    while (token != NULL) {
        addWord(token);
        token = strtok(NULL, " ,.-\n");
    }
    
    int i;
    for (i = 0; i < numWords; i++) {
        checkWord(words[i]);
    }
    
    for (i = 0; i < numWords; i++) {
        free(words[i]);
    }
    free(words);
    
    return 0;
}
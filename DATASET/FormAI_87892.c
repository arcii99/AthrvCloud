//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 1000

struct word {
    char* word;
    int frequency;
};

void countWords(char* string, struct word* words, int* numWords) {
    char* token = strtok(string, " ,.-\n");
    while (token != NULL) {
        int index = -1;
        for (int i = 0; i < *numWords; i++) {
            if (strcmp(token, words[i].word) == 0) {
                index = i;
                break;
            }
        }
        if (index == -1) {
            words[*numWords].word = malloc(strlen(token) + 1);
            strcpy(words[*numWords].word, token);
            words[*numWords].frequency = 1;
            (*numWords)++;
        } else {
            words[index].frequency++;
        }
        token = strtok(NULL, " ,.-\n");
    }
}

int main() {
    char input[MAX_WORD_LENGTH];
    struct word words[MAX_WORDS];
    int numWords = 0;
    
    printf("Enter a string: ");
    fgets(input, MAX_WORD_LENGTH, stdin);
    
    countWords(input, words, &numWords);
    
    printf("Word frequency count:\n");
    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].frequency);
        free(words[i].word);
    }
    
    return 0;
}
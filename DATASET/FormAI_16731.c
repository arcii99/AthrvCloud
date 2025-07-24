//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} Word;

void count_words(char *txt, Word *words, int *num_words) {
    char delimiters[] = " ,.;:";
    char *token;
    
    token = strtok(txt, delimiters);
    
    while (token != NULL) {
        int i;
        for (i = 0; i < *num_words; i++) {
            if (strcmp(words[i].word, token) == 0) {
                words[i].count++;
                break;
            }
        }
        
        if (i == *num_words) {
            if (*num_words == MAX_WORDS) {
                printf("Maximum number of words reached.\n");
                return;
            }
            strncpy(words[*num_words].word, token, MAX_WORD_LENGTH);
            words[*num_words].count = 1;
            (*num_words)++;
        }
        
        token = strtok(NULL, delimiters);
    }
}

void print_word_counts(Word *words, int num_words) {
    printf("Word frequency:\n");
    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }
}

int main() {
    char text[MAX_WORDS * MAX_WORD_LENGTH];
    Word words[MAX_WORDS];
    int num_words = 0;
    
    printf("Enter text to count word frequency:\n");
    fgets(text, MAX_WORDS * MAX_WORD_LENGTH, stdin);
    
    count_words(text, words, &num_words);
    print_word_counts(words, num_words);
    
    return EXIT_SUCCESS;
}
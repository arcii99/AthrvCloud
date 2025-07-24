//FormAI DATASET v1.0 Category: Word Count Tool ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 50
#define MAX_NUM_WORDS 500

int main() {

    // Initializing required variables
    char *words[MAX_NUM_WORDS];
    char input_string[1000];
    int total_words = 0;

    // Input
    printf("Enter the text to be counted: ");
    fgets(input_string, 1000, stdin);

    // Tokenizing the input string
    char *token = strtok(input_string, " ");
    while(token != NULL) {
        words[total_words++] = token;
        token = strtok(NULL, " ");
    }

    // Counting words
    int word_count[MAX_NUM_WORDS];
    memset(word_count, 0, total_words * sizeof(int));
    for(int i = 0; i < total_words; i++) {
        for(int j = 0; j < total_words; j++) {
            if(strcmp(words[i], words[j]) == 0) {
                word_count[i]++;
            }
        }
    }

    // Removing duplicate words and counting unique words
    int unique_words = 0;
    for(int i = 0; i < total_words; i++) {
        int is_duplicate = 0;
        for(int j = i + 1; j < total_words; j++) {
            if(strcmp(words[i], words[j]) == 0) {
                is_duplicate = 1;
            }
        }
        if(!is_duplicate) {
            unique_words++;
        }
    }

    // Printing word count results
    printf("\nWORD\t\tFREQUENCY\n");
    printf("---------------------------------\n");
    for(int i = 0; i < total_words; i++) {
        int is_duplicate = 0;
        for(int j = i + 1; j < total_words; j++) {
            if(strcmp(words[i], words[j]) == 0) {
                is_duplicate = 1;
            }
        }
        if(!is_duplicate) {
            printf("%-18s\t%d\n", words[i], word_count[i]);
        }
    }

    // Printing total word count and unique word count
    printf("\nNumber of words: %d\n", total_words);
    printf("Number of unique words: %d\n", unique_words);

    return 0;
}
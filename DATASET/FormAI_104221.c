//FormAI DATASET v1.0 Category: Text Summarizer ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct WordCount {
    char *word;
    int count;
} WordCount;

int main(void) {
    char input[5000];
    char *token;
    WordCount words[500];
    int i,num_words=0;

    printf("Enter text to be summarized:\n");
    fgets(input,5000,stdin); // Get input from user

    // Split text into words and count occurrences
    token = strtok(input, " ,.-\n\t"); 
    while(token != NULL && num_words < 500) {
        int found = 0;
        for(i = 0; i < num_words; i++) {
            if(strcmp(words[i].word, token) == 0) {
                words[i].count++;
                found = 1;
                break;
            }
        }
        if(!found) {
            words[num_words].word = malloc(strlen(token) + 1);
            strcpy(words[num_words].word, token);
            words[num_words].count = 1;
            num_words++;
        }
        token = strtok(NULL, " ,.-\n\t");
    }

    // Sort the words by frequency in descending order
    for(i = 0; i < num_words - 1; i++) {
        int j;
        for(j = i + 1; j < num_words; j++) {
            if(words[j].count > words[i].count) {
                // Swap the two elements
                WordCount temp = words[i];
                words[i] = words[j];
                words[j] = temp;
            }
        }
    }

    // Print out the top 10 most frequently occurring words
    printf("The most frequently occurring words are: \n");
    for(i = 0; i < 10 && i < num_words; i++) {
        printf("%s - %d times\n", words[i].word, words[i].count);
    }

    // Free memory allocated for words
    for(i = 0; i < num_words; i++) {
        free(words[i].word);
    }

    return 0;
}
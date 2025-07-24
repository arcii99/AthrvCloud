//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LEN 50
#define MAX_WORDS 1000

int main(){
    char words[MAX_WORDS][MAX_WORD_LEN];  // Array to hold the words
    int freq[MAX_WORDS] = {0};  // Array to hold the frequency of each word
    int num_words = 0;  // Total number of words in the array

    // Read in words from standard input
    char word[MAX_WORD_LEN];
    while (scanf("%s", word) != EOF){
        // Convert to lowercase
        for (int i = 0; word[i] != '\0'; i++){
            word[i] = tolower(word[i]);
        }

        // Check if word is already in words array
        int i;
        for (i = 0; i < num_words; i++){
            if (strcmp(word, words[i]) == 0){
                freq[i]++;
                break;
            }
        }

        // If word is not in words array, add it
        if (i == num_words){
            strcpy(words[i], word);
            freq[i]++;
            num_words++;
        }
    }

    // Print out the frequency for each word
    for (int i = 0; i < num_words; i++){
        printf("%s: %d\n", words[i], freq[i]);
    }

    return 0;
}
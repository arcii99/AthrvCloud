//FormAI DATASET v1.0 Category: Text Summarizer ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARACTERS 1000
#define MAX_SUMMARY_LENGTH 100

// Function to remove punctuation from a given string
void removePunctuation(char *string) {
    int length = strlen(string);

    for(int i = 0; i < length; i++) {
        if(string[i] == '.' || string[i] == ',' || string[i] == ';' || string[i] == ':') {
            for(int j = i; j < length - 1; j++) {
                string[j] = string[j + 1];
            }
            length--;
            i--;
        }
    }
}

// Function to split a given string into an array of words
int splitString(char *string, char **words) {
    int numWords = 0;

    words[numWords] = strtok(string, " ");
    while(words[numWords] != NULL) {
        numWords++;
        words[numWords] = strtok(NULL, " ");
    }

    return numWords;
}

// Function to find the most frequent word in a given array of words
char* findMostFrequentWord(char **words, int numWords) {
    int maxCount = 0;
    char *mostFrequent = NULL;

    for(int i = 0; i < numWords; i++) {
        int count = 0;
        for(int j = i; j < numWords; j++) {
            if(strcmp(words[i], words[j]) == 0) {
                count++;
            }
        }
        if(count > maxCount) {
            maxCount = count;
            mostFrequent = words[i];
        }
    }

    return mostFrequent;
}

// Main function
int main() {
    char input[MAX_CHARACTERS];
    char *words[MAX_CHARACTERS];
    char summary[MAX_SUMMARY_LENGTH];
    int numWords;

    printf("Enter text: ");
    fgets(input, MAX_CHARACTERS, stdin);

    // Remove punctuation from input string
    removePunctuation(input);

    // Split input string into array of words
    numWords = splitString(input, words);

    // Find most frequent word in words array
    char *mostFrequent = findMostFrequentWord(words, numWords);

    // Generate summary using most frequent word
    snprintf(summary, MAX_SUMMARY_LENGTH, "The text contains the word '%s' %d times.", mostFrequent, numWords);

    // Print summary
    printf("Summary: %s\n", summary);

    return 0;
}
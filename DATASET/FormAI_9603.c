//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: satisfied
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50 // Maximum length of a word in characters

int countWords(char* sentence);
void printFrequency(int freq[], int size);

int main() {
    char sentence[100]; // Maximum sentence length
    int freq[MAX_WORD_LENGTH] = {0}; // Initialize word frequency array to 0

    printf("Welcome to the C Word Frequency Counter!\n");
    printf("Enter a sentence: ");
    fgets(sentence, 100, stdin); // Read input from user

    int numWords = countWords(sentence); // Count number of words in sentence
    printf("\nNumber of words: %d\n", numWords);

    char* word = strtok(sentence, " .,?!\n"); // Split sentence into words
    while (word != NULL) {
        int len = strlen(word);
        if (len <= MAX_WORD_LENGTH) {
            freq[len-1]++;
        }
        word = strtok(NULL, " .,?!\n");
    }
    
    printf("Frequency of word lengths:\n");
    printFrequency(freq, MAX_WORD_LENGTH);

    return 0;
}

// Function to count number of words in a sentence
int countWords(char* sentence) {
    int count = 0;
    char* word = strtok(sentence, " .,?!\n");
    while (word != NULL) {
        count++;
        word = strtok(NULL, " .,?!\n");
    }
    return count;
}

// Function to print frequency of word lengths
void printFrequency(int freq[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d-letter words: %d\n", i+1, freq[i]);
    }
}
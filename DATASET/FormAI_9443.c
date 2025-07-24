//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

// Function to generate random words between 3 to 20 characters in length
void generateWords(char words[][MAX_WORD_LENGTH]) {
    char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
    int i, j, wordLength;
    srand(time(NULL)); // seeding the random number generator

    for(i=0; i<MAX_WORDS; i++) {
        wordLength = rand() % 18 + 3; // generating random word length between 3 to 20 (inclusive)

        for(j=0; j<wordLength; j++) {
            words[i][j] = alphabet[rand() % 26]; // picking random alphabets to form the word
        }
        words[i][wordLength] = '\0'; // null terminating the word
    }
}

// Function to print the words for the user to type
void printWords(char words[][MAX_WORD_LENGTH], int n) {
    int i;
    printf("Type the following words as fast as you can:\n");
    for(i=0; i<n; i++) {
        printf("%s ", words[i]);
    }
    printf("\n");
}

// Function to calculate the typing speed of the user
double calculateTypingSpeed(double timeTaken, int totalStringLength) {
    double seconds = timeTaken/CLOCKS_PER_SEC; // calculating time in seconds
    return ((double)totalStringLength/5)/seconds*60; // calculating WPM (words per minute) assuming an average word length of 5 characters
}

int main() {
    char words[MAX_WORDS][MAX_WORD_LENGTH], userInput[MAX_WORDS][MAX_WORD_LENGTH];
    int i, n = 25, totalStringLength = 0;
    double timeTaken;
    clock_t start, end;

    generateWords(words); // generating random words
    printWords(words, n); // printing the words for the user

    start = clock(); // starting the timer
    for(i=0; i<n; i++) {
        scanf("%s", userInput[i]); // taking input from the user for each word
        totalStringLength += strlen(words[i]); // keeping track of total string length typed by the user
    }
    end = clock(); // stopping the timer

    timeTaken = (double)(end - start); // calculating the time taken to type the words

    printf("Time taken: %lf seconds\n", timeTaken/CLOCKS_PER_SEC);
    printf("Typing Speed: %lf WPM\n", calculateTypingSpeed(timeTaken, totalStringLength));

    return 0;
}
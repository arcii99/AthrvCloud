//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TESTS 5 // number of tests
#define ULONG_MAX_STRLEN 20 // max string length of unsigned long
#define TEST_TIME_LIMIT 5 // time limit for each test
#define TEST_WORDS_LIMIT 30 // word limit for each test

// function to generate random words
void generateWords(char words[][50], int n) {
    char alphabet[] = "abcdefghijklmnopqrstuvwxyz";

    for (int i = 0; i < n; i++) {
        int len = rand() % 10 + 1;
        for (int j = 0; j < len; j++) {
            words[i][j] = alphabet[rand() % 26];
        }
        words[i][len] = '\0';
    }
}

// function to print words
void printWords(char words[][50], int n) {
    for (int i = 0; i < n; i++) {
        printf("%s ", words[i]);
    }
}

// function to get user input
char* getUserInput() {
    char* input = (char*) malloc(100 * sizeof(char));
    fgets(input, 100, stdin);
    return input;
}

// function to check if two strings are equal
int isEqual(char* s1, char* s2) {
    while (*s1 != '\0' && *s2 != '\0') {
        if (*s1 != *s2) {
            return 0;
        }
        s1++;
        s2++;
    }
    if (*s1 == '\0' && *s2 == '\0') {
        return 1;
    }
    return 0;
}

int main() {
    char words[TESTS][TEST_WORDS_LIMIT][50]; // array to store the words for each test
    unsigned long totalTypos = 0; // total typos made by user
    unsigned long totalWordsTyped = 0; // total words typed by user
    time_t start, end; // variables to store start and end time of each test
    srand(time(NULL)); // generate seed for random number generator

    printf("*** C Typing Speed Test ***\n\n");
    printf("Type out the following words as fast as possible, and press enter between each word:\n");

    for (int i = 0; i < TESTS; i++) {
        generateWords(words[i], TEST_WORDS_LIMIT); // generate words for each test
        printWords(words[i], TEST_WORDS_LIMIT); // print the words for each test
        printf("\n");

        time(&start); // set start time
        for (int j = 0; j < TEST_WORDS_LIMIT; j++) {
            char* userInput = getUserInput(); // get user input
            if (! isEqual(userInput, words[i][j])) { // check for typos
                totalTypos++;
            }
            totalWordsTyped++;
            free(userInput); // free user input memory

            // check if time limit has been reached
            time(&end);
            if (difftime(end, start) > TEST_TIME_LIMIT) {
                printf("\nTime limit exceeded for this test. Moving onto next test...\n");
                break;
            }
        }
    }

    printf("\n*** Test results ***\n");
    printf("Total words typed: %lu\n", totalWordsTyped);
    printf("Total typos made: %lu\n", totalTypos);
    printf("Typing accuracy: %.2lf%%\n", ((double) (totalWordsTyped - totalTypos) / totalWordsTyped) * 100);

    return 0;
}
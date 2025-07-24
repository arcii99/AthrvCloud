//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_WORDS 50 // Maximum number of words in the test
#define MAX_WORD_LENGTH 15 // Maximum length of a word in characters

int main() {
    char words[MAX_WORDS][MAX_WORD_LENGTH]; // Array to store words
    int i, j;
    int mistakes = 0; // Counter for number of mistakes made by user
    clock_t start, end; // Variables to measure time taken to complete test
    float time_taken;

    // Populate array with random words
    char* word_list[] = {"abstract", "algorithm", "array", "binary", "buffer", "class",
                         "compile", "debug", "function", "integer", "library", "loop",
                         "memory", "null", "object", "operator", "pointer", "program",
                         "queue", "recursion", "stack", "string", "syntax", "variable"};
    srand(time(NULL)); // Seed the random number generator
    for (i = 0; i < MAX_WORDS; i++) {
        strcpy(words[i], word_list[rand() % 24]);
    }

    // Display instructions
    printf("Welcome to the Typing Speed Test!\n");
    printf("You will be given %d words to type as quickly and accurately as possible.\n", MAX_WORDS);
    printf("Press enter to begin.\n");
    getchar(); // Wait for user to press enter

    // Begin test
    start = clock();
    for (i = 0; i < MAX_WORDS; i++) {
        printf("Word %d: ", i+1); // Print the word to be typed
        char input[MAX_WORD_LENGTH]; // Variable to store user input
        scanf("%s", input);
        for (j = 0; j < strlen(input); j++) {
            if (input[j] != words[i][j]) {
                mistakes++; // Increment mistake counter if character is incorrect
            }
        }
    }
    end = clock();
    time_taken = (float)(end - start) / CLOCKS_PER_SEC;

    // Display results
    printf("Congratulations, you have completed the typing speed test!\n");
    printf("You made %d mistakes and took %.2f seconds to complete the test.\n", mistakes, time_taken);
    printf("Your typing speed was approximately %.2f words per minute.\n", (MAX_WORDS / time_taken) * 60);

    return 0;
}
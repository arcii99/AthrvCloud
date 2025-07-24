//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_LENGTH 100 // Maximum length of the input string
#define MAX_ATTEMPTS 5 // Max number of times the user can attempt to type the phrase

int main() {
    srand(time(0)); // Seed the random number generator with the current time
    char phrases[][MAX_LENGTH] = {"The quick brown fox jumps over the lazy dog.",
                                  "The five boxing wizards jump quickly.",
                                  "Pack my box with five dozen liquor jugs.",
                                  "How vexingly quick daft zebras jump.",
                                  "Sphinx of black quartz, judge my vow."}; // Array of phrases to choose from

    int num_phrases = sizeof(phrases) / sizeof(phrases[0]); // Calculate the number of phrases in the array
    int rand_index = rand() % num_phrases; // Generate a random index for selecting a phrase from the array
    char phrase[MAX_LENGTH];
    strcpy(phrase, phrases[rand_index]); // Copy the randomly selected phrase into the phrase variable

    int num_attempts = 0; // Initialize the number of attempts to 0
    printf("Type the following phrase:\n%s\n", phrase);
    clock_t start_time = clock(); // Get the starting time for the typing test

    while (num_attempts < MAX_ATTEMPTS) { // Start the loop to allow for multiple attempts
        char input[MAX_LENGTH];
        printf("Attempt %d : ", num_attempts + 1);
        fgets(input, MAX_LENGTH, stdin); // Get the user input

        // Check if the user input matches the phrase
        if (strcmp(input, phrase) == 0) {
            printf("Congratulations! You typed the phrase correctly!\n");
            clock_t end_time = clock(); // Get the ending time for the typing test
            double time_taken = (double) (end_time - start_time) / CLOCKS_PER_SEC; // Calculate the time taken in seconds
            printf("Time taken: %lf seconds\n", time_taken);
            return 0;
        } else {
            printf("Incorrect. Please try again.\n");
            num_attempts++; // Increment the number of attempts
        }
    }
    printf("Sorry, you have reached the maximum number of attempts.\n");
    return 0;
}
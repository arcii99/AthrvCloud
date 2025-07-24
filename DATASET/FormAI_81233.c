//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_LENGTH 50 // Maximum length of the typing test string
#define NUM_OF_TRIALS 3 // Number of typing tests to be taken

int main() {
    srand(time(NULL)); // Initialize random number generator
    char typing_test[MAX_LENGTH]; // Declare string for typing test
    int i, score, total_score = 0, average_score; // Declare variables for score calculation
    double total_time = 0, average_time; // Declare variables for time calculation
    clock_t start_time, end_time; // Declare variables for time measurement

    printf("*** Typing Speed Test ***\n\n");
    printf("Type the following string as fast as you can:\n");

    for (i = 0; i < NUM_OF_TRIALS; i++) {
        int j;
        int typing_test_length = (rand() % (MAX_LENGTH - 20)) + 20; // Generate random length of test string

        // Generate random string for typing test
        for (j = 0; j < typing_test_length; j++) {
            typing_test[j] = (rand() % 26) + 'a';
        }
        typing_test[typing_test_length] = '\0'; // Add null character to end of string

        printf("\n%s\n", typing_test); // Display typing test string
        printf("Type the string above and hit enter when finished.\n");

        start_time = clock(); // Start time measurement
        char input[MAX_LENGTH];
        fgets(input, sizeof(input), stdin); // Get user input
        end_time = clock(); // End time measurement

        // Calculate score and time
        int num_of_errors = 0;
        for (j = 0; j < typing_test_length; j++) {
            if (input[j] != typing_test[j]) {
                num_of_errors++;
            }
        }
        score = (typing_test_length - num_of_errors) * 60 / ((end_time - start_time) / (double)CLOCKS_PER_SEC);
        total_score += score;
        total_time += (end_time - start_time) / (double)CLOCKS_PER_SEC;
        printf("You %s the string in %d seconds with a score of %d.\n", num_of_errors ? "incorrectly typed" : "successfully typed", end_time - start_time, score);
    }

    // Calculate average score and time
    average_score = total_score / NUM_OF_TRIALS;
    average_time = total_time / NUM_OF_TRIALS;

    printf("\nTyping speed test completed.\n");
    printf("Your average score was %d words per minute.\n", average_score);
    printf("Your average time was %.2f seconds.\n", average_time);

    return 0;
}
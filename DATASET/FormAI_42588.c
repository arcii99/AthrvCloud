//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int numChars = 100; // Number of characters in the test
    char str[numChars]; // String to hold the test
    char userInput[numChars]; // String to hold user input
    int errors = 0; // Number of errors made by user
    double timeTaken; // Time taken to complete the test
    int i, j; // Counters for loops
    char c; // Character to be typed by user

    // Seed the random number generator
    srand(time(NULL));

    // Generate the test string
    for (i = 0; i < numChars; i++) {
        c = rand() % 26 + 97; // Generate a lowercase letter
        str[i] = c;
    }
    str[numChars] = '\0'; // Null-terminate the string

    // Display the test string
    printf("Type the following: \n%s\n", str);

    // Get user input and calculate errors
    clock_t startTime = clock(); // Start the clock
    for (j = 0; j < numChars; j++) {
        c = getchar(); // Get character from user
        userInput[j] = c;
        if (c != str[j]) {
            errors++;
        }
    }
    clock_t endTime = clock(); // End the clock

    // Calculate time taken
    timeTaken = (double)(endTime - startTime) / CLOCKS_PER_SEC;

    // Display results
    printf("Time taken: %.2f seconds\n", timeTaken);
    printf("Number of errors: %d\n", errors);

    return 0;
}
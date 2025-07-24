//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
    char quote[] = "The quick brown fox jumps over the lazy dog"; // Quote for typing test
    int length = strlen(quote); // Length of quote
    time_t start, end; // Variables to calculate time taken to complete test
    char input[length]; // User input for typing test

    printf("Welcome to the Typing Speed Test!\n\n");
    printf("Please type the following quote as fast as you can:\n%s\n", quote);
    printf("Press Enter when you're done.\n");

    start = time(NULL); // Mark start time of test

    fgets(input, length+1, stdin); // Accept user input

    end = time(NULL); // Mark end time of test

    float time_taken = difftime(end, start); // Calculate time taken to complete test in seconds
    time_taken /= 60; // Convert time taken from seconds to minutes
    float wpm = (float) length/5; // Calculate words per minute
    wpm = wpm/time_taken; // Divide by time taken to get words per minute

    printf("\nTest complete!\n");
    printf("Time taken: %.2f minutes\n", time_taken);
    printf("Words per minute: %.2f wpm\n", wpm);

    return 0;
}
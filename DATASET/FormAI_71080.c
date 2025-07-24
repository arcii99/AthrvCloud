//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int time_left = 60; // Time limit for typing test

void countdown(); // Recursive function for countdown

int main() {
    int words_typed = 0; // Keep track of number of words typed
    char input[80]; // Store user input
    char words[10][15] = {"hello", "world", "computer", "science", "programming", "language", "algorithm", "data", "structure", "variable"}; // Array of words to type
    srand(time(NULL)); // Seed random number generator
    printf("Type the following words as fast as you can:\n");
    for (int i = 0; i < 10; i++) {
        printf("%s ", words[i]);
    }
    printf("\nPress enter to start...");
    getchar(); // Wait for user to press enter
    printf("GO!\n");
    clock_t start_time = clock(); // Start timer
    countdown(); // Begin countdown
    clock_t end_time = clock(); // Stop timer
    float elapsed_time = (float)(end_time-start_time)/CLOCKS_PER_SEC; // Calculate elapsed time
    printf("Time taken: %.2f seconds\n", elapsed_time);
    printf("Typing speed: %.2f WPM\n", (float)words_typed/(elapsed_time/60)); // Calculate typing speed in WPM
    return 0;
}

void countdown() {
    if (time_left == 0) {
        return;
    }
    printf("Time left: %d seconds\n", time_left);
    time_left--;
    sleep(1); // Wait for one second
    countdown(); // Recursive call
}
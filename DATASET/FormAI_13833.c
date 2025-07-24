//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main()
{
    printf("Welcome to the Typing Speed Test!\n");
    printf("Please type the following text:\n");

    // Text to be typed
    char text[] = "The quick brown fox jumps over the lazy dog.";
    printf("%s\n", text);

    // Start timer
    clock_t start = clock();

    // User input
    char input[100];
    fgets(input, 100, stdin);

    // End timer
    clock_t end = clock();
    double time_taken = ((double) end - start) / CLOCKS_PER_SEC;

    // Remove newline character from input
    input[strcspn(input, "\n")] = 0;

    // Calculate accuracy percentage
    int correct = 0;
    for (int i = 0; i < strlen(input); i++)
    {
        if (input[i] == text[i])
        {
            correct++;
        }
    }
    double accuracy = (double)correct / strlen(text) * 100;

    // Calculate typing speed in words per minute
    double words = strlen(text) / 5;
    double minutes = time_taken / 60;
    double wpm = words / minutes;

    // Print results
    printf("\n");
    printf("Time taken: %.2f seconds\n", time_taken);
    printf("Accuracy: %.2f%%\n", accuracy);
    printf("Typing speed: %.2f words per minute\n", wpm);

    return 0;
}
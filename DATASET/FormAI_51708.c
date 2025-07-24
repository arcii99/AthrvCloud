//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Function to calculate typing speed
int calculateSpeed(char *text, double timeTaken) {
    int len = strlen(text);
    double speed = (double) len / timeTaken;
    return (int) speed;
}

int main() {
    char text[1000]; // Array to store the typed text
    char ch;
    int i = 0; // Index to keep track of correct keystrokes
    int errors = 0; // Variable to count errors
    double timeTaken; // Time taken to type the text

    printf("Welcome to the Typing Speed Test!\n\n");
    printf("Type the following sentence as quickly and accurately as possible:\n\n");
    printf("The quick brown fox jumps over the lazy dog.\n\n");

    time_t start = time(NULL); // Start timer

    while ((ch = getchar()) != '\n') {
        if (ch == text[i]) {
            i++;
        } else {
            errors++;
        }
    }

    time_t end = time(NULL); // Stop timer

    timeTaken = difftime(end, start); // Calculate time taken

    printf("\nCongratulations! You typed the sentence in %.2f seconds.\n", timeTaken);
    printf("You made %d errors.\n", errors);

    int speed = calculateSpeed("The quick brown fox jumps over the lazy dog.", timeTaken);
    printf("Your typing speed is %d characters per minute.\n", speed*60);

    return 0;
}
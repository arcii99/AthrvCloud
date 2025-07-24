//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

int main() {
    srand(time(NULL));
    char userInput;    // User's input
    int numChars = 0;  // Number of characters typed by the user
    int numMistakes = 0;  // Number of mistakes made by the user
    int timeTaken;  // Time taken to type the text
    int textLength;  // Length of the text to be typed
    char *text;

    printf("Welcome to the Typing Speed Test! Press enter to begin.\n");
    getchar();  // Wait for user to press enter

    // Generate the random text to be typed
    textLength = rand() % 150 + 100;  // Random number between 100 and 250
    text = malloc(sizeof(char) * textLength);
    for (int i = 0; i < textLength; i++) {
        text[i] = rand() % 94 + 33;  // Random character between ASCII 33 and 126
        printf("%c", text[i]);
    }

    time_t startTime = time(NULL); // Record start time

    // User types the text
    for (int i = 0; i < textLength; i++) {
        userInput = getchar();
        if (userInput == text[i]) {
            numChars++;
        } else {
            numMistakes++;
        }
    }

    timeTaken = time(NULL) - startTime;

    printf("\n\nYou typed %d characters in %d seconds.", numChars, timeTaken);
    printf("\nYou made %d mistakes and your typing speed is %.2f characters per minute.\n", numMistakes, ((float)numChars/timeTaken) * 60);

    free(text);
    return 0;
}
//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main() {
    // Variables to hold user input and text comparison
    char userInput[100];
    char inputChar;
    char text[100] = "The quick brown fox jumps over the lazy dog";
    int i = 0;
    int j = 0;

    // Generate a random typing speed test from a list of phrases
    srand(time(NULL));
    char *phrases[6] = {"The quick brown fox jumps over the lazy dog", "She sells seashells by the seashore", "Peter Piper picked a peck of pickled peppers", "How much wood would a woodchuck chuck", "Red lorry, yellow lorry, red lorry, yellow lorry", "I saw Susie sitting in a shoe shine shop"};
    int randomIndex = rand() % 6;
    strcpy(text, phrases[randomIndex]);

    // Display the text to the user and record the start time
    printf("Type the following text:\n%s\n", text);
    clock_t startTime = clock();

    // Loop through each character of the text and get user input
    while(text[i] != '\0') {
        inputChar = getchar();

        // Check if the input character matches the text character
        if(inputChar == text[i]) {
            i++;
        }
        j++;

        // Stop the timer if the user has finished typing the text
        if(i == strlen(text)) {
            clock_t endTime = clock();
            double timeInSeconds = (double)(endTime - startTime) / CLOCKS_PER_SEC;

            // Calculate and display the typing speed
            int wordsPerMinute = strlen(text) / 5 / (timeInSeconds / 60);
            printf("\nCongratulations! You typed the text correctly in %.2f seconds!\n", timeInSeconds);
            printf("Your typing speed is %d words per minute!\n", wordsPerMinute);
            return 0;
        }
    }
    return 0;
}
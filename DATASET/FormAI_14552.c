//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>

// function to generate a random alphabet from A-Z
char generateAlphabet() {
    return (char)((rand() % 26) + 65);
}

int main() {
    srand(time(NULL)); // seed for random number generation
    char userInput[100]; // array to store user input
    char generatedText[100]; // array to store generated text
    int errorCount = 0, correctCount = 0; // variables to keep track of errors and correct keystrokes
    double timeTaken, typingSpeed; // variables to calculate typing speed

    // Generating text for the user to type
    printf("Type the following text: \n");
    for (int i = 0; i < 50; i++) {
        generatedText[i] = generateAlphabet();
        printf("%c", generatedText[i]);
    }

    // Reading and processing user input
    printf("\n");
    clock_t start = clock(); // start time of user typing
    fgets(userInput, 100, stdin); // reading user input
    for (int i = 0; i < strlen(userInput); i++) {
        if (toupper(userInput[i]) == generatedText[i]) { // if user typed correctly
            correctCount++;
        }
        else {
            errorCount++; // if user typed incorrectly
        }
    }
    clock_t end = clock(); // end time of user typing

    // Calculating typing speed and printing results
    timeTaken = ((double)(end - start)) / CLOCKS_PER_SEC;
    typingSpeed = ((double)correctCount / 5) / timeTaken; // considering 5 keystrokes per word on an average
    printf("\nYour typing speed is %.2f words per minute.\n", typingSpeed * 60);

    return 0;
}
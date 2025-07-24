//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void generateRandomText(char* text, int length) {
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"; // available characters
    for (int i = 0; i < length; i++) {
        int randomIndex = rand() % (sizeof(charset) - 1);
        text[i] = charset[randomIndex];
    }
    text[length] = '\0';
}

int main() {
    // initialize random seed
    srand(time(NULL));

    // generate random text for typing test
    char text[101];
    generateRandomText(text, 100);

    printf("Welcome to the Typing Speed Test!\n");
    printf("Type the following text as fast and accurately as possible:\n%s\n\n", text);

    // initialize variables
    char input[101];
    int correctCount = 0;
    int incorrectCount = 0;
    int elapsedTime;

    // start timer
    clock_t start = clock();

    printf("Start typing...\n");

    // get user input
    fgets(input, 101, stdin);

    // stop timer
    elapsedTime = (clock() - start) / CLOCKS_PER_SEC;

    // count correct and incorrect characters
    for (int i = 0; i < strlen(text); i++) {
        if (text[i] == input[i]) {
            correctCount++;
        } else {
            incorrectCount++;
        }
    }

    // calculate accuracy and words per minute (WPM)
    float accuracy = (float)correctCount / (correctCount + incorrectCount) * 100;
    float wpm = ((float)correctCount / 5) / ((float)elapsedTime / 60);

    // print results
    printf("\n\n-- RESULTS --\n");
    printf("Time elapsed: %d seconds\n", elapsedTime);
    printf("Characters correct: %d\n", correctCount);
    printf("Characters incorrect: %d\n", incorrectCount);
    printf("Accuracy: %.2f%%\n", accuracy);
    printf("Words per minute (WPM): %.2f\n", wpm);

    return 0;
}
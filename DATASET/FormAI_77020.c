//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

int main() {
    char actualText[100] = "The quick brown fox jumps over the lazy dog.";
    char inputText[100];

    printf("Type the following text as fast as you can:\n");
    printf("%s\n", actualText);

    time_t startTime = time(NULL);

    fgets(inputText, sizeof(inputText), stdin);

    time_t endTime = time(NULL);
    time_t totalTime = endTime - startTime;

    int incorrectChars = 0;
    for (int i = 0; i < sizeof(actualText); i++) {
        if (toupper(actualText[i]) != toupper(inputText[i])) {
            incorrectChars++;
        }
    }

    int wordsPerMinute = ((strlen(actualText) - incorrectChars) / 5) / (totalTime / 60);

    printf("You typed the following text:\n");
    printf("%s\n", inputText);

    printf("Number of incorrect characters: %d\n", incorrectChars);
    printf("Time taken: %ld seconds\n", totalTime);
    printf("Words per minute: %d\n", wordsPerMinute);

    return 0;
}
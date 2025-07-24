//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char input[51], c;
    int i = 0, mistakes = 0, totalChars = 0, timeElapsed;
    clock_t startTime, endTime;

    printf("Welcome to the Typing Speed Test. Type the following paragraph as quickly and accurately as possible:\n\n");

    printf("Paranoia is a good thing. It's a healthy defense mechanism, and it's an important survival skill. But sometimes paranoia can cause us to doubt ourselves and our abilities. The key is to find a balance between being cautious and being confident.\n");

    printf("\nPress enter to begin.\n");
    fgets(input, 10, stdin);
    fflush(stdin);

    startTime = clock();
    while (i < 50) {
        c = getchar();
        if (c == '\n') continue;
        totalChars++;
        if (c != input[i]) mistakes++;
        i++;
    }
    endTime = clock();
    timeElapsed = (endTime - startTime) / CLOCKS_PER_SEC;
    printf("You typed %d characters in %d seconds.\n", totalChars, timeElapsed);
    printf("You made %d mistakes.\n", mistakes);
    printf("Your typing speed is %d characters per minute.\n", (int)(totalChars * 60 / timeElapsed));
    if (mistakes > 0) {
        printf("\nDon't be too hard on yourself. Remember, it's all about finding that balance between being cautious and being confident.");
    } else {
        printf("\nCongratulations! You typed the paragraph perfectly. You are clearly an expert typist. But don't get too confident - paranoia is still a good thing.");
    }

    return 0;
}
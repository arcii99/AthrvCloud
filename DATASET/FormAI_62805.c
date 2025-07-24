//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    printf("Welcome to the Typing Speed Test!\n");
    printf("Type the following sentence as fast as you can:\n");
    printf("The quick brown fox jumps over the lazy dog\n\n");

    char sentence[] = "The quick brown fox jumps over the lazy dog";
    char input[100];
    int mistakeCount = 0;
    int timeTaken = 0;
    time_t startTime, endTime;

    printf("Press Enter to start the timer");
    getchar();

    startTime = time(NULL);

    printf("Start Typing:\n");

    fgets(input, 100, stdin);

    endTime = time(NULL);
    timeTaken = (int) difftime(endTime, startTime); 

    for (int i = 0; i < strlen(input); i++) {
        if (input[i] != sentence[i]) {
            mistakeCount++;
        }
    }

    printf("\nYou typed: %s\n", input);

    if (mistakeCount > 0) {
        printf("%d Mistakes, Are you a cat on a keyboard? :P\n", mistakeCount);
    } 
    else {
        printf("%d seconds! Wow! You are fast as lightning!\n", timeTaken);
    }

    return 0;
}
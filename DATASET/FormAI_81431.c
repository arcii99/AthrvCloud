//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LENGTH 100

int main()
{
    printf("Welcome to the C Typing Speed Test\n\n");

    char sentence[MAX_LENGTH] = "The quick brown fox jumps over the lazy dog.";
    printf("Type this sentence as fast and accurately as possible: %s\n\n", sentence);

    int startTime = time(NULL);
    printf("> ");

    char input[MAX_LENGTH];
    fgets(input, MAX_LENGTH, stdin);

    int endTime = time(NULL);
    int timeTaken = endTime - startTime;

    int errors = 0;
    for (int i = 0; i < MAX_LENGTH; i++)
    {
        if (sentence[i] != input[i])
        {
            errors++;
        }
    }

    float accuracy = (float)(strlen(sentence) - errors) / strlen(sentence) * 100;
    float speed = (float)strlen(sentence) / timeTaken * 60;

    printf("\nTime taken: %d seconds\n", timeTaken);
    printf("Number of errors: %d\n", errors);
    printf("Accuracy: %.2f%%\n", accuracy);
    printf("Typing speed: %.2f words per minute\n", speed);

    return 0;
}
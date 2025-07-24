//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STRING_LENGTH 100
#define MAX_ATTEMPTS 5
#define TIMER_DURATION 30

int main()
{
    char text[] = "The quick brown fox jumps over the lazy dog";
    char user_input[MAX_STRING_LENGTH];
    double total_time_taken = 0;
    int correct_attempts = 0;

    srand(time(NULL));

    printf("\nWelcome to the Typing Speed Test!\n");
    printf("You will have to type the following sentence as fast as possible: \n");
    printf("\"%s\"\n", text);

    printf("\nYou will have to type it %d times.\n", MAX_ATTEMPTS);
    printf("Each attempt lasts %d seconds.\n", TIMER_DURATION);
    printf("\nAre you ready? Press Enter to begin.\n");
    getchar();

    for (int i = 0; i < MAX_ATTEMPTS; i++)
    {
        printf("\nAttempt %d: \n", i + 1);

        int start_time = time(NULL);

        printf("> ");
        fgets(user_input, MAX_STRING_LENGTH, stdin);

        int end_time = time(NULL);

        if (strcmp(user_input, text) == 0)
        {
            printf("\nGreat job! You typed the correct sentence!\n");
            total_time_taken += difftime(end_time, start_time);
            correct_attempts++;
        }
        else
        {
            printf("\nSorry, you typed the wrong sentence.\n");
            printf("The correct sentence was \"%s\"\n", text);
        }

        printf("\nYou took %.2lf seconds to type this sentence.\n", difftime(end_time, start_time));
        printf("Press Enter to continue.\n");
        getchar();
    }

    printf("\nCongratulations, you have completed the Typing Speed Test!\n");
    if (correct_attempts == MAX_ATTEMPTS)
    {
        printf("You typed the correct sentence in all attempts!\n");
    }
    else
    {
        printf("You typed the correct sentence in %d out of %d attempts.\n", correct_attempts, MAX_ATTEMPTS);
    }
    printf("Total time taken: %.2lf seconds\n", total_time_taken);

    return EXIT_SUCCESS;
}
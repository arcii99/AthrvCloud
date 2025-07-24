//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void typingTest()
{
    char words[10][30] = {"hello", "world", "programming", "language", "computer", "science", "keyboard", "courage", "peaceful", "nature"};
    char input[30];
    int score = 0, i, wordsTyped = 0, timeTaken = 0;
    time_t start, end;

    printf("\n\n******************Typing Speed Test******************\n\n");

    printf("Type the following words as fast as you can:\n\n");

    for (i = 0; i < 10; i++)
    {
        printf("%s ", words[i]);
    }

    printf("\n");

    time(&start);

    for (i = 0; i < 10; i++)
    {
        printf("Enter word %d: ", i + 1);
        scanf("%s", input);

        if (strcmp(input, words[i]) == 0)
        {
            printf("Correct!\n");
            score += strlen(words[i]);
            wordsTyped++;
        }
        else
        {
            printf("Incorrect!\n");
        }
    }

    time(&end);
    timeTaken = (int) difftime(end, start);

    printf("\n\n******************Results******************\n\n");
    printf("Words Typed: %d\n", wordsTyped);
    printf("Total Score: %d\n", score);
    printf("Time Taken: %d seconds\n", timeTaken);
    printf("Words per Minute: %d\n", (wordsTyped * 60) / timeTaken);
    printf("\n\n");

    printf("Do you want to try again? (y/n): ");
    char choice[2];
    scanf("%s", choice);

    // Reset the test
    if (strcmp(choice, "y") == 0)
    {
        system("clear");
        typingTest();
    }
}

int main()
{
    typingTest();

    return 0;
}
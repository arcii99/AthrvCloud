//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int i, x, y, z, w, score = 0;
    clock_t startTime, endTime;
    double timeTaken;

    printf("Welcome to the Typing Speed Test!\n");
    printf("Type the following words as fast as you can:\n");

    char *words[] = {"apple", "banana", "cherry", "date", "elderberry", "fig", "grape", "honeydew", "jackfruit", "kiwi", "lemon", "mango", "nectarine", "orange", "pear", "quince", "raspberry", "strawberry", "tangerine", "watermelon"};
    srand(time(0)); // seeding the random number generator

    for (i = 0; i < 10; i++)
    {
        x = rand() % 20; // pick a random word from the array
        printf("\n%s\n", words[x]);
        startTime = clock(); // start the timer

        char userWord[20];
        scanf("%s", userWord); // read the user's input
        endTime = clock(); // stop the timer

        timeTaken = (endTime - startTime) / (double)CLOCKS_PER_SEC;
        if (strcmp(userWord, words[x]) == 0) // compare user's input with the random word from the array
        {
            score += 10 - (int)(timeTaken * 10); // calculate the score
            printf("Correct!\n");
        }
        else
        {
            printf("Incorrect!\n");
        }
    }

    printf("\nYour score: %d\n", score);

    return 0;
}
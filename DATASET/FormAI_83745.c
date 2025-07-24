//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    char userInput;
    float time_taken;
    int i, correct=0, wrong=0;

    srand(time(0));
    printf("Welcome to the Happy Typing Speed Test! Press enter to begin.\n");
    scanf("%c", &userInput);
    printf("Type the following random sentence as fast and accurately as possible:\n");

    char sentence[100] = "Type, type, type away! This typing test is here to stay! Happy typing makes a happy day!";

    clock_t t;
    t = clock();
    for (i=0; i<strlen(sentence); i++)
    {
        printf("%c", sentence[i]);
        fflush(stdout);
        scanf(" %c", &userInput);
        if (userInput == sentence[i])
        {
            correct++;
        }
        else
        {
            wrong++;
        }
    }

    t = clock() - t;
    time_taken = ((float)t)/CLOCKS_PER_SEC;

    printf("\n\nCongratulations on finishing!\n");
    printf("Time taken: %.2f seconds\n", time_taken);
    printf("Total correct: %d\n", correct);
    printf("Total wrong: %d\n", wrong);
    printf("Accuracy: %.2f%%\n", ((float)correct*100)/(correct+wrong));
    printf("Words per minute: %.2f\n", (float)strlen(sentence)*12/(5*time_taken));
    return 0;
}
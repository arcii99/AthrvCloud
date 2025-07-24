//FormAI DATASET v1.0 Category: Math exercise ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));

    int num1 = rand() % 101; // Generate random number from 0 to 100
    int num2 = rand() % 11; // Generate random number from 0 to 10
    int ans;

    printf("Welcome to the Math Game!\n");
    printf("Your goal is to find the answer to the following equation:\n\n");

    printf("%d + %d * %d - %d = ", num1, num2, num2, num1);

    scanf("%d", &ans);

    if (ans == num1 + num2 * num2 - num1)
    {
        printf("\nCongratulations! You got the right answer!\n");
    }
    else
    {
        printf("\nSorry, that's not the right answer. The correct answer is %d.\n", num1 + num2 * num2 - num1);
    }

    printf("\nBut wait, we're not done yet!\n");
    printf("Now, we're going to do a little bit of advanced math.\n");

    printf("\nWhat is the square root of %d? ", num1 * num2);

    scanf("%d", &ans);

    if (ans == (int)(sqrt(num1 * num2)))
    {
        printf("\nWell done, you got it right!\n");
    }
    else
    {
        printf("\nSorry, that's not the right answer. The correct answer is %d.\n", (int)sqrt(num1 * num2));
    }

    printf("\nNow, let's take it up a notch!\n");
    printf("What is the value of e to the power of %d? ", num1);

    scanf("%d", &ans);

    if (ans == (int)(exp(num1)))
    {
        printf("\nAmazing, you got it right!\n");
    }
    else
    {
        printf("\nSorry, that's not the right answer. The correct answer is %d.\n", (int)exp(num1));
    }

    printf("\nWell done, you completed all the math exercises!\n");
    printf("Thanks for playing the game, and keep practicing your math skills!\n");

    return 0;
}
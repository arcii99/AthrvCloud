//FormAI DATASET v1.0 Category: Math exercise ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int num1, num2, ans, userAns;
    int correct = 0;
    int incorrect = 0;
    char runAgain;

    srand(time(NULL)); // to generate random numbers every time the program is run

    printf("Welcome to the Math exercise program!\n");

    do
    {
        num1 = rand() % 100; // generates a random number between 0-99
        num2 = rand() % 100; // generates a random number between 0-99

        printf("What is %d + %d?\n", num1, num2);
        scanf("%d", &userAns);

        ans = num1 + num2;

        if(userAns == ans)
        {
            printf("Correct!\n");
            correct++;
        }
        else
        {
            printf("Incorrect, the correct answer is %d.\n", ans);
            incorrect++;
        }

        printf("Do you want to solve another problem? (Y/N)\n");
        scanf(" %c", &runAgain);

    } while(runAgain == 'Y' || runAgain == 'y');

    printf("Thanks for playing!\n");
    printf("You got %d correct and %d incorrect.\n", correct, incorrect);

    return 0;
}
//FormAI DATASET v1.0 Category: Math exercise ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Initialize the random number generator.
    srand(time(NULL));

    // Generate two random numbers between 1 and 10.
    int num1 = rand() % 10 + 1;
    int num2 = rand() % 10 + 1;

    // Ask the user to solve the math problem.
    printf("What is %d + %d? ", num1, num2);

    // Accept the user's answer.
    int answer;
    scanf("%d", &answer);

    // Check if the user's answer is correct.
    if (answer == num1 + num2)
    {
        // Congratulate the user.
        printf("Correct! You're a math genius!\n");
    }
    else
    {
        // Inform the user of their mistake.
        printf("Sorry, that's incorrect. The correct answer is %d.\n", num1 + num2);
    }

    // Wait for the user to read the result.
    printf("Press any key to exit.");
    getchar();

    return 0;
}
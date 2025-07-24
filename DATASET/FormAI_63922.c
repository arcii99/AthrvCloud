//FormAI DATASET v1.0 Category: Math exercise ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Generate two random numbers between 1 and 10
    srand(time(NULL));
    int num1 = rand() % 10 + 1;
    int num2 = rand() % 10 + 1;

    // Ask the user to solve the math problem
    printf("What is the value of %d + %d?\n", num1, num2);
    int answer;
    scanf("%d", &answer);

    // Check if the user's answer is correct
    int result = num1 + num2;
    if (answer == result)
    {
        printf("Correct!\n");
    }
    else
    {
        printf("Sorry, the correct answer is %d.\n", result);
    }

    return 0;
}
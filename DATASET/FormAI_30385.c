//FormAI DATASET v1.0 Category: Math exercise ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); // Initialize random number generator
    int num1 = rand() % 21; // Generate a random number between 0 and 20
    int num2 = rand() % 21;
    int sum = num1 + num2;
    int product = num1 * num2;

    printf("Welcome to the exciting math game! \n");
    printf("You will be given two random numbers between 0 and 20. \n");
    printf("Your task is to solve the following problems: \n");
    printf("What is the sum of %d and %d? \n", num1, num2);

    int user_answer; // User's answer
    scanf("%d", &user_answer); // Read user input
    if (user_answer == sum)
    {
        printf("Correct! \n");
    }
    else
    {
        printf("Sorry, the correct answer is %d. \n", sum);
    }

    printf("What is the product of %d and %d? \n", num1, num2);

    scanf("%d", &user_answer); // Read user input
    if (user_answer == product)
    {
        printf("Great job! \n");
    }
    else
    {
        printf("Sorry, the correct answer is %d. \n", product);
    }

    printf("Thank you for playing the exciting math game! \n");

    return 0;
}
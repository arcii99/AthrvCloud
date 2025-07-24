//FormAI DATASET v1.0 Category: Arithmetic ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Let's generate two random numbers
    srand(time(NULL));
    int num1 = rand() % 100;
    int num2 = rand() % 100;

    printf("Welcome to my Arithm-EGG-tic program!\n");
    printf("We'll start by generating two random numbers for you...\n");
    printf("Number 1: %d\nNumber 2: %d\n", num1, num2);
    printf("\n\n\nNow let's do some funny math!\n\n\n");

    int answer1 = num1 + num2;
    int answer2 = num1 - num2;
    int answer3 = num1 * num2;
    int answer4 = num1 / num2;

    printf("Okay, here we go:\n\n");
    printf("%d + %d = %d\n", num1, num2, answer1);
    printf("%d - %d = %d\n", num1, num2, answer2);
    printf("%d * %d = %d\n", num1, num2, answer3);

    if (num2 == 0)
    {
        printf("Oh no, looks like we can't divide by zero. Let's try that again...\n\n");
        main(); // Recursive call to try again
    }
    else
    {
        printf("%d / %d = %d\n", num1, num2, answer4);
    }

    printf("\n\n\nThanks for playing Arithm-EGG-tic!\n");
    printf("Come back soon for more egg-citing math adventures!\n");

    return 0;
}
//FormAI DATASET v1.0 Category: Math exercise ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main()
{
    srand(time(0));  //Seed random number generator
    
    printf("BRAVE MATH EXERCISES!\n");

    int num1 = rand() % 50;    //Generate first random number 
    int num2 = rand() % 50;    //Generate second random number
    int result = num1 + num2;  //Calculate sum of random numbers

    //Display addition problem to the user
    printf("\nWhat is the result of adding %d and %d?\n", num1, num2);

    int answer;
    scanf("%d", &answer);  //Get user's answer

    //Check if user's answer is correct
    if(answer == result)
    {
        printf("\nYou are brave! Your answer is CORRECT!\n");
    }
    else
    {
        printf("\nYou are brave, but your answer is WRONG.\n");
        printf("The correct answer is %d.\n", result);
    }

    //Generate third random number
    int num3 = rand() % 10 + 1;

    //Calculate square of third random number
    double square = pow(num3, 2);

    //Display square problem to the user
    printf("\nWhat is the square of %d?\n", num3);

    double answer2;
    scanf("%lf", &answer2);  //Get user's answer

    //Check if user's answer is correct
    if(answer2 == square)
    {
        printf("\nYou are brave! Your answer is CORRECT!\n");
    }
    else
    {
        printf("\nYou are brave, but your answer is WRONG.\n");
        printf("The correct answer is %.2lf.\n", square);
    }

    //Generate fourth random number
    int num4 = rand() % 50 + 1;

    //Calculate cube of fourth random number
    double cube = pow(num4, 3);

    //Display cube problem to the user
    printf("\nWhat is the cube of %d?\n", num4);

    double answer3;
    scanf("%lf", &answer3);  //Get user's answer

    //Check if user's answer is correct
    if(answer3 == cube)
    {
        printf("\nYou are brave! Your answer is CORRECT!\n");
    }
    else
    {
        printf("\nYou are brave, but your answer is WRONG.\n");
        printf("The correct answer is %.2lf.\n", cube);
    }

    printf("\nBRAVE MATH EXERCISES COMPLETED!\n");

    return 0;
}
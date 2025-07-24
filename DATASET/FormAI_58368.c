//FormAI DATASET v1.0 Category: Math exercise ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    int num1 = rand() % 100; //Generate a random number between 0 and 99
    int num2 = rand() % 100; //Generate a random number between 0 and 99

    printf("Welcome to the paranoid math game!\n");
    printf("I'm going to give you two numbers, and you must add them together.\n");
    printf("But beware, there's a chance I'll try to trick you!\n");
    printf("If the sum I give you doesn't match what you calculated, you lose.\n");

    int sum = num1 + num2;
    int player_answer;

    int chance_of_trick = rand() % 101; //Generate a random number between 0 and 100
    if (chance_of_trick < 10) //If the chance of a trick is less than 10%, then try to trick the player
    {
        printf("Watch out! My calculator might be malfunctioning...\n");
        int trick_num = rand() % 10; //Generate a random number between 0 and 9
        sum += trick_num; //Add the trick number to the sum
    }

    printf("\n%d + %d = ", num1, num2);
    scanf("%d", &player_answer);
    printf("\n");

    if (player_answer == sum)
    {
        printf("Congratulations! You won. You're smarter than my calculator!\n");
    }
    else
    {
        printf("Sorry, you lose. My calculator must have made a mistake...\n");
    }

    return 0;
}
//FormAI DATASET v1.0 Category: Math exercise ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); //initialize random number generator with current time
    int num1 = rand() % 20; //generate a random number between 0-19
    int num2 = rand() % 10; //generate another random number between 0-9
    int ans; //to store user's answer
    printf("Exercise: %d + %d = ?\n", num1, num2); //display the exercise
    scanf("%d", &ans); //get user's input
    int correct_ans = num1 + num2; //calculate the correct answer

    if (ans == correct_ans) //if user's answer is correct
    {
        printf("Congratulations! Your answer is correct!\n");
    }
    else //if user's answer is incorrect
    {
        printf("Sorry, your answer is incorrect. The correct answer is %d\n", correct_ans);
    }

    return 0;
}
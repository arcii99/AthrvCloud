//FormAI DATASET v1.0 Category: Math exercise ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main()
{
    char name[20];
    printf("Welcome to the wackiest math test ever!\n");
    printf("What's your name?\n");
    scanf("%s", name);
    printf("Hi %s! Let's get started.\n", name);

    int difficulty;
    printf("First up, choose your difficulty level from 1 to 10: ");
    scanf("%d", &difficulty);
    printf("You've chosen level %d. Good luck!\n", difficulty);

    int score = 0;
    srand(time(NULL));
 
    for(int i = 1; i <= 10; i++)
    {
        int num1 = rand() % (int)pow(10, difficulty);
        int num2 = rand() % (int)pow(10, difficulty);
        char operator;
        if(i%2 == 0)
        {
            operator = '-';
        }
        else
        {
            operator = '+';
        }
         
        int correct_answer;
        if(operator == '+')
        {
            correct_answer = num1 + num2;
        }
        else
        {
            correct_answer = num1 - num2;
        }
 
        int user_answer;
        printf("\nQuestion %d: What is %d %c %d?\n", 
            i, num1, operator, num2);
        scanf("%d", &user_answer);
 
        if(user_answer == correct_answer)
        {
            printf("Correct! You're a math whiz!\n");
            score++;
        }
        else
        {
            printf("Wrong! The correct answer is %d. Better luck next time!\n", correct_answer);
        }
    }
 
    printf("\nGreat job, %s!\n", name);
    printf("Your final score is %d out of 10. Thanks for playing!\n", score);
 
    return 0;
}
//FormAI DATASET v1.0 Category: Online Examination System ; Style: interoperable
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    char ans;
    int i, score = 0;
    time_t t;
    srand((unsigned)time(&t)); //initialize random number generator

    printf("Welcome to the C Online Examination System!\n\n");
    printf("This exam will consist of 10 multiple choice questions.\n");
    printf("You will have four options for each question. Please enter the corresponding letter of your answer.\n\n");

    for (i = 1; i <= 10; i++)
    {
        int num1 = rand() % 10; //generate two random numbers for the question
        int num2 = rand() % 10;

        printf("Question %d: What is the result of %d + %d ?\n", i, num1, num2);
        printf("A) %d\nB) %d\nC) %d\nD) %d\n", num1 + num2, num1 - num2, num1 * num2, num1 / num2);

        printf("Answer: ");
        scanf(" %c", &ans); //get user's answer

        if (ans == 'A' || ans == 'a')
        {
            printf("Correct!\n");
            score++;
        }
        else
        {
            printf("Incorrect. The correct answer is A) %d.\n", num1 + num2);
        }
        printf("\n");
    }

    printf("You have completed the exam.\n");
    printf("Your score is %d out of 10.\n", score);

    return 0;
}
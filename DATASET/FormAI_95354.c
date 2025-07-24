//FormAI DATASET v1.0 Category: Online Examination System ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int i, choice, score = 0;
    char answers[] = {'C', 'A', 'B', 'D', 'A', 'C', 'D', 'B', 'C', 'A'};
    
    srand(time(NULL)); //initialize random seed

    printf("Welcome to the Online Examination System\n\n");
    printf("You will be given 10 multiple choice questions to answer.\n\n");

    for (i = 1; i <= 10; i++)
    {
        int question = rand() % 10; //generate random question
        printf("%d) What is the capital of France?\n", i);
        printf("A) Paris\nB) Berlin\nC) Madrid\nD) Rome\n");
        printf("Enter your choice: ");

        do {
            choice = getchar(); //read user input
        } while (choice == '\n'); //skip new lines

        if (choice == answers[question])
        {
            printf("Correct!\n\n");
            score++;
        }
        else
        {
            printf("Incorrect! The correct answer is %c\n\n", answers[question]);
        }
    }

    printf("Thank you for taking the exam. Your score is %d out of 10.\n", score);

    return 0;
}
//FormAI DATASET v1.0 Category: Online Examination System ; Style: artistic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_QUESTIONS 50
#define MAX_OPTIONS 4

int main()
{
    char questions[MAX_QUESTIONS][100];
    char options[MAX_QUESTIONS][MAX_OPTIONS][50];
    int answers[MAX_QUESTIONS];
    int student_answer;
    int marks=0;
    int i,j;
    char ch;

    printf("\nWelcome to Online Examination System!\n\n");

    //Adding questions with options and answers
    strcpy(questions[0],"1. What is the capital of India?");
    strcpy(options[0][0],"A. Mumbai");
    strcpy(options[0][1],"B. Delhi");
    strcpy(options[0][2],"C. Kolkata");
    strcpy(options[0][3],"D. Bangalore");
    answers[0]=2;

    strcpy(questions[1],"2. Which is the largest continent?");
    strcpy(options[1][0],"A. Asia");
    strcpy(options[1][1],"B. North America");
    strcpy(options[1][2],"C. South America");
    strcpy(options[1][3],"D. Africa");
    answers[1]=1;

    strcpy(questions[2],"3. Who invented telephone?");
    strcpy(options[2][0],"A. Thomas Edison");
    strcpy(options[2][1],"B. Michael Faraday");
    strcpy(options[2][2],"C. Isaac Newton");
    strcpy(options[2][3],"D. Alexander Graham Bell");
    answers[2]=4;

    //Displaying questions with options
    for(i=0;i<MAX_QUESTIONS;i++)
    {
        if(strlen(questions[i])>0)
        {
            printf("%s\n",questions[i]);
            for(j=0;j<MAX_OPTIONS;j++)
                printf("%s ",options[i][j]);
            printf("\n");
        }
    }

    //Taking answers from student
    printf("\nEnter your answers:\n");
    for(i=0;i<MAX_QUESTIONS;i++)
    {
        if(strlen(questions[i])>0)
        {
            printf("%s ",questions[i]);
            scanf("%d",&student_answer);
            if(student_answer == answers[i])
                marks++;
        }
    }

    //Displaying marks
    printf("\nYour marks: %d\n",marks);

    //Giving feedback
    if(marks==MAX_QUESTIONS)
        printf("\nCongratulations! You have scored full marks.\n");
    else if(marks>=(MAX_QUESTIONS/2))
        printf("\nGood job! You have passed.\n");
    else
        printf("\nBetter luck next time.\n");

    printf("\nThank you for participating in the exam.\n\n");
    return 0;
}
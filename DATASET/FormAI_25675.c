//FormAI DATASET v1.0 Category: Online Examination System ; Style: enthusiastic
#include<stdio.h>
#include<string.h>

int main()
{
    char questions[5][100], options[5][4][100], answers[5][100];
    int i, j, marks=0, choice, response[5], correct[5]={4, 3, 2, 1, 3};

    strcpy(questions[0], "What is the command to compile C program on Linux?");
    strcpy(options[0][0], "gcc");
    strcpy(options[0][1], "exe");
    strcpy(options[0][2], "java");
    strcpy(options[0][3], "python");
    strcpy(answers[0], "gcc");

    strcpy(questions[1], "How do you declare a variable in C?");
    strcpy(options[1][0], "int");
    strcpy(options[1][1], "char");
    strcpy(options[1][2], "float");
    strcpy(options[1][3], "All of the above");
    strcpy(answers[1], "All of the above");

    strcpy(questions[2], "What is the purpose of 'printf' function?");
    strcpy(options[2][0], "to input value");
    strcpy(options[2][1], "to output value");
    strcpy(options[2][2], "to define function");
    strcpy(options[2][3], "to assign value");
    strcpy(answers[2], "to output value");

    strcpy(questions[3], "What is the use of 'scanf' function?");
    strcpy(options[3][0], "to output value");
    strcpy(options[3][1], "to input value");
    strcpy(options[3][2], "to define function");
    strcpy(options[3][3], "to assign value");
    strcpy(answers[3], "to input value");

    strcpy(questions[4], "Which of the following is not a data type in C?");
    strcpy(options[4][0], "float");
    strcpy(options[4][1], "int");
    strcpy(options[4][2], "double");
    strcpy(options[4][3], "string");
    strcpy(answers[4], "string");

    printf("\n\n***** Welcome to C Online Examination System *****\n\n");

    for(i=0; i<5; i++)
    {
        printf("\n%d. %s\n", i+1, questions[i]);
        printf("\t1. %s\n", options[i][0]);
        printf("\t2. %s\n", options[i][1]);
        printf("\t3. %s\n", options[i][2]);
        printf("\t4. %s\n", options[i][3]);

        printf("\nEnter your choice (1-4): ");
        scanf("%d", &choice);

        response[i]=choice;

        if(strcmp(options[i][choice-1], answers[i])==0)
        {
            marks+=10;
        }
    }

    printf("\n\n***** Results *****\n\n");

    for(i=0; i<5; i++)
    {
        printf("\n%d. %s", i+1, questions[i]);
        printf("\n\tYour answer: %s", options[i][response[i]-1]);
        printf("\n\tCorrect answer: %s", answers[i]);
    }

    printf("\n\nYour Total Marks: %d/50\n\n", marks);

    if(marks>=40)
    {
        printf("Congratulations, You passed the exam!\n\n");
    }
    else
    {
        printf("Sorry, You failed the exam!\n\n");
    }

    return 0;
}
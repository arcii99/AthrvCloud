//FormAI DATASET v1.0 Category: Online Examination System ; Style: curious
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int questions[10][6], i, j, k, l, m, marks=0;
    char answer;
    srand(time(0));
    printf("**** Welcome to the Online Examination System ****\n\n");
    printf("There are 10 Multiple Choice Questions\n");
    printf("Each question has 5 options (A, B, C, D, E)\n");
    printf("Choose the correct option to get 1 mark\n\n");
    for(i=0;i<10;i++)
    {
        questions[i][0] = i+1;
        for(j=1;j<6;j++)
        {
            questions[i][j] = rand()%5+65;
        }
    }
    for(i=0;i<10;i++)
    {
        printf("Question %d:\n",questions[i][0]);
        printf("Option A : %c\n",questions[i][1]);
        printf("Option B : %c\n",questions[i][2]);
        printf("Option C : %c\n",questions[i][3]);
        printf("Option D : %c\n",questions[i][4]);
        printf("Option E : %c\n",questions[i][5]);
        printf("Enter your answer : ");
        scanf("%c",&answer);
        if(answer==questions[i][rand()%5+1])
        {
            marks++;
            printf("Correct Answer!\n");
        }
        else
        {
            printf("Wrong Answer!\n");
        }
    }
    printf("\nYou have scored %d out of 10\n",marks);
    printf("Thank you for taking the test!\n");
    return 0;
}
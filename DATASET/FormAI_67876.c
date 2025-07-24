//FormAI DATASET v1.0 Category: Online Examination System ; Style: irregular
#include<stdio.h>
#include<stdlib.h>

int main()
{
    //welcome message
    printf("Welcome to the Online Examination System");

    //taking input from user
    char name[20];
    printf("\nEnter your Name: ");
    scanf("%s",&name);

    //randomly generating questions
    int num1,num2,result,answer,question_number;
    for(int i=1;i<=5;i++)
    {
        //generating random numbers and question
        num1=rand()%100;
        num2=rand()%100;
        question_number=i;
        result=num1+num2;

        //asking question
        printf("\n\nQuestion:%d ",question_number);
        printf("%d + %d = ? ",num1,num2);
        scanf("%d",&answer);

        //checking answer
        if(answer==result)
            printf("\nCorrect Answer!");
        else
            printf("\nWrong Answer! Correct Answer is %d",result);
    }

    //giving final result
    printf("\n\nThank you for taking the exam %s!",name);
    printf("\n\nYour Score is: 4/5");

    return 0;
}
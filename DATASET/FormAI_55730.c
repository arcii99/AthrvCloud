//FormAI DATASET v1.0 Category: Online Examination System ; Style: romantic
#include<stdio.h>
#include<string.h>
void main()
{
    int i,j,k,choice,count=0;
    char q[50][500],a[50][50],s[500];
    printf("Welcome to the Online Examination System!\n");
    printf("Please enter the number of questions you want to add: ");
    scanf("%d",&k);
    for(i=0;i<k;i++)
    {
        printf("Enter the question %d: ",i+1);
        scanf(" %[^\n]s",q[i]);
        printf("Enter the answer for question %d: ",i+1);
        scanf(" %[^\n]s",a[i]);
    }
    printf("\n*****************************************************************\n");
    printf("There are %d questions in the examination.\n",k);
    printf("Please select the correct option to answer each question.\n");
    printf("\n*****************************************************************\n");
    for(i=0;i<k;i++)
    {
        printf("Question %d: %s\n",i+1,q[i]);
        printf("A. %s\n",a[i]);
        printf("B. Random\n");
        printf("C. Random\n");
        printf("D. Random\n");
        printf("Please enter your answer: ");
        scanf(" %c",&s[i]);
        if(s[i]==a[i][0])
        {
            printf("Correct answer! \n");
            count++;
        }
        else
        {
            printf("Wrong answer! \n");
        }
    }
    printf("\n*****************************************************************\n");
    printf("Your result is:\n");
    printf("Number of Correct Answers: %d\n",count);
    printf("Number of Wrong Answers: %d\n",k-count);
    printf("Your Percentage is: %.2f%%\n",(float)count/k*100);
    printf("\n*****************************************************************\n");
    printf("Thank you for taking the examination!\n");
}
//FormAI DATASET v1.0 Category: Online Examination System ; Style: creative
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct question
{
    char q[100];
    char a[50][100];
    char correct_ans[100];
};

struct student
{
    char name[30];
    int score;
};

int main()
{
    FILE *fp;
    struct question q_array[10];
    struct student s;
    int i,j,k,ans,option,marks;

    //Reading Questions from File
    fp = fopen("questions.txt","r");
    if(fp==NULL)
    {
        printf("Error in opening file\n");
        exit(0);
    }

    for(i=0;i<10;i++)
    {
        fgets(q_array[i].q,100,fp);
        for(j=0;j<4;j++)
        {
            fgets(q_array[i].a[j],100,fp);
        }
        fgets(q_array[i].correct_ans,100,fp);
    }
    fclose(fp);

    // Test starts

    printf("\nWelcome to Online Examination System!\n");
    printf("Enter your name: ");
    scanf("%s",s.name);
    s.score=0;

    for(i=0;i<10;i++)
    {
        printf("\nQ%d. %s",i+1,q_array[i].q);
        for(j=0;j<4;j++)
        {
            printf("%d. %s",j+1,q_array[i].a[j]);
        }
        printf("Enter your answer: ");
        scanf("%d",&ans);

        if(strcmp(q_array[i].a[ans-1],q_array[i].correct_ans)==0)
        {
            s.score+=10;
            printf("\nCorrect Answer!\n");
        }
        else
        {
            printf("\nWrong Answer!\n");
        }
    }

    //Result

    printf("\nResult:\n");
    printf("Name: %s\n",s.name);
    printf("Score: %d/100\n",s.score);

    if(s.score>=70)
    {
        printf("Congratulations! You have cleared the examination.\n");
    }
    else
    {
        printf("Sorry! You did not clear the examination.\n");
    }

    return 0;
}
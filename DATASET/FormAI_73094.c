//FormAI DATASET v1.0 Category: Online Examination System ; Style: imaginative
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct question{
char q[100];
char a[50];
char c1[50];
char c2[50];
char c3[50];
};

int main()
{
    int score=0;
    int choice;
    char ans[50];
    struct question arr[10];
    strcpy(arr[0].q, "Which one is not a programming language?\n");
    strcpy(arr[0].a, "HTML");
    strcpy(arr[0].c1, "C++");
    strcpy(arr[0].c2, "Java");
    strcpy(arr[0].c3, "HTML");

    strcpy(arr[1].q, "What is the output of 3+2*5?\n");
    strcpy(arr[1].a, "13");
    strcpy(arr[1].c1, "25");
    strcpy(arr[1].c2, "13");
    strcpy(arr[1].c3, "15");

    strcpy(arr[2].q, "Which data type has the largest storage size?\n");
    strcpy(arr[2].a, "long double");
    strcpy(arr[2].c1, "double");
    strcpy(arr[2].c2, "float");
    strcpy(arr[2].c3, "long double");

    strcpy(arr[3].q, "Which one of the following is not a storage class?\n");
    strcpy(arr[3].a, "register");
    strcpy(arr[3].c1, "static");
    strcpy(arr[3].c2, "auto");
    strcpy(arr[3].c3, "register");

    strcpy(arr[4].q, "What is the output of 2<<3?\n");
    strcpy(arr[4].a, "16");
    strcpy(arr[4].c1, "6");
    strcpy(arr[4].c2, "8");
    strcpy(arr[4].c3, "16");

    strcpy(arr[5].q, "What type of operator is ++?\n");
    strcpy(arr[5].a, "unary");
    strcpy(arr[5].c1, "binary");
    strcpy(arr[5].c2, "ternary");
    strcpy(arr[5].c3, "unary");

    strcpy(arr[6].q, "Which header file is used for input and output operations?\n");
    strcpy(arr[6].a, "stdio.h");
    strcpy(arr[6].c1, "string.h");
    strcpy(arr[6].c2, "stdlib.h");
    strcpy(arr[6].c3, "stdio.h");

    strcpy(arr[7].q, "What is the output of the following code?\n int a=5,b=3;\n a=b++ + ++b + a++;\n printf('%d',a);\n");
    strcpy(arr[7].a, "13");
    strcpy(arr[7].c1, "14");
    strcpy(arr[7].c2, "15");
    strcpy(arr[7].c3, "16");

    strcpy(arr[8].q, "Which one of the following is not a keyword in C?\n");
    strcpy(arr[8].a, "cin");
    strcpy(arr[8].c1, "auto");
    strcpy(arr[8].c2, "static");
    strcpy(arr[8].c3, "cin");

    strcpy(arr[9].q, "What is the output of 'printf(''%c'',''a''+1);'?\n");
    strcpy(arr[9].a, "b");
    strcpy(arr[9].c1, "a");
    strcpy(arr[9].c2, "c");
    strcpy(arr[9].c3, "d");

    printf("\t\tWelcome to C Online Exam\n\n");
    printf("This exam consist of 10 questions. Each question carries 10 points.\n\n");

    for(int i=0;i<10;i++)
    {
        printf("%d. %s\n",i+1,arr[i].q);
        printf("A. %s\n",arr[i].c1);
        printf("B. %s\n",arr[i].c2);
        printf("C. %s\n",arr[i].c3);
        printf("Enter your choice(A/B/C): ");
        scanf("%d",&choice);
        printf("\n");
        if(choice==1)
            strcpy(ans,arr[i].c1);
        else if(choice==2)
            strcpy(ans,arr[i].c2);
        else if(choice==3)
            strcpy(ans,arr[i].c3);

        if(strcmp(ans,arr[i].a)==0)
        {
            printf("Correct Answer!\n\n");
            score+=10;
        }
        else
            printf("Wrong Answer!\n\n");
    }

    printf("\nYour Score: %d/100\n",score);
    if(score>=50)
        printf("Congratulations! You have passed the exam.\n");
    else
        printf("Sorry! You have failed the exam.\n");

    return 0;
}
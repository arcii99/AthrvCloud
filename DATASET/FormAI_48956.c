//FormAI DATASET v1.0 Category: Pattern printing ; Style: grateful
#include<stdio.h>

int main()
{
    printf("I am grateful to write a program for you today!\n");

    for(int i=1; i<=5; i++)
    {
        for(int j=1; j<=i; j++)
        {
            printf("* ");
        }
        printf("\n");
    }

    printf("\nI am grateful for the opportunity to write a pattern printing program for you!");

    printf("\nHere's a unique pattern:\n\n");

    for(int i=1; i<=5; i++)
    {
        for(int j=1; j<=5; j++)
        {
            if(i==1 || i==5 || j==1 || j==5 || i==j || i+j==6)
            {
                printf("* ");
            }
            else
            {
                printf("  ");
            }
        }
        printf("\n");
    }

    printf("\nHope you liked the pattern!");

    printf("\nI am grateful for your time and for giving me the opportunity to serve you today.");

    return 0;
}
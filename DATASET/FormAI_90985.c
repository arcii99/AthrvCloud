//FormAI DATASET v1.0 Category: Pattern printing ; Style: brave
#include<stdio.h>

int main()
{
    printf("I am a C Pattern printing program. Let's begin!\n\n");
    
    //Printing Pattern in Brave style
    for(int i=1;i<=10;i++)
    {
        for(int j=1;j<=10-i;j++)
        {
            printf("  ");
        }
        for(int k=1;k<=i;k++)
        {
            printf("* ");
        }
        printf("\n");
    }
    for(int i=9;i>=1;i--)
    {
        for(int j=1;j<=10-i;j++)
        {
            printf("  ");
        }
        for(int k=1;k<=i;k++)
        {
            printf("* ");
        }
        printf("\n");
    }
    printf("\n\n");
    
    //Printing Pattern in a different style
    printf("I am not afraid to try different styles!\n\n");
    
    for(int i=1;i<=10;i++)
    {
        for(int j=1;j<=i;j++)
        {
            printf("%d ",j);
        }
        printf("\n");
    }
    for(int i=9;i>=1;i--)
    {
        for(int j=1;j<=i;j++)
        {
            printf("%d ",j);
        }
        printf("\n");
    }
   
    printf("\nYay! The program is complete!\n");
    
    return 0;
}
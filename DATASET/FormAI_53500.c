//FormAI DATASET v1.0 Category: Pattern printing ; Style: brave
#include<stdio.h>

int main()
{
    printf("Welcome to the C Pattern Printing Program:\n\n");

    int a = 1; //to keep track of odd and even numbers in the pattern
    
    //Printing the first part of the pattern 
    for(int i = 1; i <= 9; i += 2)
    {
        for(int j = 9; j > i; j -= 2)
        {
            printf("  ");
        }
        for(int k = 1; k <= i; k++)
        {
            if(a % 2 == 0)
            {
                printf("- ");
            }
            else
            {
                printf("| ");
            }
            a++;
        }
        printf("\n");
    }
    
    a = 1; //resetting the value of 'a' for the second part of the pattern
    
    //Printing the second part of the pattern
    for(int i = 7; i >= 1; i -= 2)
    {
        for(int j = 7; j >= i; j -= 2)
        {
            printf("  ");
        }
        for(int k = 1; k <= i; k++)
        {
            if(a % 2 == 0)
            {
                printf("- ");
            }
            else
            {
                printf("| ");
            }
            a++;
        }
        printf("\n");
    }
    
    printf("\n\n***Pattern Printing completed successfully!!!***\n\n");
    
    return 0;
}
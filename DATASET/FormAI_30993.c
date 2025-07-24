//FormAI DATASET v1.0 Category: Pattern printing ; Style: enthusiastic
#include <stdio.h> //Including the standard input-output library

int main() //Declaring the main function
{
    printf("Let's create a unique pattern with 'C'\n\n"); //Greeting message
    int i, j, k; //Declaring integer variables

    // Upper part of the pattern
    for (i = 1; i <= 5; i++) //Outer loop
    {
        for (j = 1; j <= i; j++) //Inner loop for spaces
        {
            printf(" "); //Printing spaces
        }
        printf("C"); //Printing the letter 'C'
        if (i == 5) //Checking if we are at the last iteration
        {
            for (j = 1; j <= 4; j++) //Printing four letters 'C'
            {
                printf("C");
            }
            printf("\n"); //Moving to next line
            break; //Breaking the loop
        }
        printf("\n"); //Moving to next line
    }

    // Lower part of the pattern
    for (i = 4; i >= 1; i--) //Outer loop
    {
        for (j = 1; j <= i; j++) //Inner loop for spaces
        {
            printf(" "); //Printing spaces
        }
        printf("C"); //Printing the letter 'C'
        if (i == 1) //Checking if we are at the last iteration
        {
            for (j = 1; j <= 4; j++) //Printing four letters 'C'
            {
                printf("C");
            }
            printf("\n"); //Moving to next line
            break; //Breaking the loop
        }
        printf("\n"); //Moving to next line
    }

    printf("\nPattern created successfully!"); //Closing message

    return 0; //Returning 0 if everything executed properly
}
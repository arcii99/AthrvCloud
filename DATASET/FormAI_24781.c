//FormAI DATASET v1.0 Category: Pattern printing ; Style: minimalist
#include<stdio.h>

int main()
{
    int count, i, j, space = 21; //defining variables
    for(count = 1; count <= 10; count++) //for loop for number of lines
    {
        space--; //decreasing space for each line
        for(j = 1; j <= space; j++) //for loop for printing spaces
        {
            printf(" ");
        }
        for(i = 1; i <= count; i++) //for loop for printing pattern
        {
            printf("* ");
        }
        printf("\n"); //moving to next line
    }

    space = 11; //resetting space variable
    for(count = 10; count >= 1; count--) //for loop for number of lines
    {
        space++; //increasing space for each line
        for(j = 1; j <= space; j++) //for loop for printing spaces
        {
            printf(" ");
        }
        for(i = 1; i <= count; i++) //for loop for printing pattern
        {
            printf("* ");
        }
        printf("\n"); //moving to next line
    }
    return 0; //program executed successfully
}
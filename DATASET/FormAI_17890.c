//FormAI DATASET v1.0 Category: Pattern printing ; Style: synchronous
#include <stdio.h>

int main()
{
    int i, j, n = 10; // n represents the height of the pattern (number of rows)
    
    for(i=1;i<=n;i++) // loop through each row
    {
        for(j=1;j<=n;j++) // loop through each column
        {
            if(i==1 || i==n || j==1 || j==n) // print * only for the first and last rows and columns
            {
                printf("*"); 
            }
            else if(i==j || j==(n-i+1)) // print the diagonal lines
            {
                printf("\\"); 
            }
            else // print spaces for all other positions
            {
                printf(" "); 
            }
        }
        printf("\n"); // go to the next line after each row
    }
    
    return 0;
}
//FormAI DATASET v1.0 Category: Pattern printing ; Style: standalone
#include <stdio.h>

int main()
{
    int rows = 7; //Number of rows in our pattern
    
    for(int i=1; i<=rows; i++) //Iterating over each row
    {
        //Printing spaces at the beginning of the row
        for(int j=1; j<=(rows-i); j++)
            printf("  ");
        
        //Printing digits from 1 to i
        for(int j=1; j<=i; j++)
            printf("%d ", j);
        
        //Printing digits from i-1 to 1
        for(int j=i-1; j>=1; j--)
            printf("%d ", j);
        
        //Printing spaces after the digits
        for(int j=1; j<=(rows-i); j++)
            printf("  ");
        
        //Printing a newline character at the end of the row
        printf("\n");
    }
    
    return 0;
}
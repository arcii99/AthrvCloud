//FormAI DATASET v1.0 Category: Pattern printing ; Style: peaceful
#include <stdio.h>
//Defining the main function
int main()
{
    int row, col, n;
    //Getting input from the user
    printf("Enter the number of rows: ");
    scanf("%d", &n);
    for (row = 1; row <= n; row++)   //Outer loop for number of rows
    {
        for (col = 1; col <= n; col++)   //Inner loop for number of columns
        {
            if (row == 1 || row == n || col == 1 || col == n || col == row || col == n - row + 1)   //Condition for printing * symbol
                printf("* ");   //Printing * symbol
            else
                printf("  ");   //Printing space
        }
        printf("\n");   //Printing newline character
    }
    return 0;
}
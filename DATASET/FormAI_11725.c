//FormAI DATASET v1.0 Category: Pattern printing ; Style: genious
#include<stdio.h>
int main()
{
    //Variable Declaration
    int i, j, rows;

    //User Input
    printf("Enter the number of rows you want to print in the pattern: ");
    scanf("%d", &rows);

    //For Loop for First Half
    for(i=1;i<=rows;i++)
    {
        for(j=1;j<=i;j++)
        {
            printf("* ");
        }
        printf("\n");
    }

    //For Loop for Second Half
    for(i=rows-1;i>=1;i--)
    {
        for(j=1;j<=i;j++)
        {
            printf("* ");
        }
        printf("\n");
    }

    return 0; //Program Execution complete!
}
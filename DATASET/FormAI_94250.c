//FormAI DATASET v1.0 Category: Pattern printing ; Style: automated
#include <stdio.h>

int main()
{
    int i, j, k;

    for(i=1;i<=4;i++) //Loop for top half of pattern
    {
        k = 65; //Assigning ASCII code of 'A' to k
        for(j=1;j<=i;j++) //Loop for printing characters in each row
        {
            printf("%c ", k); //Printing character
            k++; //Incrementing k to print next character
        }
        printf("\n"); //Moving to next line
    }

    for(i=3;i>=1;i--) //Loop for bottom half of pattern
    {
        k = 65;
        for(j=1;j<=i;j++)
        {
            printf("%c ", k);
            k++;
        }
        printf("\n");
    }

    return 0;
}
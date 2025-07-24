//FormAI DATASET v1.0 Category: Pattern printing ; Style: intelligent
#include <stdio.h>

// Function for pattern printing
void patternPrinting(int n)
{
    int i, j, k, l;
    char c = 'A';
    
    // Loop for printing pattern
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n-i; j++)
        {
            printf(" ");
        }
        for(k=1; k<=i; k++)
        {
            printf("%c", c++);
        }
        c -= 1;
        for(l=1; l<i; l++)
        {
            printf("%c", --c);
        }
        printf("\n");
        c = 'A';
    }
}

int main()
{
    int n;

    printf("Enter the number of rows for pattern printing: ");
    scanf("%d", &n);
    
    // Checking if the entered number is odd
    if(n%2 == 1)
    {
        // Calling the pattern printing function and passing the entered number as argument
        patternPrinting(n);
    }
    else
    {
        printf("Please input an odd number for pattern printing.");
    }
        
    return 0;
}
//FormAI DATASET v1.0 Category: Pattern printing ; Style: asynchronous
#include<stdio.h>
#include<stdlib.h>

// Function to print the C pattern
void printC()
{
    int size = 7;

    // Asynchronous pattern printing
    #pragma omp parallel for
    for (int i = 1; i <= size; i++)
    {
        // First line
        if (i == 1)
        {
            printf(" ");
            for (int j = 1; j <= size/2+1; j++)
                printf("*");
            printf("\n");
        }
        
        // Middle lines
        else if (i <= size/2+1)
        {
            printf("*");
            for (int j = 1; j <= size/2; j++)
                printf(" ");
            printf("*\n");
        }

        // Last line
        else if (i == size)
        {
            printf(" ");
            for (int j = 1; j <= size/2+1; j++)
                printf("*");
            printf("\n");
        }

        // Blank spaces
        else
        {
            printf(" ");
            for (int j = 1; j <= size/2; j++)
                printf(" ");
            printf("\n");
        }
    }
}

// Driver program
int main()
{
    printC();
    return 0;
}
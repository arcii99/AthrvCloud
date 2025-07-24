//FormAI DATASET v1.0 Category: Fractal Generation ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    // Define the variables
    int n, x, y, i, j;
    double scalex, scaley, k;
    
    // Request the user input
    printf("Enter the fractal level (1-7): ");
    scanf("%d", &n);

    // Set the scale factors
    scalex = 1.0 / pow(3, n);
    scaley = 1.0 / pow(3, n);

    // Iterate over the rows
    for (i = pow(3, n); i >= 0; i--)
    {
        // Iterate over the columns
        for (j = 0; j < pow(3, n); j++)
        {
            // Convert the row and column indices to coordinates
            x = j;
            y = i;
            
            // Apply the fractal algorithm
            for (k = 0; k <= n; k++)
            {
                if (x % 3 == 1 && y % 3 == 1)
                {
                    printf("*");
                    break;
                }
                else
                {
                    x /= 3;
                    y /= 3;
                }
            }

            // Print a space to separate the columns
            printf(" ");
        }

        // Print a newline to separate the rows
        printf("\n");
    }

    return 0;
}
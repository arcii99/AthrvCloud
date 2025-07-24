//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: ultraprecise
#include <stdio.h>

// Function to generate fibonacci sequence
void fibonacci_sequence(int n)
{
    int first = 0, second = 1, next, i;
    printf("%d %d ", first, second);

    for(i = 3; i <= n; i++)
    {
        next = first + second;
        printf("%d ", next);
        first = second;
        second = next;
    }
}

// Function to print Fibonacci Sequence in Spiral form
void fibonacci_spiral(int n)
{
    int a[n][n], i, k = 0, l = 0, m = n, j = 1;

    while(k < m && l < n)
    {
        // Fill top row from left to right
        for(i = l; i < n; i++)
        {
            a[k][i] = j++;
        }
        k++;

        // Fill right column from top to bottom
        for(i = k; i < m; i++)
        {
            a[i][n-1] = j++;
        }
        n--;

        // Fill bottom row from right to left
        if(k < m)
        {
            for(i = n-1; i >= l; i--)
            {
                a[m-1][i] = j++;
            }
            m--;
        }

        // Fill left column from bottom to top
        if(l < n)
        {
            for(i = m-1; i >= k; i--)
            {
                a[i][l] = j++;
            }
            l++;
        }
    }

    // Print the spiral fibonacci sequence
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

// Main function
int main()
{
    int n;

    // Get user input
    printf("Enter the number of terms in fibonacci sequence: ");
    scanf("%d", &n);

    // Display fibonacci sequence
    printf("\nFibonacci Sequence: ");
    fibonacci_sequence(n);

    // Display fibonacci sequence in spiral form
    printf("\n\nFibonacci Spiral Sequence: \n");
    fibonacci_spiral(n);

    return 0;
}
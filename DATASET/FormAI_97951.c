//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: rigorous
#include <stdio.h>

int main()
{
    int n, i, t1 = 0, t2 = 1, nextTerm;
    printf("Enter the number of terms: ");
    scanf("%d", &n);

    printf("Fibonacci Series: ");

    for (i = 1; i <= n; ++i)
    {
        printf("%d, ", t1);  // print the current term

        nextTerm = t1 + t2; // calculate the next term

        t1 = t2; // assign the next term as the current term
        t2 = nextTerm; // assign the calculated next term as the upcoming term
    }
    return 0;
}
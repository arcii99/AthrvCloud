//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: optimized
#include <stdio.h>

int main()
{
    int numTerms, i, term1 = 0, term2 = 1, nextTerm;
    printf("Enter the number of terms: ");
    scanf("%d", &numTerms);
    
    printf("\nFibonacci Series:\n");

    for(i=1; i<=numTerms; i++)
    {
        printf("%d, ", term1);
        nextTerm = term1 + term2;
        term1 = term2;
        term2 = nextTerm;
    }

    return 0;
}
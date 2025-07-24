//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numberOfTerms, i;
    int currentTerm = 0, nextTerm = 1, sum;

    printf("Enter the number of terms you want in the Fibonacci sequence: ");
    scanf("%d", &numberOfTerms);

    printf("\nHere is your Fibonacci sequence:\n");

    for (i = 0; i < numberOfTerms; ++i)
    {
        if (i == 0)
        {
            printf("In the beginning, there was ");
            printf("%d\n", currentTerm);
            continue;
        }
        else if (i == 1)
        {
            printf("Then came ");
            printf("%d\n", nextTerm);
            continue;
        }

        sum = currentTerm + nextTerm;
        currentTerm = nextTerm;
        nextTerm = sum;

        printf("And then there was ");
        printf("%d\n", nextTerm);
    }

    printf("\nThat concludes our journey through the Fibonacci sequence.\n");

    return 0;
}
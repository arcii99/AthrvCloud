//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, i;
    int *fibArray;

    printf("Enter the number of terms you want in the Fibonacci sequence: ");
    scanf("%d", &num);

    // Dynamic memory allocation to store the sequence
    fibArray = (int*) malloc(sizeof(int) * num);

    if (num <= 0) {
        printf("Invalid input! Please enter a positive integer.\n");
    }
    else {
        // Starting two numbers of the sequence
        fibArray[0] = 0;
        fibArray[1] = 1;

        printf("\nFibonacci sequence: ");

        // Loop to generate the sequence
        for (i = 2; i < num; i++) {
            fibArray[i] = fibArray[i-1] + fibArray[i-2];
        }

        // Loop to print the sequence
        for (i = 0; i < num; i++) {
            if (i == num-1) {
                printf("%d", fibArray[i]);
            }
            else {
                printf("%d, ", fibArray[i]);
            }
        }

        // Freeing the allocated memory
        free(fibArray);
    }

    return 0;
}
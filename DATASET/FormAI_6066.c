//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

int main()
{
    int n, i, j, k = 1, p = 0;
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    printf("\n*************************************\n");
    printf("Generating Fibonacci Sequence...");
    for (i = 0; i < n; i++) {
        for (j = 0; j < k; j++) {
            printf("*");
            usleep(100000);
        }
        k += p;
        p = k - p;
        printf("\n");
    }
    return 0;
}
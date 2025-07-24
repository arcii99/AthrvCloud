//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: future-proof
#include <stdio.h>

#define MAX_TERMS 100

void drawFibonacci(int[], int);

int main(void) {
    int n, i;
    int fibonacci[MAX_TERMS] = {0, 1};

    printf("Enter the number of terms to display (1-%d): ", MAX_TERMS - 2);
    scanf("%d", &n);

    if (n < 1 || n > MAX_TERMS - 2) {
        printf("Invalid input! Exiting program...\n");
        return 1;
    }

    for (i = 2; i < n + 2; i++) {
        fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
    }

    drawFibonacci(fibonacci, n);

    return 0;
}

void drawFibonacci(int sequence[], int n) {
    int i, j, k, isEven;

    for (i = 0; i < n; i += 2) {
        isEven = !(sequence[i] % 2);
        k = sequence[i + 1];
        
        if (isEven) {
            for (j = 0; j < k; j++) {
                printf("*");
            }
        } else {
            for (j = 0; j < k; j++) {
                printf("-");
            }
        }
        
        printf("\n");
    }
}
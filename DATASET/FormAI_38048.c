//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: enthusiastic
#include <stdio.h>

int main() {
    int n, first = 0, second = 1, next, i;
    printf("Enter the number of terms in Fibonacci series: ");
    scanf("%d", &n);
    
    printf("\nFibonacci Series:\n");
    for (i = 0; i < n; i++) {
        if (i <= 1) {
            next = i;
        } else {
            next = first + second;
            first = second;
            second = next;
        }
        printf("%d ", next);
        if ((i + 1) % 10 == 0) {
            printf("\n");
        }
    }
    return 0;
}
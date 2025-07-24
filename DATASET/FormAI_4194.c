//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void delay(int milliseconds) {
    usleep(milliseconds * 1000);
}

int main() {
    int n, n1 = 0, n2 = 1, nextTerm, i;
    printf("Enter the number of terms to display: ");
    scanf("%d", &n);
    for (i=1; i<=n; ++i) {
        printf("%d, ", n1);
        // Visualize the Fibonacci sequence
        for (int j = 0; j < n1; j++) {
            printf("*");
        }
        printf("\n");
        delay(100);
        nextTerm = n1 + n2; // compute the next Fibonacci number
        n1 = n2;
        n2 = nextTerm;
    }
    return 0;
}
//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void printFibonacci(int n) {
    int a = 0, b = 1, c, i;
    printf("%d %d ", a, b);
    for (i = 3; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
        printf("%d ", c);
    }
}

int main() {
    int n, i, j, k = 0;
    printf("Enter the number of terms:\n");
    scanf("%d", &n);
    printf("\n\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n - i; j++) {
            if (j % 2 == 0) {
                printf("〰️ ");
            } else {
                printf("🔲 ");
            }
        }
        printFibonacci(i + k);
        k++;
        printf("\n\n");
        usleep(500000);
        system("clear");
    }
    return 0;
}
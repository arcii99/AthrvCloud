//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: brave
#include <stdio.h>

int main() {
    int n, t1 = 0, t2 = 1, nextTerm;

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    printf("Fibonacci Series: ");

    for (int i = 1; i <= n; ++i) {
        if (i == 1) {
            printf("%d ", t1);
            continue;
        }
        if (i == 2) {
            printf("%d ", t2);
            continue;
        }
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;

        printf("%d ", nextTerm);

        for(int j = 0; j < nextTerm; ++j) {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}
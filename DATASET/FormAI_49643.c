//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: careful
#include <stdio.h>

void fibonacci(int n);

int main() {
    int n;

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    printf("Fibonacci Sequence: ");

    fibonacci(n);

    return 0;
}

void fibonacci(int n) {
    int i, t1 = 0, t2 = 1, nextTerm;

    for (i = 0; i < n; i++) {
        if(i <= 1) {
            nextTerm = i;
        } else {
            nextTerm = t1 + t2;
            t1 = t2;
            t2 = nextTerm;
        }

        printf("%d ", nextTerm);
    }
}
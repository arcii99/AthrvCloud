//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: Dennis Ritchie
#include<stdio.h>
int main() {
    int n, i, t1 = 0, t2 = 1, nextTerm;
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    printf("Fibonacci Series: ");
    for (i = 1; i <= n; ++i) {
        printf("%d, ", t1);
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
    }
    printf("\n\nVisualization:\n\n");
    for (i = 1; i <= n; ++i) {
        int j;
        for (j = 0; j < n-i; j++) printf(" ");
        for (j = 0; j < i; j++)
            printf("%d ", t1);
        printf("\n");
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
    }
    return 0;
}
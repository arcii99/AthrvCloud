//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: portable
#include <stdio.h>

void print_fibonacci(int n) {
    int fibo[n];
    fibo[0] = 0;
    fibo[1] = 1;
    printf("%d %d ", fibo[0], fibo[1]);
    for (int i = 2; i < n; i++) {
        fibo[i] = fibo[i-1] + fibo[i-2];
        printf("%d ", fibo[i]);
    }
}

int main() {
    int n;
    printf("Enter the number of terms you want in the Fibonacci sequence: ");
    scanf("%d", &n);
    printf("The Fibonacci Series: ");
    print_fibonacci(n);
    printf("\n");
    return 0;
}
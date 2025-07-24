//FormAI DATASET v1.0 Category: Recursive ; Style: complex
#include <stdio.h>

int fibonacci(int n) {
    if (n <= 1)
        return n;
    else
        return (fibonacci(n-1) + fibonacci(n-2));
}

int main() {
    int n, i = 0, c;
    printf("Enter the number of terms in Fibonacci series: ");
    scanf("%d", &n);
    printf("\nFibonacci series:\n");
    for (c = 1; c <= n; c++) {
        printf("%d ", fibonacci(i));
        i++;
    }
    printf("\n");
    return 0;
}
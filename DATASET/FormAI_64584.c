//FormAI DATASET v1.0 Category: Recursive ; Style: single-threaded
#include <stdio.h>

int fibonacci(int n) {
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return (fibonacci(n-1) + fibonacci(n-2));
}

int main() {
    int n, i;
    printf("Enter the number of terms to be printed: ");
    scanf("%d", &n);
    printf("Fibonacci Series:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", fibonacci(i));
    }
    return 0;
}
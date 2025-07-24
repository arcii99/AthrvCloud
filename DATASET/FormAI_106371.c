//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: rigorous
#include <stdio.h>

int main() {
    int n, factorial = 1;
    printf("Enter a positive integer: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Error: Factorial of negative numbers is undefined.\n");
    } else {
        for (int i = 1; i <= n; ++i) {
            factorial *= i;
        }
        printf("Factorial of %d is %d.\n", n, factorial);
    }
    return 0;
}
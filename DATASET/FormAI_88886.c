//FormAI DATASET v1.0 Category: Math exercise ; Style: standalone
#include <stdio.h>

int main() {
    int num, i;
    unsigned long long factorial = 1;

    printf("Enter a number: ");
    scanf("%d", &num);

    // Error handling for negative numbers
    if (num < 0) {
        printf("Error: Factorial of negative number doesn't exist.");
    }
    else {
        // Find the factorial
        for (i = 1; i <= num; ++i) {
            factorial *= i;
        }

        // Print the factorial
        printf("Factorial of %d = %llu", num, factorial);
    }

    return 0;
}
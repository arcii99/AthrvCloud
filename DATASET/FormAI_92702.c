//FormAI DATASET v1.0 Category: Syntax parsing ; Style: mathematical
#include <stdio.h>

// Custom function to calculate factorial
int factorial(int n) {
    int fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

int main() {
    // Declare and initialize variables
    int num, k;
    printf("Enter the number of terms in the series: ");
    scanf("%d", &num);
    printf("Enter the value of k: ");
    scanf("%d", &k);

    if (num <= 0 || k <= 0) {
        printf("Error: Both 'num' and 'k' must be positive integers!\n");
        return 1;
    }

    // Calculate the series
    int sum = 0;
    for (int i = 1; i <= num; i++) {
        int term = i;
        for (int j = 1; j < i; j++) {
            term *= (k - j);
        }
        term /= factorial(i);
        sum += term;
    }

    // Print the series and sum
    printf("The series is: ");
    for (int i = 1; i <= num; i++) {
        printf("%d", i);
        if (i != num) {
            printf(",");
        }
    }
    printf("\n");
    printf("The sum of the series is: %d\n", sum);

    return 0;
}
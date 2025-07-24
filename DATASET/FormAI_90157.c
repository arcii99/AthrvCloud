//FormAI DATASET v1.0 Category: Scientific ; Style: mathematical
#include <stdio.h>

// Define a constant variable PI
#define PI 3.14159265358979323846

// Declare the function to calculate the factorial of a number
int factorial(int n);

int main() {
    int n;

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    double sum = 0;
    int sign = 1, i;

    // Calculate the sum of the series
    for (i = 1; i <= n; i++) {
        sum += sign * (double)1/factorial(2*i-1);
        sign *= -1;
    }

    // Multiply by 4 and PI to get the value of PI
    double pi = 4 * sum;

    printf("The value of PI is: %lf\n", pi);

    return 0;
}

// Function to calculate the factorial of a number
int factorial(int n) {
    int res = 1;
    int i;
    for (i = n; i >= 1; i--) {
        res *= i;
    }
    return res;
}
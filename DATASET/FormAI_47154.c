//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: scientific
// Mortgage Calculator Program
#include <stdio.h>
#include <math.h>

int main() {
    double p = 0.0, r = 0.0, m = 0.0, n = 0.0, i = 0.0, j = 0.0;

    // Get user input for mortgage details
    printf("Enter the Principal Amount: ");
    scanf("%lf", &p);

    printf("Enter the Interest Rate (in Percentage): ");
    scanf("%lf", &r);

    printf("Enter the Term of the Mortgage (in Years): ");
    scanf("%lf", &n);

    // Calculate monthly interest rate
    r = r / (12 * 100);

    // Calculate number of payments
    m = n * 12;

    // Calculate monthly payment amount
    i = pow(1 + r, m);
    j = (p * r * i) / (i - 1);

    // Print out payment details
    printf("\nMonthly Payments: %0.2lf\n", j);

    // Calculate total payment amount
    printf("Total Payment Amount: %0.2lf\n", j * m);
    return 0;
}
//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    float principal, rate, EMI, total;
    int years, months;

    printf("Enter the loan amount: ");
    scanf("%f", &principal);
    printf("Enter the interest rate: ");
    scanf("%f", &rate);
    printf("Enter the number of years: ");
    scanf("%d", &years);

    // Calculation
    rate /= 1200; // Monthly interest rate
    months = years * 12; // Total number of months

    // Monthly EMI Calculation
    EMI = (principal * rate * pow(1 + rate, months)) / (pow(1 + rate, months) - 1);
    total = EMI * months;

    // Result
    printf("\n");
    printf("Loan Amount:     %.2f\n", principal);
    printf("Interest Rate:   %.2f %%\n", rate * 1200);
    printf("Number of Years: %d\n", years);
    printf("EMI per month:   %.2f\n", EMI);
    printf("Total Payment:   %.2f\n", total);

    return 0;
}
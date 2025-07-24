//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: configurable
#include <stdio.h>
#include <math.h>

float calculateMonthlyPayment(float principal, float rate, int years) {
    // Formula to calculate the monthly payment
    float monthlyRate = rate / 1200; // 12 months in a year, 100 for percentage
    int months = years * 12; // Total number of months
    float numerator = principal * monthlyRate; // Numerator of the formula
    float denominator = 1 - pow(1 + monthlyRate, -months); // Denominator of the formula
    float monthlyPayment = numerator / denominator; // Final monthly payment
    return monthlyPayment;
}

int main() {

    // Variable declarations
    float principal, annualRate;
    int years;

    // Getting input from the user
    printf("Enter the principal amount: ");
    scanf("%f", &principal);
    printf("Enter the annual interest rate (in percentage): ");
    scanf("%f", &annualRate);
    printf("Enter the number of years of the loan: ");
    scanf("%d", &years);

    // Calculating the monthly payment and total payment
    float monthlyPayment = calculateMonthlyPayment(principal, annualRate, years);
    float totalPayment = monthlyPayment * years * 12;

    // Printing the results
    printf("\nLoan information:\n");
    printf("Principal amount: $%.2f\n", principal);
    printf("Annual interest rate: %.2f%%\n", annualRate);
    printf("Number of years of the loan: %d\n", years);
    printf("\nMonthly payment: $%.2f\n", monthlyPayment);
    printf("Total payment: $%.2f\n", totalPayment);

    return 0;
}
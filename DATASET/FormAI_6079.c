//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: scientific
#include <stdio.h>
#include <math.h>

int main() {
    double principal, ratePerAnnum, numberOfYears, totalPayment, totalInterest;
    int monthlyPayment;

    // Get input from user
    printf("Enter Principal Amount: ");
    scanf("%lf", &principal);

    printf("Enter Annual Interest Rate (in percentage): ");
    scanf("%lf", &ratePerAnnum);

    printf("Enter Number of Years: ");
    scanf("%lf", &numberOfYears);

    // Calculate monthly interest rate and total number of payments
    double monthlyRate = ratePerAnnum / 1200;  // 12 months in a year, 100% to 1%
    int numberOfPayments = numberOfYears * 12;

    // Calculate monthly payment
    monthlyPayment = (principal * monthlyRate) / (1 - pow(1 + monthlyRate, -numberOfPayments));

    // Calculate total payment and total interest
    totalPayment = monthlyPayment * numberOfPayments;
    totalInterest = totalPayment - principal;

    // Display results
    printf("\n");
    printf("Loan Amount: %.2lf\n", principal);
    printf("Interest Rate: %.2lf %%\n", ratePerAnnum);
    printf("Number of Years: %.0lf\n", numberOfYears);
    printf("Monthly Payment: $%d\n", monthlyPayment);
    printf("Total Payment: $%.2lf\n", totalPayment);
    printf("Total Interest: $%.2lf\n", totalInterest);

    return 0;
}
//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: mathematical
#include <stdio.h>
#include <math.h>

int main() {

    // Get variables from user input
    double principal, rate, payments;
    printf("Enter the principal value: ");
    scanf("%lf", &principal);
    printf("Enter the interest rate: ");
    scanf("%lf", &rate);
    printf("Enter the number of payments: ");
    scanf("%lf", &payments);

    // Calculate monthly interest rate
    double monthlyRate = rate / 1200;

    // Calculate monthly payment
    double monthlyPayment = principal * (monthlyRate * pow(1 + monthlyRate, payments)) / (pow(1 + monthlyRate, payments) - 1);

    // Calculate total payments
    double totalPayments = monthlyPayment * payments;

    // Calculate total interest paid
    double totalInterest = totalPayments - principal;

    // Display results to user
    printf("Loan Details:\n");
    printf("Principal Amount: $%.2lf\n", principal);
    printf("Interest Rate: %.2lf%%\n", rate);
    printf("Number of Payments: %.0lf\n", payments);
    printf("\n");
    printf("Monthly Payment: $%.2lf\n", monthlyPayment);
    printf("Total Payments: $%.2lf\n", totalPayments);
    printf("Total Interest Paid: $%.2lf\n", totalInterest);

    return 0;
}
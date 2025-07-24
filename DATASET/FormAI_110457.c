//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: detailed
#include <stdio.h>
#include <math.h>

int main() {
    // Loan details
    double loanAmount = 0.0;
    double interestRate = 0.0;
    int loanTermYears = 0;
    int loanTermMonths = 0;

    // Monthly payment variables
    double monthlyInterestRate = 0.0;
    double monthlyPayment = 0.0;

    // Output variables
    double totalPaid = 0.0;
    double totalInterest = 0.0;

    // Get input from user
    printf("Enter Loan Amount: $");
    scanf("%lf", &loanAmount);
    printf("Enter Interest Rate: ");
    scanf("%lf", &interestRate);
    printf("Enter Loan Term in Years: ");
    scanf("%d", &loanTermYears);
    printf("Enter Loan Term in Months: ");
    scanf("%d", &loanTermMonths);

    // Calculate monthly payment variables
    monthlyInterestRate = interestRate / 1200.0;
    monthlyPayment = (loanAmount * monthlyInterestRate) / (1 - pow(1 + monthlyInterestRate, -(loanTermYears * 12 + loanTermMonths)));

    // Calculate total paid and total interest
    totalPaid = monthlyPayment * (loanTermYears * 12 + loanTermMonths);
    totalInterest = totalPaid - loanAmount;

    // Output results
    printf("\n");
    printf("Loan Amount: $%.2f\n", loanAmount);
    printf("Interest Rate: %.2f%%\n", interestRate);
    printf("Loan Term: %d Years %d Months\n", loanTermYears, loanTermMonths);
    printf("\n");
    printf("Monthly Payment: $%.2f\n", monthlyPayment);
    printf("Total Paid: $%.2f\n", totalPaid);
    printf("Total Interest: $%.2f\n", totalInterest);

    return 0;
}
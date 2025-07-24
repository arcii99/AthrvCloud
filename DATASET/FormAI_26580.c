//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

// Function to calculate the monthly payment amount
double calculateMonthlyPayment(double loanAmount, double interestRate, int numOfYears) {
    double monthlyInterestRate = interestRate / 1200; // Divide by 1200 to convert from annual to monthly interest rate
    int numOfMonths = numOfYears * 12; // Convert number of years to number of months
    double monthlyPayment = (loanAmount * monthlyInterestRate) / (1 - pow(1 + monthlyInterestRate, -numOfMonths));
    return monthlyPayment;
}

int main() {
    printf("Welcome to your Personal Finance Planner!\n");

    double loanAmount, interestRate;
    int numOfYears;

    printf("\nEnter the loan amount: ");
    scanf("%lf", &loanAmount);
    printf("Enter the interest rate (in percentage): ");
    scanf("%lf", &interestRate);
    printf("Enter the number of years for the loan: ");
    scanf("%d", &numOfYears);

    double monthlyPayment = calculateMonthlyPayment(loanAmount, interestRate, numOfYears);

    printf("\nLoan amount: $%.2f\n", loanAmount);
    printf("Interest rate: %.2f%%\n", interestRate);
    printf("Number of years: %d\n", numOfYears);
    printf("Monthly payment: $%.2f\n", monthlyPayment);

    return 0;
}
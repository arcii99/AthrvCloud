//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: interoperable
#include <stdio.h>

// Function to calculate monthly payment for a loan
float calculateMonthlyPayment(float principal, float interestRate, int loanTermYears) {
    int loanTermMonths = loanTermYears * 12;
    float monthlyRate = (interestRate / 100) / 12;
    float numerator = principal * monthlyRate;
    float denominator = 1 - pow(1 + monthlyRate, -loanTermMonths);
    float monthlyPayment = numerator / denominator;
    return monthlyPayment;
}

int main() {

    // Define values
    float principal, interestRate, monthlyPayment;
    int loanTermYears;

    // Get user input
    printf("Enter the principal amount of the loan: ");
    scanf("%f", &principal);
    printf("Enter the interest rate of the loan: ");
    scanf("%f", &interestRate);
    printf("Enter the loan term in years: ");
    scanf("%d", &loanTermYears);

    // Calculate monthly payment
    monthlyPayment = calculateMonthlyPayment(principal, interestRate, loanTermYears);
    printf("Monthly Payment: $%.2f\n", monthlyPayment);

    // Get user input for additional monthly payments
    float additionalPayment;
    printf("Enter any additional monthly payments: ");
    scanf("%f", &additionalPayment);

    // Calculate total interest paid and pay off date with additional payments
    float totalInterest = 0;
    int monthCount = 0;
    while (principal > 0) {
        monthCount++;
        float interest = (principal * interestRate / 100) / 12;
        totalInterest += interest;
        principal += interest;
        principal -= monthlyPayment;
        principal -= additionalPayment;
    }
    printf("Total Interest Paid: $%.2f\n", totalInterest);
    printf("Pay Off Date: %d/%d", monthCount % 12 + 1, monthCount / 12);

    return 0;
}
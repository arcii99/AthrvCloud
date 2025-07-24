//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: secure
#include <stdio.h>
#include <math.h>

// Function to calculate monthly mortgage payment
double calculateMortgagePayment(double principal, double interestRate, int term) {
    double monthlyInterestRate = (interestRate / 12) / 100; // Convert annual interest rate to monthly interest rate
    int numberOfPayments = term * 12; // Calculate total number of payments in the loan term

    // Calculate monthly mortgage payment using formula: M = P [ i(1 + i)^n ] / [ (1 + i)^n – 1 ]
    double monthlyPayment = (principal * monthlyInterestRate * pow(1 + monthlyInterestRate, numberOfPayments)) / (pow(1 + monthlyInterestRate, numberOfPayments) - 1);

    return monthlyPayment;
}

int main() {
    // Get input from user
    double principal, interestRate;
    int term;

    printf("Enter principal amount: ");
    scanf("%lf", &principal);

    printf("Enter interest rate: ");
    scanf("%lf", &interestRate);

    printf("Enter loan term (in years): ");
    scanf("%d", &term);

    // Call calculateMortgagePayment function to calculate monthly mortgage payment
    double monthlyPayment = calculateMortgagePayment(principal, interestRate, term);

    // Print the calculated monthly mortgage payment
    printf("Monthly Mortgage Payment: $%.2f\n", monthlyPayment);

    return 0;
}
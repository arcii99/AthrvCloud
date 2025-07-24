//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Function to calculate monthly loan payments */
double calculatePayment(double principal, double interestRate, int numOfPayments) {
    double ratePerPeriod = interestRate / 12; // Monthly interest rate calculation
    double payment = principal * (ratePerPeriod / (1 - pow(1 + ratePerPeriod, -numOfPayments))); // Loan payment calculation formula
    return payment; // Returning monthly payment
}

int main() {
    double principal, interestRate, payment;
    int numOfPayments;

    // User inputs
    printf("Enter the principal: ");
    scanf("%lf", &principal);
    printf("Enter the annual interest rate (in percentage): ");
    scanf("%lf", &interestRate);
    printf("Enter the number of payments: ");
    scanf("%d", &numOfPayments);

    interestRate = interestRate / 100; // Converting interest rate percentage to decimal
    payment = calculatePayment(principal, interestRate, numOfPayments); // Calling the function to calculate monthly payment

    // Displaying the results
    printf("\nLoan details:\n");
    printf("Principal amount : $%.2lf\n", principal);
    printf("Interest rate    : %.2lf%%\n", interestRate * 100);
    printf("Number of payments: %d\n", numOfPayments);
    printf("Monthly payment  : $%.2lf\n", payment);

    return 0;
}
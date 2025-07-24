//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: careful
#include <stdio.h>

// Function to calculate monthly interest rate
float calcInterestRate(float apr) {
    float monthlyRate = (apr / 100) / 12;
    return monthlyRate;
}

int main() {
    float loanAmount, apr, paymentAmt;
    int numPayments;

    printf("Welcome to the Personal Finance Planner!\n\n");

    // Get loan amount from user
    printf("Please enter the amount of your loan: ");
    scanf("%f", &loanAmount);

    // Get APR from user
    printf("Please enter the annual percentage rate (APR): ");
    scanf("%f", &apr);

    // Get number of payments from user
    printf("Please enter the number of payments: ");
    scanf("%d", &numPayments);

    // Calculate monthly interest rate
    float monthlyRate = calcInterestRate(apr);

    // Calculate payment amount
    paymentAmt = (monthlyRate * loanAmount) / (1 - pow(1 + monthlyRate, -numPayments));

    // Display payment information to user
    printf("\n\nYour monthly payment will be: $%.2f\n", paymentAmt);
    printf("Total amount paid over the life of the loan: $%.2f\n", paymentAmt * numPayments);
    printf("Total interest paid over the life of the loan: $%.2f\n", (paymentAmt * numPayments) - loanAmount);

    return 0;
}
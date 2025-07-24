//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: curious
#include <stdio.h>

// Function to calculate monthly payments
float calculateMonthlyPayments(float loanAmount, float interestRate, int loanTerm) {
    float monthlyInterestRate = interestRate / 1200; // Monthly interest rate = Annual interest rate / 12
    int totalMonths = loanTerm * 12; // Total Months = Loan term in years * 12
    float monthlyPayment = (loanAmount * monthlyInterestRate) / (1 - pow(1 + monthlyInterestRate, -totalMonths)); // Calculating monthly payments using formula
    return monthlyPayment;
}

int main() {
    float loanAmount, interestRate, monthlyPayment, totalInterestPaid;
    int loanTerm, totalPayments;

    // Getting input from user
    printf("Enter loan amount: ");
    scanf("%f", &loanAmount);
    printf("Enter interest rate: ");
    scanf("%f", &interestRate);
    printf("Enter loan term in years: ");
    scanf("%d", &loanTerm);

    // Calculating monthly payments and total payments
    monthlyPayment = calculateMonthlyPayments(loanAmount, interestRate, loanTerm);
    totalPayments = loanTerm * 12;
    totalInterestPaid = (monthlyPayment * totalPayments) - loanAmount;

    // Displaying results
    printf("\nMonthly Payment: $%.2f\n", monthlyPayment);
    printf("Total Payments: $%.2f\n", monthlyPayment * totalPayments);
    printf("Total Interest Paid: $%.2f\n", totalInterestPaid);

    return 0;
}
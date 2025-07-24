//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: realistic
#include <stdio.h>

// Function to calculate monthly installment
float calculateInstallment(float principal, float rate, int time) {
    float installment = (((rate/100)/12) * principal) / (1 - pow(1 + ((rate/100)/12), -time));
    return installment;
}

// Function to calculate total interest paid
float calculateInterest(float principal, float installment, int time) {
    float total_interest = (installment * time) - principal;
    return total_interest;
}

// Function to calculate total amount paid
float calculateTotalAmount(float principal, float total_interest) {
    float total_amount = principal + total_interest;
    return total_amount;
}

int main() {
    float principal, rate, installment, total_interest, total_amount;
    int time;

    // Input principal, rate, and time period
    printf("Enter the principal amount: ");
    scanf("%f", &principal);
    printf("Enter the rate of interest: ");
    scanf("%f", &rate);
    printf("Enter the time period (in months): ");
    scanf("%d", &time);

    // Calculate installment, total interest, and total amount
    installment = calculateInstallment(principal, rate, time);
    total_interest = calculateInterest(principal, installment, time);
    total_amount = calculateTotalAmount(principal, total_interest);

    // Output the results
    printf("Monthly installment: $%.2f\n", installment);
    printf("Total interest paid: $%.2f\n", total_interest);
    printf("Total amount paid: $%.2f\n", total_amount);

    return 0;
}
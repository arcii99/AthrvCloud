//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: brave
#include <stdio.h>
#include <math.h>

int main() {
    float principal, rate, time, emi, total_amount;
    int num_payments;
    
    // Get user input
    printf("Enter principal amount: ");
    scanf("%f", &principal);
    printf("Enter annual interest rate: ");
    scanf("%f", &rate);
    printf("Enter loan term in years: ");
    scanf("%f", &time);
    
    // Convert rate to monthly and calculate number of payments
    rate = rate / 1200; // monthly rate
    num_payments = time * 12; // number of payments
    
    // Calculate EMI (Equated Monthly Installment)
    emi = (principal * rate * pow((1 + rate), num_payments)) / (pow((1 + rate), num_payments) - 1);
    
    // Calculate Total amount payable
    total_amount = emi * num_payments;
    
    // Print Results
    printf("\n\nLoan Summary:\n\n");
    printf("Principal Amount: $%0.2f\n", principal);
    printf("Interest Rate: %0.2f%%\n", rate*1200);
    printf("Loan Tenure: %0.0f years\n", time);
    printf("Number of Payments: %d\n", num_payments);
    printf("EMI (Equated Monthly Installment): $%0.2f\n", emi);
    printf("Total Amount Payable: $%0.2f\n", total_amount);
    
    return 0;
}
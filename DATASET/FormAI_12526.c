//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: expert-level
#include <stdio.h>

int main() {
    
    float loanAmount, interestRate, monthlyPayment, totalPayment, monthlyRate;
    int paymentPeriods;
    
    // Get user input
    printf("Enter the loan amount (in dollars): ");
    scanf("%f", &loanAmount);
    printf("Enter the interest rate (in percentage): ");
    scanf("%f", &interestRate);
    printf("Enter the payment period (in months): ");
    scanf("%d", &paymentPeriods);
    
    // Calculate monthly interest rate
    monthlyRate = (interestRate / 100) / 12;
    
    // Calculate monthly payment
    monthlyPayment = (monthlyRate * loanAmount) / (1 - pow(1 + monthlyRate, -paymentPeriods));
    
    // Calculate total payment
    totalPayment = monthlyPayment * paymentPeriods;
    
    // Display results
    printf("Monthly Payment: %.2f\n", monthlyPayment);
    printf("Total Payment: %.2f\n", totalPayment);
    
    return 0;
}
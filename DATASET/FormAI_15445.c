//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: configurable
#include <stdio.h>

float calculateMortgage(float loanAmount, float interestRate, int term) {
    float monthlyInterestRate = interestRate / 12;
    int numberOfPayments = term * 12;
    float mortgagePayment = (loanAmount * monthlyInterestRate) / (1 - (pow(1 + monthlyInterestRate, -numberOfPayments)));
    return mortgagePayment;
}

int main() {
    float loanAmount, interestRate;
    int term;
    
    // Configurable Inputs
    printf("Enter the loan amount: ");
    scanf("%f", &loanAmount);
    
    printf("Enter the interest rate: ");
    scanf("%f", &interestRate);
    
    printf("Enter the loan term (in years): ");
    scanf("%d", &term);
    
    // Calculate Mortgage Payment
    float mortgagePayment = calculateMortgage(loanAmount, interestRate, term);
    
    // Output Mortgage Payment
    printf("Your monthly mortgage payment is: %.2f\n", mortgagePayment);
    
    return 0;
}
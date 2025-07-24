//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: careful
#include <stdio.h>

int main() {
    float loanAmount, interestRate;
    int numOfYears;
    printf("Enter loan amount: $");
    scanf("%f", &loanAmount);
    printf("Enter interest rate: ");
    scanf("%f", &interestRate);
    printf("Enter number of years: ");
    scanf("%d", &numOfYears);

    float monthlyInterestRate = interestRate / 1200;
    int numOfPayments = numOfYears * 12;
    float monthlyPayment = (loanAmount * monthlyInterestRate) / (1 - ( pow(1 + monthlyInterestRate, -numOfPayments)));
    
    printf("\nLoan Amount: $%.2f\n", loanAmount);
    printf("Interest Rate: %.2f%%\n", interestRate);
    printf("Duration (Years): %d\n", numOfYears);
    printf("Monthly Payment: $%.2f\n", monthlyPayment);

    return 0;
}
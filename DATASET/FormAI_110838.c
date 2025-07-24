//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: authentic
#include <stdio.h>
#include <math.h>

int main() {
    // Declare variables
    float loanAmount, annualInterestRate, monthlyInterestRate, monthlyPayment;
    int numOfPayments, i;
 
    // Get Loan Amount
    printf("Enter loan amount: ");
    scanf("%f", &loanAmount);
 
    // Get Annual Interest Rate
    printf("Enter annual interest rate: ");
    scanf("%f", &annualInterestRate);
 
    // Get Number of Payments
    printf("Enter number of payments: ");
    scanf("%d", &numOfPayments);
 
    // Calculate Monthly Interest Rate
    monthlyInterestRate = (annualInterestRate / (float) (12 * 100));
 
    // Calculate Monthly Payment
    float numerator = monthlyInterestRate * pow(1 + monthlyInterestRate, numOfPayments);
    float denominator = pow(1 + monthlyInterestRate, numOfPayments) - 1;
    
    monthlyPayment = loanAmount * (numerator / denominator);
 
    // Display the result
    printf("\n");
    printf("Loan Amount: %.2f\n", loanAmount);
    printf("Annual Interest Rate: %.2f\n", annualInterestRate);
    printf("Number of Payments: %d\n", numOfPayments);
    printf("Monthly Payment: %.2f\n\n", monthlyPayment);
    
    // Generate Monthly Payment Schedule
    printf("\n");
    printf("Monthly Payment Schedule:\n");
    printf("---------------------------------------\n");
    printf(" Month |    Payment   |     Balance    \n");
    printf("---------------------------------------\n");
    
    float balance = loanAmount;
    
    for (int i = 1; i <= numOfPayments; i++) {
        printf("   %d   |   $%.2f  |  $%.2f\n", i, monthlyPayment, balance);
        float interest = balance * monthlyInterestRate;
        float principal = monthlyPayment - interest;
        balance = balance - principal;
    }
    
    printf("---------------------------------------\n");
    
    return 0;
}
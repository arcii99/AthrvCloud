//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: dynamic
#include <stdio.h>

int main() {
    float loanAmount, interestRate, monthlyPayment, principal, interest, balance, payments;
    
    // get loan amount
    printf("Enter loan amount: ");
    scanf("%f", &loanAmount);
    
    // get interest rate
    printf("Enter interest rate (in percentage): ");
    scanf("%f", &interestRate);
    
    // convert interest rate to monthly percentage rate
    interestRate /= 1200;
    
    // get number of payments
    printf("Enter number of payments: ");
    scanf("%f", &payments);
    
    // calculate monthly payment
    monthlyPayment = loanAmount * (interestRate * pow(1 + interestRate, payments)) / (pow(1 + interestRate, payments) - 1);
    
    // print monthly payment
    printf("\nMonthly Payment: $%.2f\n", monthlyPayment);
    
    // calculate and print amortization table
    printf("\nAmortization Table\n");
    printf("-------------------\n");
    printf("Month\t\tBalance\t\tPayment\t\tPrincipal\tInterest\n");
    
    balance = loanAmount;
    
    for (int month=1; month<=payments; month++) {
        
        interest = balance * interestRate;
        principal = monthlyPayment - interest;
        balance -= principal;
        
        printf("%d\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\n", month, balance, monthlyPayment, principal, interest);
    } 
    
    return 0;
}
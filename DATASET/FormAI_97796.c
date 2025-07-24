//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: mathematical
#include <stdio.h>
#include <math.h>

int main() {
    float loanAmount, interestRate, monthlyPayment, balance, principal, interest;
    int numYears, numMonths;
    
    // input loan parameters
    printf("Enter loan amount: ");
    scanf("%f", &loanAmount);
    
    printf("Enter interest rate: ");
    scanf("%f", &interestRate);
    
    printf("Enter number of years: ");
    scanf("%d", &numYears);
    
    // convert years to months
    numMonths = numYears * 12;
    
    // convert interest rate to monthly rate
    interestRate = interestRate / 1200;
    
    // calculate monthly payment
    monthlyPayment = loanAmount * interestRate / (1 - pow(1 + interestRate, -numMonths));
    
    // display monthly payment
    printf("Monthly payment: $%.2f\n", monthlyPayment);
    
    // print amortization table
    printf("\nAmortization Schedule:\n");
    printf("------------------------\n");
    printf(" Payment  Interest  Principal   Balance\n");
    printf("--------  --------  ---------  ---------\n");
    
    balance = loanAmount;
    
    for (int i = 1; i <= numMonths; i++) {
        // calculate interest and principal
        interest = balance * interestRate;
        principal = monthlyPayment - interest;
        
        // update balance
        balance -= principal;
        
        // display payment information
        printf(" %3d      $%7.2f  $%8.2f  $%8.2f\n", i, interest, principal, balance);
    }
    
    return 0;
}
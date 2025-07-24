//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: lively
#include<stdio.h>

int main(){
    float loanAmount, monthlyPayment, interestRate, balance, interest, principal;
    int numPayments, i;

    // Taking Loan Amount as input from user
    printf("Enter the loan amount: ");
    scanf("%f", &loanAmount);

    // Taking Interest Rate as input from user
    printf("Enter the interest rate: ");
    scanf("%f", &interestRate);

    // Taking Number of Payments as input from user
    printf("Enter the number of payments: ");
    scanf("%d", &numPayments);

    // Calculating Monthly Payment
    monthlyPayment = (interestRate * loanAmount) / (1 - pow(1 + interestRate, -numPayments));

    // Printing Monthly Payment
    printf("\nMonthly Payment: $%.2f\n", monthlyPayment);

    // Calculating Total Payment
    float totalPayment = monthlyPayment * numPayments;
    printf("Total Payment: $%.2f\n", totalPayment);

    // Initializing Balance equal to Loan Amount
    balance = loanAmount;

    // Printing Table
    printf("\nPayment\t  Interest\t  Principal\t  Balance\n");
    for(i=1; i<=numPayments; i++){
        // Calculating Interest
        interest = interestRate * balance;

        // Calculating Principal
        principal = monthlyPayment - interest;

        // Calculating Balance
        balance = balance - principal;

        // Printing Table Row
        printf("%d\t  $%.2f\t  $%.2f\t  $%.2f\n", i, interest, principal, balance);
    }

    return 0;
}
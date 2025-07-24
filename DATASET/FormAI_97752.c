//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: complete
#include<stdio.h>

int main(){
    float loanAmount, interestRate, monthlyPayment, balance, principal, interest;
    int numPayments, month=1;

    printf("Enter loan amount: ");
    scanf("%f", &loanAmount);

    printf("Enter interest rate in percentage: ");
    scanf("%f", &interestRate);

    printf("Enter number of payments: ");
    scanf("%d", &numPayments);

    //Calculating monthly interest rate and payment
    interestRate /= 1200.0;
    monthlyPayment = (loanAmount * interestRate) / (1.0 - pow(1.0 + interestRate, -numPayments));

    printf("\nMonthly payment is $%.2f\n\n", monthlyPayment);

    //Printing table
    printf("Month\tBalance\t\tPrincipal\tInterest\n");
    balance = loanAmount;

    while(month <= numPayments){
        interest = interestRate * balance;
        principal = monthlyPayment - interest;
        balance -= principal;

        printf("%d\t$%.2f\t$%.2f\t\t$%.2f\n", month, balance, principal, interest);
        month++;
    }
    return 0;
}
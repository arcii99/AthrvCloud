//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: light-weight
#include <stdio.h>

int main(){
    float loanAmount, interestRate, monthlyPayment, balance, monthlyInterest;
    int term, i;

    printf("Enter the loan amount ($): ");
    scanf("%f", &loanAmount);

    printf("Enter the annual interest rate (%%): ");
    scanf("%f", &interestRate);

    printf("Enter the term of the loan (years): ");
    scanf("%d", &term);

    monthlyInterest = interestRate / 1200;
    monthlyPayment = (loanAmount * monthlyInterest) / (1 - (1 / pow(1 + monthlyInterest, term * 12)));
    balance = loanAmount;

    printf("Monthly Payment: $%.2f\n", monthlyPayment);
    printf("Payment Schedule:\n");
    printf("%5s %20s %20s %20s\n", "Month", "Payment", "Interest", "Balance");

    for(i = 1; i <= term * 12; i++){
        float interest, principal;
        interest = monthlyInterest * balance;
        principal = monthlyPayment - interest;
        balance = balance - principal;

        printf("%5d %20.2f %20.2f %20.2f\n", i, monthlyPayment, interest, balance);

        if(balance <= 0){
            printf("Loan paid off in %d months.\n", i);
            break;
        }
    }

    return 0;
}
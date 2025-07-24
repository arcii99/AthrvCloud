//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    printf("Welcome to the Mortgage Calculator 3000!\n");
    printf("Please enter your loan amount: ");
    double loanAmount;
    scanf("%lf",&loanAmount);
    printf("Thank you! Now enter your interest rate (as a decimal): ");
    double interestRate;
    scanf("%lf",&interestRate);
    printf("Wonderful! Now enter your loan term in years: ");
    int loanTerm;
    scanf("%d",&loanTerm);
    double monthlyInterestRate = interestRate/12.0;
    int numberOfPayments = loanTerm*12;
    double monthlyPayment = loanAmount*((monthlyInterestRate*pow(1+monthlyInterestRate,numberOfPayments))/(pow(1+monthlyInterestRate,numberOfPayments)-1));
    printf("Calculating...\n");
    printf("Based on the information you provided, your monthly payment will be: $%.2lf\n",monthlyPayment);
    printf("Thank you for using the Mortgage Calculator 3000. Have a great day!\n");
    return 0;
}
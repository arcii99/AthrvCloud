//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: innovative
#include<stdio.h>

int main(){
    float loanAmount, interestRate, monthlyPayment, totalInterest, totalPayment;
    int years;

    printf("Enter the loan amount: ");
    scanf("%f", &loanAmount);

    printf("Enter the interest rate: ");
    scanf("%f", &interestRate);

    printf("Enter the loan term (in years): ");
    scanf("%d", &years);

    //Converting interest rate from annual to monthly
    interestRate = interestRate/100/12;

    //Calculating monthly payment
    monthlyPayment = (interestRate * loanAmount) / (1 - pow((1 + interestRate), -years*12));

    //Calculating total payment
    totalPayment = monthlyPayment * years * 12;

    //Calculating total interest
    totalInterest = totalPayment - loanAmount;

    printf("\nMonthly Payment: $%.2f", monthlyPayment);
    printf("\nTotal Payment: $%.2f", totalPayment);
    printf("\nTotal Interest: $%.2f", totalInterest);

    return 0;
}
//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: minimalist
#include<stdio.h>

int main()
{
    float loan, interest, monthlyInterest, numberOfYears, totalAmount, monthlyPayment;

    //Taking user input for Loan amount, interest rate, loan term
    printf("Enter your loan amount: $");
    scanf("%f", &loan);

    printf("Enter the interest rate per annum: ");
    scanf("%f", &interest);

    printf("Enter the total number of years of loan term: ");
    scanf("%f", &numberOfYears);

    //Converting years to months and calculating monthly interest rate
    monthlyInterest = interest / 1200;
    numberOfYears = numberOfYears * 12;

    //Calculating Monthly Payment and Total Payment
    monthlyPayment = (loan * monthlyInterest) / (1 - (pow(1 / (1 + monthlyInterest), numberOfYears)));
    totalAmount = monthlyPayment * numberOfYears;

    //Printing final results
    printf("\n=========================================");
    printf("\nLoan amount: $ %.2f", loan);
    printf("\nInterest rate: %.2f percent", interest);
    printf("\nLoan term: %.2f years", numberOfYears/12);
    printf("\nMonthly payment: $ %.2f", monthlyPayment);
    printf("\nTotal payment: $ %.2f", totalAmount);
    printf("\n=========================================");

    return 0;
}
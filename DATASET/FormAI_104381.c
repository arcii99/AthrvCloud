//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: high level of detail
#include<stdio.h>

int main()
{
    float loanAmount, interestRate, term, monthlyPayment;
    printf("Enter Loan Amount: ");
    scanf("%f", &loanAmount);
    printf("Enter Interest Rate: ");
    scanf("%f", &interestRate);
    printf("Enter Loan Term (in years): ");
    scanf("%f", &term);

    //converting years to months
    term *= 12;

    //Calculate monthly interest rate
    interestRate /= 1200;

    //Calculate monthly payment using Formula
    monthlyPayment = (loanAmount * interestRate) / (1 - (pow(1 / (1 + interestRate), term)));

    //Displaying Result
    printf("\nMonthly Payment = $%.2f\n", monthlyPayment);

    getchar();
    return 0;
}
//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: innovative
#include <stdio.h>
#include <math.h>

int main() {
    float loanAmount, interestRate, monthlyPayment, totalPayment, monthlyInterestRate, balance;
    int years, numberOfPayments, currentMonth;

    printf("Enter loan amount: ");
    scanf("%f", &loanAmount);

    printf("Enter interest rate: ");
    scanf("%f", &interestRate);

    printf("Enter number of years: ");
    scanf("%d", &years);

    monthlyInterestRate = interestRate / 1200;
    numberOfPayments = years * 12;
    balance = loanAmount;
    currentMonth = 1;

    printf("Month \t Payment \t Remaining Balance \n");
    while (currentMonth <= numberOfPayments) {
        monthlyPayment = (loanAmount * monthlyInterestRate) / (1 - pow(1 + monthlyInterestRate, -numberOfPayments));
        totalPayment += monthlyPayment;

        balance = balance - (monthlyPayment - (balance * monthlyInterestRate));
        printf("%d \t %0.2f \t %0.2f \n", currentMonth, monthlyPayment, balance);

        currentMonth++;
    }
    printf("\n\n");

    printf("Loan Amount: %0.2f \n", loanAmount);
    printf("Interest Rate: %0.2f \n", interestRate);

    printf("\nTotal payment made: %0.2f \n", totalPayment);
    printf("Total interest paid: %0.2f \n", totalPayment - loanAmount);

    return 0;
}
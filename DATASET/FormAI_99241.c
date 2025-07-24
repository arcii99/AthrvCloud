//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: shocked
#include <stdio.h>

int main() {
    printf("Welcome to Shocking Mortgage Calculator!\n");
    printf("Please enter the loan amount: ");

    float loanAmount;
    scanf("%f", &loanAmount);

    printf("Please enter the interest rate (in percentage): ");
    float interestRate;
    scanf("%f", &interestRate);

    printf("Please enter the loan term (in years): ");
    float loanTerm;
    scanf("%f", &loanTerm);

    float monthlyInterestRate = interestRate / 12.0 / 100.0;
    float monthlyPayment = (loanAmount * monthlyInterestRate) / (1 - pow(1 + monthlyInterestRate, -loanTerm * 12));

    printf("\nYour monthly payment is: $%.2f\n", monthlyPayment);
    printf("Total interest paid: $%.2f\n", (monthlyPayment * (loanTerm * 12)) - loanAmount);

    printf("\n");
    printf("That's all folks! Come back again when you realize that a mortgage is a bad investment! \n");

    return 0;
}
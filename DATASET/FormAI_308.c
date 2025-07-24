//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: peaceful
#include <stdio.h>

int main() {
    double loanAmount, interestRate, monthlyRate, paymentAmount;
    int loanTerm;

    printf("Welcome to the Peaceful Mortgage Calculator!\n");

    printf("Please enter the amount of your loan: ");
    scanf("%lf", &loanAmount);

    printf("Please enter the interest rate (in percentage): ");
    scanf("%lf", &interestRate);
    monthlyRate = interestRate / 1200.0;

    printf("Please enter the term of your loan (in years): ");
    scanf("%d", &loanTerm);

    paymentAmount = (loanAmount * monthlyRate) / (1 - (1 / pow(1 + monthlyRate, loanTerm * 12)));
    printf("\nYour monthly payment is: $%.2lf\n", paymentAmount);

    printf("\nThank you for using the Peaceful Mortgage Calculator!\n");

    return 0;
}
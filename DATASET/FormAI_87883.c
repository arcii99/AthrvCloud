//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: genious
#include <stdio.h>
#include <math.h>

int main()
{
    float loanAmount, interestRate, monthlyRate, months, payment;

    printf("Enter the Loan Amount: $ ");
    scanf("%f", &loanAmount);

    printf("Enter the Interest Rate: ");
    scanf("%f", &interestRate);

    printf("Enter the Loan Term (in months): ");
    scanf("%f", &months);

    monthlyRate = (interestRate / 100) / 12;

    payment = (loanAmount * monthlyRate) / (1 - pow((1 + monthlyRate), (-1 * months)));

    printf("\nYour Monthly Payment is: $%.2f\n", payment);

    return 0;
}
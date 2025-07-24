//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: innovative
#include <stdio.h>

int main() {
    // welcome message
    printf("Welcome to the Mortgage Calculator!\n");

    // input variables
    double loanAmount, interestRate, monthlyPayment;
    int years;

    // get user input
    printf("Enter the loan amount: ");
    scanf("%lf", &loanAmount);

    printf("Enter the interest rate: ");
    scanf("%lf", &interestRate);

    printf("Enter the loan term (in years): ");
    scanf("%d", &years);

    // calculate monthly interest rate
    double monthlyInterestRate = interestRate / 1200;

    // calculate monthly payment
    monthlyPayment = (loanAmount * monthlyInterestRate) / (1 - pow(1 + monthlyInterestRate, -years * 12));

    // output monthly payment
    printf("Your monthly payment is: $%.2lf\n", monthlyPayment);

    return 0;
}
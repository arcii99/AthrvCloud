//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: romantic
#include <stdio.h>

int main() {
    float loanAmount, interestRate, monthlyPayment;
    int numOfYears;

    printf("Oh, my beloved, let me help you with your mortgage,\n");
    printf("Please tell me the loan amount you're borrowing?\n");
    scanf("%f", &loanAmount);

    printf("And how many years will you be committing to repay it with your might and main?\n");
    scanf("%d", &numOfYears);

    printf("At what romantic interest rate, will you be taking this loan, my dear?\n");
    scanf("%f", &interestRate);

    float rate = interestRate / 1200;
    int months = numOfYears * 12;
    monthlyPayment = (loanAmount * rate) / (1 - (pow(1 + rate, -months)));

    printf("\nOh, my love, thank the heavens that we have this equation to share our common goal,\n");
    printf("The monthly payment of the mortgage you are taking will be: $%.2f\n", monthlyPayment);

    return 0;
}
//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: Sherlock Holmes
#include <stdio.h>

int main() {

    printf("Ah, Watson, welcome back. I see you've arrived at the perfect time. I require your assistance with a new case.\n");
    printf("A young couple has approached me, seeking a loan to purchase their first home. However, they are unsure of the terms and repayments on the mortgage.\n");
    printf("I believe it's time to put our brains to work and create a Mortgage Calculator program to assist them!\n");
    printf("Let us begin by collecting the necessary data.\n\n");

    float loanAmount;
    printf("What is the amount of the loan required in pounds? ");
    scanf("%f", &loanAmount);

    float interestRate;
    printf("What is the interest rate on the loan (as a decimal)? ");
    scanf("%f", &interestRate);

    float loanTerm;
    printf("What is the length of the loan term (in years)? ");
    scanf("%f", &loanTerm);

    float monthlyInterest = interestRate/12;
    float loanMonths = loanTerm*12;
    float monthlyRepayment = (loanAmount * monthlyInterest)/(1 - pow((1 + monthlyInterest), -loanMonths));

    printf("\nExcellent, Watson. Now, let us put this data into our Mortgage Calculator program.\n");

    printf("\nThe loan amount required: £%.2f\n", loanAmount);
    printf("The interest rate on the loan: %.2f%%\n", interestRate*100);
    printf("The length of the loan term: %0.0f years\n", loanTerm);

    printf("\nThe calculated monthly repayment on the loan: £%.2f\n", monthlyRepayment);

    printf("\nThat wasn't too difficult, was it Watson?\n");

    return 0;
}
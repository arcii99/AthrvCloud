//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Welcome to our Crazy Mortgage Calculator program!

int main() {

    printf("Welcome to the Crazy Mortgage Calculator!\n");
    printf("This program is designed to help you calculate your monthly mortgage payments.\n");

    float loanAmount = 0, interestRate = 0, monthlyPayment = 0;
    int numMonths = 0;

    printf("\nEnter the amount of the loan: ");
    scanf("%f", &loanAmount);

    printf("Enter the interest rate (percent): ");
    scanf("%f", &interestRate);

    printf("Enter the number of months for repayment: ");
    scanf("%d", &numMonths);

    // Let's make some crazy calculations!
    monthlyPayment = ((loanAmount * (interestRate / 100)) / 12) / (1 - (pow((1 + (interestRate / 100) / 12), (-numMonths))));

    printf("\nYour monthly payment is: $%.2f.\n", monthlyPayment);

    // Let's have some fun with the output!
    int i;
    printf("\nHere's your mortgage payment broken down by month:\n");

    for (i = 1; i <= numMonths; i++) {
        printf("Month %d: $%.2f\n", i, monthlyPayment);
    }

    // Let's add some flair to the end of our program!
    printf("\nThank you for using our Crazy Mortgage Calculator!\n");
    printf("We hope you find it helpful (and a little bit fun too)!\n");

    return 0;
}
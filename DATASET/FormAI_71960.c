//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    float mortgageAmount, interestRate, numberOfYears, monthlyPayment, totalCost;
    char input;

    printf("Mortgage Calculator\n");

    do {
        printf("\nEnter the mortgage amount: $");
        scanf("%f", &mortgageAmount);

        printf("Enter the interest rate: ");
        scanf("%f", &interestRate);

        printf("Enter the number of years for the loan: ");
        scanf("%f", &numberOfYears);

        interestRate /= 1200;
        numberOfYears *= 12;

        monthlyPayment = mortgageAmount * interestRate / (1 - (float)pow(1 + interestRate, -numberOfYears));
        totalCost = monthlyPayment * numberOfYears;

        printf("\nMonthly payment: $%.2f", monthlyPayment);
        printf("\nTotal cost of loan: $%.2f\n", totalCost);

        printf("\nDo you want to calculate another mortgage? (Y/N) ");
        fflush(stdin);
        scanf("%c", &input);

    } while (toupper(input) == 'Y');

    return 0;
}
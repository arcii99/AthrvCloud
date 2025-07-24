//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: happy
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Welcome to the Happy Mortgage Calculator!\n");
    printf("Let's see how much house you can afford.\n\n");

    float income, expenses, interest, downPayment, price;
    printf("What is your total monthly income? ");
    scanf("%f", &income);

    printf("What are your total monthly expenses? ");
    scanf("%f", &expenses);

    printf("What is the current interest rate? ");
    scanf("%f", &interest);

    printf("How much can you put down as a down payment? ");
    scanf("%f", &downPayment);

    printf("\nBased on your inputs:\n");
    printf("Total monthly income: $%.2f\n", income);
    printf("Total monthly expenses: $%.2f\n", expenses);
    printf("Interest rate: %.2f%%\n", interest);
    printf("Down payment: $%.2f\n", downPayment);

    printf("\nNow, let's calculate the maximum house price you can afford.\n\n");

    // Calculation
    float monthlyPayment = (income - expenses) * 0.3;
    float loanAmount = (price - downPayment);
    float monthlyInterestRate = (interest / 100) / 12.0;
    float numberOfPayments = 30 * 12; // Assuming a 30 year mortgage
    float x = pow(1 + monthlyInterestRate, numberOfPayments);
    float monthly = (loanAmount * x * monthlyInterestRate) / (x - 1);

    printf("Based on a 30 year mortgage and a monthly payment of no more than 30%% of your income:\n");
    printf("You can afford a house priced at: $%.2f\n", monthlyPayment / monthly);
    printf("That means leveraging a home loan of no more than: $%.2f\n", monthlyPayment / monthly * 0.75);
    printf("and making a down payment of: $%.2f\n", monthlyPayment / monthly * 0.25);
    return 0;
}
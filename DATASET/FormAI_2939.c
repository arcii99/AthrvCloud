//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

int main()
{
    float income = 0;
    float expenses = 0;
    float savings = 0;

    printf("Welcome to the personal finance planner.\n");
    printf("Please enter your monthly income:  $");
    scanf("%f", &income);
    printf("Please enter your monthly expenses:  $");
    scanf("%f", &expenses);

    savings = income - expenses;

    printf("\n\n********** FINANCIAL SUMMARY **************\n\n");
    printf("Monthly Income:          $%6.2f\n", income);
    printf("Monthly Expenses:        $%6.2f\n", expenses);
    printf("Monthly Savings:         $%6.2f\n", savings);

    if (savings > 0)
    {
        printf("\nCongratulations. You are living below your means and saving money every month!\n");
    }
    else if (savings < 0)
    {
        printf("\nOh no! You are spending more than you make. You need to adjust your budget.\n");
    }
    else
    {
        printf("\nYou are breaking even. You should look for ways to increase your income or decrease your expenses.\n");
    }

    printf("\nThank you for using the personal finance planner!\n");

    return 0;
}
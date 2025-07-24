//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: single-threaded
#include<stdio.h>
#include<stdlib.h>

float income, expense, savings;
int months;

int main()
{
    printf("********** Personal Finance Planner **********\n");

    printf("Enter your monthly income: ");
    scanf("%f", &income);

    printf("Enter your monthly expenses: ");
    scanf("%f", &expense);

    printf("Enter the number of months you want to plan: ");
    scanf("%d", &months);

    savings = (income - expense)*months;

    printf("\n\nMonth\tIncome\t\tExpense\t\tSavings\n");
    for(int i=1; i<=months; i++)
    {
        printf("%d\t%.2f\t\t%.2f\t\t%.2f\n", i, income, expense, savings);
        income = income*1.05; //Assuming 5% increase in income per month
        expense = expense*1.03; //Assuming 3% increase in expenses per month
        savings = savings + ((income - expense)*months);
    }

    printf("\n**********************************************************\n");
    printf("Total savings after %d months: %.2f\n", months, savings);

    return 0;
}
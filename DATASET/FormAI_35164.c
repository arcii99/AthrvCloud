//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: random
#include<stdio.h>
#include<stdlib.h>

int main()
{
    float balance, income, expense, savings, total_expense = 0;
    int n, i;

    printf("\n*** PERSONAL FINANCE PLANNER ***\n");
    printf("\nEnter your starting balance: ");
    scanf("%f", &balance);

    printf("\nEnter number of expenses: ");
    scanf("%d", &n);

    float* expense_arr = (float*)malloc(n*sizeof(float));

    printf("\nEnter your expenses:\n");
    for(i=0; i<n; i++)
    {
        printf("Expense %d: ", i+1);
        scanf("%f", &expense_arr[i]);
        total_expense += expense_arr[i];
    }

    printf("\nEnter your income: ");
    scanf("%f", &income);

    savings = income - total_expense;
    balance += savings;

    printf("\n*** FINANCIAL SUMMARY ***\n");
    printf("Starting Balance: $%.2f\n", balance);
    printf("Total expenses: $%.2f\n", total_expense);
    printf("Income: $%.2f\n", income);
    printf("Savings: $%.2f\n", savings);
    printf("Ending Balance: $%.2f\n", balance);

    free(expense_arr);

    return 0;
}
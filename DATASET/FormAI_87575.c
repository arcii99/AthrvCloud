//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: shocked
#include<stdio.h>
#include<stdlib.h>

void main()
{
    float salary, expenses, savings;
    int months;
    printf("\nWelcome to the Personal Finance Planner!");
    printf("\nEnter your monthly salary: ");
    scanf("%f", &salary);
    printf("\nEnter your monthly expenses: ");
    scanf("%f", &expenses);
    printf("\nEnter the number of months you want to plan for: ");
    scanf("%d", &months);
    printf("\nCalculating your savings for the next %d months...", months);
    savings = (salary - expenses) * months;
    printf("\nYou can save $%.2f in %d months if you stick to your budget!",savings,months);
    if (savings >= (salary * months * 0.5))
    {
        printf("\nWow! You're saving more than 50 percent of your income. Impressive!");
    }
    else if (savings >= (salary * months * 0.3))
    {
        printf("\nYou're saving about 30 percent of your income. Keep up the good work!");
    }
    else
    {
        printf("\nYou're saving less than 30 percent of your income. You might need to adjust your budget.");
    }
    printf("\nThanks for using the Personal Finance Planner. Have a good day!");
}
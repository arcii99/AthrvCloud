//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: Alan Touring
#include <stdio.h>

int main()
{
    float salary, expenses, savings;

    printf("Enter your monthly salary: ");
    scanf("%f", &salary);

    printf("Enter your monthly expenses: ");
    scanf("%f", &expenses);

    savings = salary - expenses;

    if (savings < 0)
    {
        printf("\nYou have a deficit of $%.2f. You need to cut down your expenses.", savings);
    }
    else if (savings == 0)
    {
        printf("\nYou have no savings. You need to start saving.");
    }
    else
    {
        printf("\nYour monthly savings are $%.2f. You are doing great!", savings);
    }

    return 0;
}
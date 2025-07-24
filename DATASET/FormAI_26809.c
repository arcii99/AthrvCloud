//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: rigorous
#include <stdio.h>

int main()
{
    float salary, rent, utilities, groceries, transportation, extras, total_expenses, savings;
    
    printf("Welcome to the Personal Finance Planner!\n\n");
    printf("Please enter your monthly income: ");
    scanf("%f", &salary);
    
    printf("\nEnter your monthly rent/mortgage payment: ");
    scanf("%f", &rent);
    
    printf("\nEnter your monthly utilities cost: ");
    scanf("%f", &utilities);
    
    printf("\nEnter your monthly groceries cost: ");
    scanf("%f", &groceries);
    
    printf("\nEnter your monthly transportation cost: ");
    scanf("%f", &transportation);
    
    printf("\nEnter the amount of money you spend on extras (i.e. entertainment, dining out): ");
    scanf("%f", &extras);
    
    total_expenses = rent + utilities + groceries + transportation + extras;
    savings = salary - total_expenses;
    
    printf("\nYour total monthly expenses are: $%.2f\n", total_expenses);
    printf("\nYour estimated monthly savings are: $%.2f\n", savings);
    
    if(savings < 0)
    {
        printf("\nUh-oh! You are spending more than you earn. Consider cutting back on some expenses.\n");
    }
    else if(savings >= 0 && savings < (salary * 0.10))
    {
        printf("\nYou are saving less than 10 percent of your monthly income. Try increasing your savings!\n");
    }
    else
    {
        printf("\nGreat job! You are saving at least 10 percent of your monthly income.\n");
    }
    
    return 0;
}
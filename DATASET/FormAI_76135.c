//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: relaxed
#include <stdio.h>

int main()
{
    float income, expenses, savings;
    
    printf("Welcome to the Personal Finance Planner!\n\n");
    
    printf("Please enter your monthly income: ");
    scanf("%f", &income);
    
    printf("Please enter your monthly expenses: ");
    scanf("%f", &expenses);
    
    savings = income - expenses;
    
    printf("\nYour total savings for this month: $%.2f\n", savings);
    
    if(savings >= 500)
    {
        printf("Congratulations! You are on track to achieve your financial goals.\n");
    }
    else if(savings >= 200)
    {
        printf("You are doing decently, but there is room for improvement.\n");
    }
    else
    {
        printf("You need to reconsider your expenses and find ways to save more!\n");
    }
    
    return 0;
}
//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

int main()
{
    float income, expense, savings, total_savings = 0;
    int num_months;
    
    // Input the user's monthly income and expense.
    printf("Enter your monthly income: ");
    scanf("%f", &income);
    printf("Enter your monthly expenses: ");
    scanf("%f", &expense);
    
    // Calculate the user's monthly savings and total savings over a specified number of months.
    printf("How many months would you like to calculate for? ");
    scanf("%d", &num_months);
    
    printf("\n");
    printf("MONTH\tINCOME\tEXPENSE\tSAVINGS\tTOTAL SAVINGS\n");
    
    for (int i = 1; i <= num_months; i++)
    {
        savings = income - expense;
        total_savings += savings;
        
        printf("%d\t%.2f\t%.2f\t%.2f\t%.2f\n", i, income, expense, savings, total_savings);
        
        // Update the user's income and expense for the next month based on their previous month's savings.
        income *= 1.05; // Assume a 5% increase in income each month.
        expense *= 1.03; // Assume a 3% increase in expenses each month.
    }
    
    return 0;
}
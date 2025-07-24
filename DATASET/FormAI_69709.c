//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: Ken Thompson
#include <stdio.h>

int main() {
    float income, rent, food, utilities, transportation, other_expenses, savings;
    
    printf("Enter your monthly income: ");
    scanf("%f", &income);
    
    printf("Enter your monthly rent or mortgage payment: ");
    scanf("%f", &rent);
    
    printf("Enter your monthly food expenses: ");
    scanf("%f", &food);
    
    printf("Enter your average monthly utility bills: ");
    scanf("%f", &utilities);
    
    printf("Enter your average monthly transportation expenses: ");
    scanf("%f", &transportation);
    
    printf("Enter any other monthly expenses: ");
    scanf("%f", &other_expenses);
    
    savings = income - (rent + food + utilities + transportation + other_expenses);
    
    printf("Based on your input, you have $%.2f left to save or invest each month.\n", savings);
    
    int num_months;
    float total_savings = 0;
    
    printf("\nHow many months would you like to track your savings for?: ");
    scanf("%d", &num_months);
    
    for(int i = 1; i <= num_months; i++) {
        printf("\nEnter your savings for month %d: $", i);
        float monthly_savings;
        scanf("%f", &monthly_savings);
        
        total_savings += monthly_savings;
    }
    
    printf("\nOver the past %d months, you have saved a total of $%.2f\n", num_months, total_savings);
    
    return 0;
}
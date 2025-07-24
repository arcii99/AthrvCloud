//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

int main() {
    float income, expenses, savings, investments;
    
    //Getting input from user
    printf("Enter your monthly income: $");
    scanf("%f", &income);
    
    printf("Enter your monthly expenses: $");
    scanf("%f", &expenses);
    
    //Calculating savings and investments
    savings = income - expenses;
    
    if (savings <= 0) {
        printf("You have no savings this month.\n");
    }
    else {
        printf("You have saved $%.2f this month.\n", savings);
    }
    
    investments = (savings * 0.25);
    
    printf("You should invest $%.2f this month.\n", investments);
    
    //Calculating financial goals
    float emergency_fund = (income * 3);
    float down_payment = (income * 0.2);
    float retirement_fund = (income * 0.15);
    
    printf("\nYour financial goals for this month:\n");
    printf("-------------------------------------\n");
    printf("1. Emergency Fund: $%.2f\n", emergency_fund);
    printf("2. Down Payment for Home: $%.2f\n", down_payment);
    printf("3. Retirement Fund: $%.2f\n", retirement_fund);
    
    system("pause");
    return 0;
}
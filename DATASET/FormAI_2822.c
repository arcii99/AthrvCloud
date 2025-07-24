//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: visionary
#include <stdio.h>

int main()
{
    float monthly_income, housing_expenses, transportation_expenses, food_expenses, entertainment_expenses, savings;
    
    //Get input from user
    printf("Enter your monthly income: ");
    scanf("%f", &monthly_income);
    
    printf("Enter your monthly housing expenses: ");
    scanf("%f", &housing_expenses);
    
    printf("Enter your monthly transportation expenses: ");
    scanf("%f", &transportation_expenses);
    
    printf("Enter your monthly food expenses: ");
    scanf("%f", &food_expenses);
    
    printf("Enter your monthly entertainment expenses: ");
    scanf("%f", &entertainment_expenses);
    
    printf("Enter your desired monthly savings: ");
    scanf("%f", &savings);
    
    //Calculate expenses and savings
    float total_expenses = housing_expenses + transportation_expenses + food_expenses + entertainment_expenses;
    float remaining_income = monthly_income - total_expenses - savings;
    
    //Print budget breakdown
    printf("\n-----MONTHLY BUDGET BREAKDOWN-----\n");
    printf("Monthly Income: $%.2f\n", monthly_income);
    printf("Housing Expenses: $%.2f\n", housing_expenses);
    printf("Transportation Expenses: $%.2f\n", transportation_expenses);
    printf("Food Expenses: $%.2f\n", food_expenses);
    printf("Entertainment Expenses: $%.2f\n", entertainment_expenses);
    printf("Total Expenses: $%.2f\n", total_expenses);
    printf("Desired Monthly Savings: $%.2f\n", savings);
    printf("Remaining Income: $%.2f\n", remaining_income);
    
    return 0;
}
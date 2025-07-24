//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

float income;
float bills;
float rent;
float expenses;
float savings;

int main()
{
    printf("Welcome to the Personal Finance Planner!\n\n");
    
    printf("Please enter your monthly income: $");
    scanf("%f", &income);
    
    printf("Please enter your monthly bills (excluding rent): $");
    scanf("%f", &bills);
    
    printf("Please enter your monthly rent: $");
    scanf("%f", &rent);
    
    expenses = bills + rent;
    savings = income - expenses;
    
    printf("\n\n---------------------------------\n");
    printf("MONTHLY EXPENSES\n");
    printf("---------------------------------\n\n");
    printf("Bills: $%.2f\n", bills);
    printf("Rent: $%.2f\n", rent);
    printf("\nTotal Expenses: $%.2f\n\n", expenses);
    
    printf("---------------------------------\n");
    printf("MONTHLY SAVINGS\n");
    printf("---------------------------------\n\n");
    printf("Income: $%.2f\n", income);
    printf("Expenses: $%.2f\n", expenses);
    printf("\nTotal Savings: $%.2f\n\n", savings);
    
    printf("---------------------------------\n\n");
    printf("Thank you for using the Personal Finance Planner!\n\n");
    
    return 0;
}
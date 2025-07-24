//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: systematic
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int choice, expense, income, budget, savings;
    
    printf("Welcome to Personal Finance Planner\n");
    printf("1. Calculate Monthly Budget\n2. Calculate Monthly Savings\n3. Exit\n");
    printf("Please select your choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            printf("Enter your monthly income: ");
            scanf("%d", &income);
            printf("Enter your monthly expenses: ");
            scanf("%d", &expense);
            budget = income - expense;
            printf("Your monthly budget is: %d\n", budget);
            break;
        
        case 2:
            printf("Enter your monthly income: ");
            scanf("%d", &income);
            printf("Enter your monthly expenses: ");
            scanf("%d", &expense);
            savings = income - expense;
            printf("Your monthly savings are: %d\n", savings);
            break;
        
        case 3:
            printf("Thank you for using Personal Finance Planner!");
            exit(0);
            break;
        
        default:
            printf("Invalid choice! Please select correct choice.\n");
    }

    return 0;
}
//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: curious
#include<stdio.h>

int main()
{
    float salary, savings, expense;
    int rent, bills, food;
    
    printf("Welcome to the Personal Finance Planner!\n\n");
    printf("Please enter your monthly salary: ");
    scanf("%f", &salary);
    
    printf("Please enter your monthly expense on rent: ");
    scanf("%d", &rent);
    
    printf("Please enter your monthly utility bills expense: ");
    scanf("%d", &bills);
    
    printf("Please enter your monthly expense on food: ");
    scanf("%d", &food);
    
    expense = rent + bills + food;
    savings = salary - expense;
    
    printf("\nYour monthly expense is: %f", expense);
    printf("\nYour monthly savings is: %f", savings);
    
    if(savings > (salary/2))
    {
        printf("\n\nCongratulations! You are a good saver");
    }
    else if(savings <= (salary/2) && savings > (salary/4))
    {
        printf("\n\nYou are saving well but can do better. Keep it up!");
    }
    else
    {
        printf("\n\nYou need to cut down on your expenses and save more.");
    }
    
    return 0;
}
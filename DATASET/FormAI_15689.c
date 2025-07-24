//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

int main() {
    // declare variables
    float income, savings, expenses, investments, networth;
    char name[50];

    // ask for user input
    printf("Welcome to Personal Finance Planner!\n");
    printf("Please enter your name: ");
    scanf("%s", name);
    printf("Hello %s!\n", name);
    printf("Please enter your monthly income: $");
    scanf("%f", &income);
    printf("Please enter your monthly expenses: $");
    scanf("%f", &expenses);
    printf("Please enter your current savings: $");
    scanf("%f", &savings);
    printf("Please enter your monthly investments: $");
    scanf("%f", &investments);
    
    // calculate net worth
    networth = savings + investments;

    // display results
    printf("\nHere is your monthly finance report:\n");
    printf("------------------------------------\n");
    printf("Income: $%.2f\n", income);
    printf("Expenses: $%.2f\n", expenses);
    printf("Savings: $%.2f\n", savings);
    printf("Investments: $%.2f\n", investments);
    printf("Net Worth: $%.2f\n", networth);
    
    // determine if user is on track to reach financial goals
    if (networth >= 10000) {
        printf("\nGreat job %s! You are on track to achieving your financial goals!", name);
    } else {
        printf("\nOops %s, you still have some work to do to achieve your financial goals.", name);
    }

    return 0;
}
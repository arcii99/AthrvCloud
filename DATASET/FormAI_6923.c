//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: thoughtful
#include<stdio.h>
#include<stdlib.h>

int main(){
    float income, expenses, savings;
    int choice;
    // User Input
    printf("Enter your monthly income: $");
    scanf("%f", &income);
    printf("Enter your monthly expenses: $");
    scanf("%f", &expenses);
    // Calculations
    savings = income - expenses;
    // Display Menu
    printf("\nWhat do you want to do?\n");
    printf("1. Calculate Savings Rate\n");
    printf("2. Calculate Emergency Fund\n");
    printf("3. Calculate Debt-to-Income Ratio\n");
    printf("4. Quit\n");
    // User Input
    printf("\nEnter your choice: ");
    scanf("%d", &choice);
    // Menu switch statement
    switch(choice){
        case 1:
            printf("\nYour current savings rate is %.2f%%\n", ((savings / income) * 100));
            break;
        case 2:
            printf("\nYour emergency fund should have at least 6 months' worth of expenses, which is $%.2f\n", (expenses * 6));
            break;
        case 3:
            printf("\nYour debt-to-income ratio is %.2f%%\n", ((expenses / income) * 100));
            break;
        case 4:
            printf("\nThank you for using the Personal Finance Planner. Goodbye!\n");
            exit(0);
        default:
            printf("\nInvalid input. Please try again.\n");
            break;
    }
    return 0;
}
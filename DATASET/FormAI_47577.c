//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: all-encompassing
#include <stdio.h>

struct expense {
    char category[20];
    double amount;
};

int main()
{
    struct expense expenses[100]; // creating an array of expense structures to store expenses
    
    int numExpenses;
    double totalExpenses = 0;

    // get input from user on number of expenses
    printf("Enter the number of expenses: ");
    scanf("%d", &numExpenses);
    
    // get input from user on expense details
    for (int i = 0; i < numExpenses; i++) {
        printf("Enter the category of expense %d: ", i+1);
        scanf("%s", expenses[i].category);
        printf("Enter the amount of expense %d: ", i+1);
        scanf("%lf", &expenses[i].amount);
        totalExpenses += expenses[i].amount; // add to the total expenses
    }
    
    // print out the total expenses and category wise expenses
    printf("\nTotal expenses: $%.2lf\n\n", totalExpenses);
    printf("Category Wise Expenses:\n");
    for (int i = 0; i < numExpenses; i++) {
        printf("%s: $%.2lf\n", expenses[i].category, expenses[i].amount);
    }
    
    return 0;
}
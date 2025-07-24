//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

int main() {
    float income, expenses, savings, discretionary;

    //Accepting values for income and expenses from the user
    printf("Enter Your Monthly Income: ");
    scanf("%f", &income);

    printf("Enter Your Monthly Expenses: ");
    scanf("%f", &expenses);

    //Calculating the Amount Left for Savings and Discretionary Spending
    savings = (income * (float) 0.5) - expenses;
    discretionary = (income * (float) 0.3) - expenses;

    printf("\n\nYour Monthly Financial Plan:\n");

    //Displaying the Calculated Values
    printf("Amount Left for Savings: $%.2f\n", savings);
    printf("Amount Left for Discretionary Spending: $%.2f\n", discretionary);

    //Checking if the Amount Left is 0 or Less
    if (savings <= 0) {
        printf("\n\nYou Need to Cut Down Your Expenses and/or Increase Your Income to Meet Your Financial Goals\n\n");
    } else {
        printf("\n\nYou Can Continue to Save and Meet Your Financial Goals.\n\n");
    }

    return 0;
}
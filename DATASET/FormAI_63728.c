//FormAI DATASET v1.0 Category: Expense Tracker ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int num_of_expenses;
    printf("Enter the number of expenses: ");
    scanf("%d", &num_of_expenses);

    // Dynamically allocate memory for expenses
    float *expenses = (float *)malloc(num_of_expenses * sizeof(float));

    // Take input for each expense and store in expenses array
    for(int i = 0; i < num_of_expenses; i++) {
        printf("Enter expense #%d: ", i+1);
        scanf("%f", &expenses[i]);
    }

    // Calculate the sum of expenses
    float total_expenses = 0;
    for(int i = 0; i < num_of_expenses; i++) {
        total_expenses += expenses[i];
    }

    // Display the expense report to user
    printf("\n---------------------\n");
    printf("    Expense Report    \n");
    printf("---------------------\n");
    for(int i = 0; i < num_of_expenses; i++) {
        printf("Expense #%d: $%.2f\n", i+1, expenses[i]);
    }
    printf("---------------------\n");
    printf("Total Expenses: $%.2f\n", total_expenses);
    printf("---------------------\n");

    // Clean up memory
    free(expenses);

    return 0;
}
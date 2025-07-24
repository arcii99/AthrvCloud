//FormAI DATASET v1.0 Category: Expense Tracker ; Style: accurate
#include <stdio.h>

int main()
{
    float expenses[10];
    float totalExpenses = 0.0;
    
    // Taking user input and calculating total expenses
    printf("Enter your expenses for the month:\n");
    for(int i=0; i<10; i++){
        printf("\tExpense #%d: $", i+1);
        scanf("%f", &expenses[i]);
        totalExpenses += expenses[i];    
    }
    
    // Displaying the entered expenses
    printf("\nYour expenses for the month are:\n");
    for(int i=0; i<10; i++){
        printf("\tExpense #%d: $%.2f\n", i+1, expenses[i]);
    }
    
    // Displaying total expenses
    printf("\nTotal expenses for the month: $%.2f\n", totalExpenses);
    
    return 0;
}
//FormAI DATASET v1.0 Category: Expense Tracker ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

#define MAX_EXPENSES 100

int main(void)
{
    float expenses[MAX_EXPENSES];
    int numExpenses = 0;
    float totalExpenses = 0;
    
    while (1) {
        printf("Enter expense (or -1 to exit): ");
        scanf("%f", &expenses[numExpenses]);
        
        if (expenses[numExpenses] == -1) {
            break;
        }
        
        numExpenses++;
        
        if (numExpenses >= MAX_EXPENSES) {
            printf("Maximum number of expenses reached.\n");
            break;
        }
    }
    
    printf("\nExpenses:\n");
    
    for (int i = 0; i < numExpenses; i++) {
        printf("%.2f\n", expenses[i]);
        totalExpenses += expenses[i];
    }
    
    printf("\nTotal expenses: %.2f\n", totalExpenses);
    
    return 0;
}
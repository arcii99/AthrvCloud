//FormAI DATASET v1.0 Category: Expense Tracker ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

//structure to store expense details
struct expense {
    int expenseId;
    char description[50];
    float cost;
};

int main() {
    int numExpenses;
    float totalCost = 0;
    printf("Enter the number of expenses: ");
    scanf("%d", &numExpenses);
    struct expense expenseArray[numExpenses];
    
    //input expense details
    for(int i=0; i<numExpenses; i++) {
        printf("\nEnter details of expense %d\n", (i+1));
        printf("ID: ");
        scanf("%d", &expenseArray[i].expenseId);
        printf("Description: ");
        scanf("%s", expenseArray[i].description);
        printf("Cost: ");
        scanf("%f", &expenseArray[i].cost);
        totalCost += expenseArray[i].cost;
    }
    
    //display expense details
    printf("\nExpense details\n");
    for(int i=0; i<numExpenses; i++) {
        printf("\nID: %d\n", expenseArray[i].expenseId);
        printf("Description: %s\n", expenseArray[i].description);
        printf("Cost: $%.2f\n", expenseArray[i].cost);
    }
    printf("\nTotal expenses: $%.2f\n", totalCost);
    return 0;
}
//FormAI DATASET v1.0 Category: Expense Tracker ; Style: authentic
#include <stdio.h>

struct expense {
    char name[50];
    float cost;
};

int main() {

    int numExpenses;
    float totalCost = 0.0;
    
    printf("How many expenses do you want to enter? ");
    scanf("%d", &numExpenses);
    
    struct expense expenses[numExpenses];
    
    for (int i=0; i<numExpenses; i++) {
        printf("Enter the name of expense #%d: ", i+1);
        scanf("%s", expenses[i].name);
        printf("Enter the cost of expense #%d: ", i+1);
        scanf("%f", &expenses[i].cost);
        totalCost += expenses[i].cost;
    }
    
    printf("\n\nExpenses Entered:\n");
    for (int i=0; i<numExpenses; i++) {
        printf("%s: $%.2f\n", expenses[i].name, expenses[i].cost);
    }
    
    printf("\nTotal Cost: $%.2f", totalCost);
    
    return 0;
}
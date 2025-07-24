//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: complete
#include <stdio.h>

struct Expenses {
    char name[50];
    double amount;
};

int main() {
    int numExpenses;
    double totalExpenses = 0;
    
    printf("How many expenses do you want to add? ");
    scanf("%d", &numExpenses);
    
    struct Expenses expense[numExpenses];
    
    for(int i=0; i<numExpenses; i++) {
        printf("\nEnter expense name: ");
        scanf("%s", &expense[i].name);
        printf("Enter amount for %s: $", expense[i].name);
        scanf("%lf", &expense[i].amount);
        totalExpenses += expense[i].amount;
    }
    
    printf("\n---------- EXPENSES ----------\n");
    for(int i=0; i<numExpenses; i++) {
        printf("%s \t $%.2f\n", expense[i].name, expense[i].amount);
    }
    printf("------------------------------\n");
    
    double income;
    printf("\nEnter your income for the month: $");
    scanf("%lf", &income);
    
    double savings = income - totalExpenses;
    printf("\nYou have $%.2f left for savings this month.\n", savings);
    
    return 0;
}
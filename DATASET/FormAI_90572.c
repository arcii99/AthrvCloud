//FormAI DATASET v1.0 Category: Expense Tracker ; Style: introspective
#include<stdio.h>
#include<stdlib.h>

struct Expenses {
    char category[20];
    float cost;
};

int main() {
    int n, i;
    float totalExpenses = 0;
    printf("Enter the number of expenses you want to track: ");
    scanf("%d", &n);

    struct Expenses *expenses = (struct Expenses*)malloc(n*sizeof(struct Expenses));

    // Taking expense details as input
    for(i=0; i<n; i++) {
        printf("\nEnter details for expense-%d\n", i+1);
        printf("Category: ");
        scanf("%s", (expenses+i)->category);
        printf("Cost: ");
        scanf("%f", &(expenses+i)->cost);
        totalExpenses += (expenses+i)->cost;
    }

    // Printing expense report
    printf("\n*******************EXPENSE REPORT*******************\n");
    printf("%-20s %-15s \n", "CATEGORY", "COST");
    for(i=0; i<n; i++) {
        printf("%-20s %-15.2f \n", (expenses+i)->category, (expenses+i)->cost);
    }
    printf("Total Expense: %.2f",totalExpenses);
    
    return 0;
}
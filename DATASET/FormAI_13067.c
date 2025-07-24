//FormAI DATASET v1.0 Category: Expense Tracker ; Style: genious
#include <stdio.h>

int main() {
    float expenses[30];
    int month, days;
    float totalExpenses = 0;
    printf("Enter the number of days in this month: ");
    scanf("%d", &days);
    printf("Enter the expenses for each day: \n");
    for (int i = 0; i < days; i++) {
        printf("Day %d: ", i+1);
        scanf("%f", &expenses[i]);
        totalExpenses += expenses[i];
    }
    printf("Total expenses for this month: $%.2f\n", totalExpenses);
    printf("Enter the number of months to track: ");
    int numMonths;
    scanf("%d", &numMonths);
    for (int i = 0; i < numMonths; i++) {
        printf("\nMONTH %d\n", i+1);
        printf("How many days in this month? ");
        scanf("%d", &days);
        totalExpenses = 0;
        for (int j = 0; j < days; j++) {
            printf("Day %d: ", j+1);
            scanf("%f", &expenses[j]);
            totalExpenses += expenses[j];
        }
        printf("Total expenses for this month: $%.2f\n", totalExpenses);
    }
    return 0;
}
//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: systematic
#include <stdio.h>

int main() {
    float monthlyIncome, monthlyExpenses, savings;
    int choice;

    printf("***********PERSONAL FINANCE PLANNER***********\n\n");

    printf("Enter your monthly income: ");
    scanf("%f", &monthlyIncome);

    printf("Enter your monthly expenses: ");
    scanf("%f", &monthlyExpenses);

    savings = monthlyIncome - monthlyExpenses;

    printf("Your monthly savings: %.2f\n\n", savings);

    printf("What would you like to do next?\n");
    printf("1. Calculate savings after a year\n");
    printf("2. Calculate savings after 5 years\n");
    printf("3. Exit\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Your savings after a year: %.2f\n", savings * 12);
            break;

        case 2:
            printf("Your savings after 5 years: %.2f\n", savings * 12 * 5);
            break;

        case 3:
            printf("Thank you for using Personal Finance Planner\n");
            return 0;

        default:
            printf("Invalid choice\n");
    }

    return 0;
}
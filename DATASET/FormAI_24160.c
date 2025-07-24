//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: cheerful
#include<stdio.h>

int main() {
    printf("Welcome to Personal Finance Planner!\n\n");
    float salary, expenses, savings;
    char choice;

    do {
        printf("Enter your monthly salary: ");
        scanf("%f", &salary);

        printf("Enter your monthly expenses: ");
        scanf("%f", &expenses);

        savings = salary - expenses;

        if (savings > 0) {
            printf("\nYou're doing great! Your monthly savings is $%.2f\n", savings);
        } else if (savings == 0) {
            printf("\nYou're breaking even. Keep it up!\n");
        } else {
            printf("\nUh oh! You're overspending. You need to cut back on your expenses.\n");
        }

        printf("\nDo you want to try again? (y/n): ");
        scanf(" %c", &choice);

    } while (choice == 'y' || choice == 'Y');

    printf("\nThank you for using Personal Finance Planner! Keep up the good work!\n");

    return 0;
}
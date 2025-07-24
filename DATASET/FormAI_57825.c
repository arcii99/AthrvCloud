//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

/*
 * PERSONAL FINANCE PLANNER
 * This program allows the user to keep track of their personal expenses and income over a set period of time. 
 * It prompts the user to input their income and expenses for each day.
 * At the end of the period, it displays a summary of their spending, income, and any savings.
 */

int main() {

    double income, expenses, savings = 0;
    int days, i;

    printf("Welcome to the Personal Finance Planner!\n");
    printf("How many days would you like to plan for? ");
    scanf("%d", &days);

    for (i = 1; i <= days; i++) {
        printf("\nDay %d\n", i);
        printf("What is your income for today? ");
        scanf("%lf", &income);
        printf("What is your total expenses for today? ");
        scanf("%lf", &expenses);
        savings += income - expenses;
    }

    printf("\nPERSONAL FINANCE SUMMARY\n");
    printf("Total income: $%.2lf\n", income * days);
    printf("Total expenses: $%.2lf\n", expenses * days);
    printf("Total savings: $%.2lf\n", savings);

    if (savings < 0) {
        printf("You have overspent by $%.2lf\n", -savings);
    } else {
        printf("You have saved $%.2lf\n", savings);
    }

    printf("Thank you for using the Personal Finance Planner!");

    return EXIT_SUCCESS;
}
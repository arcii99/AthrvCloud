//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: lively
#include <stdio.h>
#include <stdlib.h>

int main() 
{
    int salary, rent, groceries, utilities, transportation, insurance, other_expenses;
    int savings_goal, total_expenses, disposable_income;
    char buffer[100];

    printf("Welcome to your Personal Finance Planner!\n");
    printf("Let's get started by entering your monthly income: ");
    fgets(buffer, 100, stdin);
    salary = atoi(buffer);

    printf("Great! Now let's input your monthly expenses.\n");
    printf("Rent: ");
    fgets(buffer, 100, stdin);
    rent = atoi(buffer);

    printf("Groceries: ");
    fgets(buffer, 100, stdin);
    groceries = atoi(buffer);

    printf("Utilities: ");
    fgets(buffer, 100, stdin);
    utilities = atoi(buffer);

    printf("Transportation: ");
    fgets(buffer, 100, stdin);
    transportation = atoi(buffer);

    printf("Insurance: ");
    fgets(buffer, 100, stdin);
    insurance = atoi(buffer);

    printf("Other Expenses: ");
    fgets(buffer, 100, stdin);
    other_expenses = atoi(buffer);

    total_expenses = rent + groceries + utilities + transportation + insurance + other_expenses;

    printf("\nYour total monthly expenses are: %d\n", total_expenses);

    printf("Now, let's set a savings goal.\n");
    printf("How much money do you want to save per month? ");
    fgets(buffer, 100, stdin);
    savings_goal = atoi(buffer);

    disposable_income = salary - total_expenses;
    printf("\nYour monthly disposable income is: %d\n", disposable_income);

    if (disposable_income >= savings_goal) {
        printf("Congratulations! You have met your savings goal.\n");
    } else {
        printf("You have not met your savings goal. You need to save an additional $%d per month to reach your goal.\n", savings_goal - disposable_income);
    }

    return 0;
}
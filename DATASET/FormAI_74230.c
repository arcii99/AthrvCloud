//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    float income;
    float expenses;
    float savings;
} Budget;

void calculate_savings(Budget *budget) {
    budget->savings = budget->income - budget->expenses;
}

void print_budget(Budget budget) {
    printf("Income: $%.2f\n", budget.income);
    printf("Expenses: $%.2f\n", budget.expenses);
    printf("Savings: $%.2f\n", budget.savings);
}

void get_input(float *input) {
    char buffer[256];
    fgets(buffer, 256, stdin);
    *input = atof(buffer);
}

void run_program() {
    Budget budget;
    printf("Welcome to the Personal Finance Planner\n");
    printf("Please enter your monthly income: ");
    get_input(&budget.income);
    printf("Please enter your monthly expenses: ");
    get_input(&budget.expenses);
    calculate_savings(&budget);
    print_budget(budget);
}

int main() {
    run_program();
    return 0;
}
//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: lively
#include <stdio.h>
#include <stdlib.h>

// Function to calculate monthly expenses
float calculateMonthlyExpenses(float rent, float utilities, float groceries) {
    return rent + utilities + groceries;
}

// Function to calculate total annual savings
float calculateAnnualSavings(float salary, float monthlyExpenses) {
    return (salary - monthlyExpenses) * 12;
}

// Function to print financial report
void printFinancialReport(float salary, float rent, float utilities, float groceries) {
    float monthlyExpenses = calculateMonthlyExpenses(rent, utilities, groceries);
    float annualSavings = calculateAnnualSavings(salary, monthlyExpenses);

    printf("--------------------------------------------------\n");
    printf("               FINANCIAL REPORT                   \n");
    printf("--------------------------------------------------\n");
    printf("Salary: $%.2f\n", salary);
    printf("Monthly Expenses: $%.2f\n", monthlyExpenses);
    printf("Annual Savings: $%.2f\n", annualSavings);
    printf("--------------------------------------------------\n");
}

int main() {
    float salary = 50000;
    float rent = 1500;
    float utilities = 200;
    float groceries = 500;

    printFinancialReport(salary, rent, utilities, groceries);

    return 0;
}
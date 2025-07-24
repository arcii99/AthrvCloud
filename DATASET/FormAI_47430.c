//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

float calculate_tax(float income) {
    float tax_rate;
    if (income <= 50000) {
        tax_rate = 0.0;
    } else if (income <= 100000) {
        tax_rate = 0.10;
    } else if (income <= 250000) {
        tax_rate = 0.20;
    } else {
        tax_rate = 0.30;
    }
    return income * tax_rate;
}

int main() {
    float income;
    printf("\nEnter your yearly income: ");
    scanf("%f", &income);
    printf("\nIncome: $%.2f\n", income);
    printf("Tax: $%.2f\n", calculate_tax(income));

    float expenses;
    printf("\nEnter your monthly expenses: ");
    scanf("%f", &expenses);
    printf("\nExpenses: $%.2f\n", expenses);
    printf("Savings: $%.2f\n", (income/12) - expenses);

    float investment;
    printf("\nEnter the amount you want to invest monthly: ");
    scanf("%f", &investment);
    float total_savings = ((income/12) - expenses) + investment;
    printf("\nTotal savings per month: $%.2f\n", total_savings);

    float inflation_rate;
    printf("\nEnter the current inflation rate (in percentage %): ");
    scanf("%f", &inflation_rate);
    printf("\nProjected savings after one year (taking inflation into account): $%.2f\n", total_savings * (100/(100+inflation_rate)));
    printf("Projected savings after five years (taking inflation into account): $%.2f\n", total_savings * pow((100/(100+inflation_rate)),5));

    return 0;
}
//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: interoperable
#include<stdio.h>

float income; //declaring variables
float expenses;
float savings;
float debt;
float monthly_expenses;
float monthly_savings;
float monthly_debt;
float monthly_income;

int main() {
    printf("Enter your net income: ");
    scanf("%f",&income); //taking input from user
    printf("Enter your total monthly expenses: ");
    scanf("%f",&monthly_expenses);
    printf("Enter your total monthly debt payments: ");
    scanf("%f",&monthly_debt);

    expenses = monthly_expenses * 12; //calculating annual expenses
    debt = monthly_debt * 12; //calculating annual debt payments
    savings = income - expenses - debt; //calculating annual savings

    printf("Annual Income: $%.2f\n",income);
    printf("Annual Expenses: $%.2f\n",expenses);
    printf("Annual Debt Payments: $%.2f\n",debt);
    printf("Annual Savings: $%.2f\n",savings);

    monthly_income = income / 12; //calculating monthly income
    monthly_savings = savings / 12; //calculating monthly savings
    printf("\nMonthly Income: $%.2f\n",monthly_income);
    printf("Monthly Expenses: $%.2f\n",monthly_expenses);
    printf("Monthly Debt Payments: $%.2f\n",monthly_debt);
    printf("Monthly Savings: $%.2f\n",monthly_savings);

    return 0;
}
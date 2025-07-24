//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: recursive
#include <stdio.h>

float calculate_savings(int months, float savings, float monthly_income, float monthly_expenses) {
    if (months == 0) // base case
        return savings;
    savings += monthly_income - monthly_expenses;
    return calculate_savings(months-1, savings, monthly_income, monthly_expenses);
}

int main() {
    int num_months;
    float initial_savings, monthly_income, monthly_expenses;
    printf("Enter the number of months: ");
    scanf("%d", &num_months);
    printf("Enter the initial savings amount: ");
    scanf("%f", &initial_savings);
    printf("Enter the monthly income: ");
    scanf("%f", &monthly_income);
    printf("Enter the monthly expenses: ");
    scanf("%f", &monthly_expenses);

    printf("Savings at the end of %d months: %.2f\n", num_months,
           calculate_savings(num_months, initial_savings, monthly_income, monthly_expenses));
    return 0;
}
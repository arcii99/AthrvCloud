//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: interoperable
#include <stdio.h>

int main() {
    float monthlyIncome, monthlyExpenses, monthlySavings;
    int numOfMonths;

    printf("Enter your monthly income: ");
    scanf("%f", &monthlyIncome);

    printf("Enter your monthly expenses: ");
    scanf("%f", &monthlyExpenses);

    printf("Enter the number of months you want to plan for: ");
    scanf("%d", &numOfMonths);

    monthlySavings = monthlyIncome - monthlyExpenses;

    printf("\n\nMonth\t\tIncome\t\tExpenses\tSavings\n");
    for(int month = 1; month <= numOfMonths; month++){
        printf("%d\t\t%.2f\t\t%.2f\t\t%.2f\n", month, monthlyIncome, monthlyExpenses, monthlySavings);
    }

    printf("\n\nTotal Income: %.2f\nTotal Expenses: %.2f\nTotal Savings: %.2f", monthlyIncome*numOfMonths, monthlyExpenses*numOfMonths, monthlySavings*numOfMonths);

    return 0;
}
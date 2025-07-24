//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: scientific
#include <stdio.h>

int main() {
    float salary, expenses, savings, year;
    
    printf("Monthly Salary: ");
    scanf("%f", &salary);
    printf("Monthly Expenses: ");
    scanf("%f", &expenses);
    printf("Number of years to plan for: ");
    scanf("%f", &year);
    
    savings = (salary - expenses) * 12 * year;

    /* Calculate interest rate based on savings amount */
    float interestRate;
    if (savings < 10000) {
        interestRate = 0.02;
    } else if (savings < 50000) {
        interestRate = 0.05;
    } else {
        interestRate = 0.1;
    }

    /* Calculate savings with interest */
    float savingsWithInterest = savings * (1 + interestRate);

    /* Display results */
    printf("\nAnnual Salary: $%.2f\n", salary * 12);
    printf("Annual Expenses: $%.2f\n", expenses * 12);
    printf("Number of years planned for: %.0f\n", year);
    printf("Total Savings without interest: $%.2f\n", savings);
    printf("Total Savings with interest: $%.2f\n", savingsWithInterest);

    return 0;
}
//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: Ada Lovelace
#include <stdio.h>

int main() {
    float income, expenses, savings;
    printf("Enter your monthly income: $");
    scanf("%f", &income);
    printf("Enter your monthly expenses: $");
    scanf("%f", &expenses);
    savings = income - expenses;

    if (savings < 0) {
        printf("You're spending more than you're earning! You have a negative savings rate.\n");
    } else {
        printf("You have a positive savings rate of $%.2f per month.\n", savings);
    }

    // Investment calculations
    float investment, interest_rate, years;
    printf("Enter the amount you'd like to invest: $");
    scanf("%f", &investment);
    printf("Enter the expected annual interest rate (in decimal form): ");
    scanf("%f", &interest_rate);
    printf("Enter the number of years you plan to invest: ");
    scanf("%f", &years);

    double final_amount = investment * pow(1 + interest_rate, years);
    printf("After %.0f years, your investment will be worth $%.2f\n", years, final_amount);

    return 0;
}
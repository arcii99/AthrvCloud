//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: invasive
#include <stdio.h>

int main() {
    float salary, savings, expenses;
    int age, months_to_retirement;

    printf("Welcome to the Personal Finance Planner!\n");
    printf("Please enter your current age: ");
    scanf("%d", &age);

    printf("Please enter your current salary: $");
    scanf("%f", &salary);

    printf("Please enter your current monthly expenses: $");
    scanf("%f", &expenses);

    savings = salary * 0.2; // assuming saving 20% of salary
    printf("\nBased on your current salary, you should aim to save: $%.2f per month\n", savings);

    months_to_retirement = (65 - age) * 12; // assuming retirement age is 65
    printf("\nAssuming you retire at age 65, you have approximately %d months left until retirement.\n", months_to_retirement);

    float total_savings = savings * months_to_retirement;
    printf("\nIf you continue to save at this rate, you will have a total of $%.2f saved for retirement at age 65.\n", total_savings);

    float total_expenses = expenses * months_to_retirement;
    printf("\nAssuming your monthly expenses remain the same, you will spend a total of $%.2f until age 65.\n", total_expenses);

    float net_worth = total_savings - total_expenses;
    if (net_worth > 0) {
        printf("\nCongratulations! If you continue on this path, you will have a net worth of $%.2f at retirement!\n", net_worth);
    } else {
        printf("\nUh oh, it looks like you will not have enough saved up for retirement based on your current path.\n");
    }

    return 0;
}
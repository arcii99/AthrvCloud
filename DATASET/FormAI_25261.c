//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: Alan Touring
#include <stdio.h>

int main() {
    float income, expenses, savings;
    printf("Enter your monthly income: $");
    scanf("%f", &income);
    printf("Enter your monthly expenses: $");
    scanf("%f", &expenses);
    savings = income - expenses;
    printf("\nYour monthly savings: $%.2f\n\n", savings);
    printf("Budget allocation suggestions:\n");
    printf("Home expenses: %.2f%%\n", (expenses * 0.4) / income * 100);
    printf("Transportation expenses: %.2f%%\n", (expenses * 0.15) / income * 100);
    printf("Food expenses: %.2f%%\n", (expenses * 0.2) / income * 100);
    printf("Entertainment expenses: %.2f%%\n", (expenses * 0.1) / income * 100);
    printf("Investment: %.2f%%\n", (expenses * 0.15) / income * 100);
    printf("Emergency fund: %.2f%%\n", (expenses * 0.05) / income * 100);

    return 0;
}
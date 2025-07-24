//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: light-weight
#include <stdio.h>

int main() {
    float monthlyIncome, monthlyExpenses, savingsAmount;
    
    printf("Welcome to the Personal Finance Planner\n");
    printf("\nEnter your monthly income: ");
    scanf("%f", &monthlyIncome);
    
    printf("\nEnter your monthly expenses: ");
    scanf("%f", &monthlyExpenses);
    
    savingsAmount = monthlyIncome - monthlyExpenses;
    printf("\nYour monthly savings amount is: %f", savingsAmount);
    
    if (savingsAmount < 0) {
        printf("\n\nOops! It looks like you have a negative savings amount. Consider revising your monthly expenses.\n");
    } else if (savingsAmount < 500) {
        printf("\n\nGreat job! You are on track to saving money. Try to increase your savings amount to reach your financial goals faster.\n");
    } else if (savingsAmount < 1000) {
        printf("\n\nFantastic! You are saving a good amount of money. Keep up the good work.\n");
    } else {
        printf("\n\nWow! You are a true financial master. Keep up the amazing work.\n");
    }
    
    return 0;
}
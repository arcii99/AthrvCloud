//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: excited
#include <stdio.h>

int main() {
    printf("Welcome to Personal Finance Planner!\n");
    printf("Let's start by setting some financial goals.\n");
    
    float income, savingsGoal, monthlyExpenses;
    int numMonths;
    
    printf("What is your current monthly income? $");
    scanf("%f", &income);
    
    printf("What is your savings goal? $");
    scanf("%f", &savingsGoal);
    
    printf("What are your monthly expenses? $");
    scanf("%f", &monthlyExpenses);
    
    printf("In how many months would you like to achieve your savings goal? ");
    scanf("%d", &numMonths);
    
    float totalExpenses = monthlyExpenses * numMonths;
    float totalSavings = income * numMonths - totalExpenses;
    
    if (totalSavings >= savingsGoal) {
        printf("Congratulations! You have reached your savings goal in %d months!\n", numMonths);
        printf("You have $%.2f remaining after reaching your goal. Congratulations on your financial success!\n", totalSavings - savingsGoal);
    } else {
        printf("Unfortunately, it looks like it will take you longer to reach your savings goal.\n");
        printf("Based on your current income and expenses, you would need to save $%.2f per month to reach your goal in %d months.\n", (savingsGoal - totalSavings) / numMonths, numMonths);
    }
    
    return 0;
}
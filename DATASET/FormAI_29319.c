//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: high level of detail
#include <stdio.h>

int main() {

    // declare variables
    float monthlyIncome, monthlyExpenses, savingsGoal, savingsPerMonth, monthsNeeded;
    
    // get user input
    printf("Enter your monthly income: ");
    scanf("%f", &monthlyIncome);
    
    printf("Enter your monthly expenses: ");
    scanf("%f", &monthlyExpenses);
    
    printf("Enter your savings goal: ");
    scanf("%f", &savingsGoal);
    
    // calculate savings needed per month and months needed to reach goal
    savingsPerMonth = monthlyIncome - monthlyExpenses;
    monthsNeeded = savingsGoal / savingsPerMonth;
    
    // output results to user
    printf("You need to save $%.2f every month to reach your savings goal.\n", savingsPerMonth);
    
    if (monthsNeeded < 12) {
        printf("You need to save for %.0f months to reach your goal.\n", monthsNeeded);
    } else {
        int yearsNeeded = monthsNeeded / 12;
        int remainingMonths = (int) monthsNeeded % 12;
        printf("You need to save for %d years and %d months to reach your goal.\n", yearsNeeded, remainingMonths);
    }
    
    return 0;
}
//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: authentic
#include <stdio.h>

float calculateSavings(float, float);       // function prototype

int main() {
    float monthlyIncome;                    // user's monthly income
    float monthlyExpenses;                  // user's monthly expenses
    float monthlySavings;                   // user's monthly savings

    // get user's monthly income and monthly expenses
    printf("What is your monthly income?\n");
    scanf("%f", &monthlyIncome);
    printf("What are your monthly expenses?\n");
    scanf("%f", &monthlyExpenses);

    monthlySavings = calculateSavings(monthlyIncome, monthlyExpenses); // calculate monthly savings

    // Display the result
    printf("Your monthly savings is $%.2f\n", monthlySavings);

    return 0;
}

/*
 * calculateSavings function calculation
 * This function calculates and returns the monthly savings of the user.
 */
float calculateSavings(float monthlyIncome, float monthlyExpenses) {
    float monthlySavings = monthlyIncome - monthlyExpenses;
    return monthlySavings;
}
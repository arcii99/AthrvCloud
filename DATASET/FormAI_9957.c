//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: all-encompassing
#include <stdio.h>

// function to calculate expenses for the month
float calculateExpenses(float rent, float food, float utilities, float transportation, float entertainment) {
    float totalExpenses = rent + food + utilities + transportation + entertainment;
    return totalExpenses;
}

int main() {
    // get the user inputs for expenses
    float rent, food, utilities, transportation, entertainment;
    printf("Enter the amount you pay for rent: ");
    scanf("%f", &rent);
    printf("Enter the amount you spend on food: ");
    scanf("%f", &food);
    printf("Enter the amount you pay for utilities: ");
    scanf("%f", &utilities);
    printf("Enter the amount you spend on transportation: ");
    scanf("%f", &transportation);
    printf("Enter the amount you spend on entertainment: ");
    scanf("%f", &entertainment);

    // calculate the total expenses
    float totalExpenses = calculateExpenses(rent, food, utilities, transportation, entertainment);

    printf("\nYour monthly expenses are: $%.2f\n", totalExpenses);

    // calculate the monthly savings
    float income, savings;
    printf("\nEnter your monthly income: ");
    scanf("%f", &income);
    savings = income - totalExpenses;

    printf("\nYour monthly savings is: $%.2f\n", savings);

    // calculate the percentage of income saved
    float percentSaved = (savings / income) * 100;
    printf("\nYou saved %.2f%% of your monthly income\n", percentSaved);

    return 0;
}
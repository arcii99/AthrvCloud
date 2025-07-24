//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: active
#include <stdio.h>

float calculateSavings(float currentSavings, float monthlyIncome, float monthlyExpenses);
float calculateInvestment(float currentInvestment, float monthlySavings, float interestRate);
void printResults(float currentSavings, float currentInvestment);

int main() {
    float currentSavings, currentInvestment, monthlyIncome, monthlyExpenses, interestRate;

    printf("Enter current savings: ");
    scanf("%f", &currentSavings);

    printf("Enter current investment amount: ");
    scanf("%f", &currentInvestment);

    printf("Enter your monthly income: ");
    scanf("%f", &monthlyIncome);

    printf("Enter your monthly expenses: ");
    scanf("%f", &monthlyExpenses);

    printf("Enter the annual interest rate: ");
    scanf("%f", &interestRate);

    float monthlySavings = calculateSavings(currentSavings, monthlyIncome, monthlyExpenses);
    float investmentGrowth = calculateInvestment(currentInvestment, monthlySavings, interestRate);

    printResults(currentSavings + monthlySavings, currentInvestment + investmentGrowth);

    return 0;
}

float calculateSavings(float currentSavings, float monthlyIncome, float monthlyExpenses) {
    return monthlyIncome - monthlyExpenses;
}

float calculateInvestment(float currentInvestment, float monthlySavings, float interestRate) {
    return (currentInvestment * interestRate / 100) / 12 + monthlySavings;
}

void printResults(float currentSavings, float currentInvestment) {
    printf("\nResults:\n");
    printf("Current Savings: $%.2f\n", currentSavings);
    printf("Current Investment: $%.2f\n", currentInvestment);
}
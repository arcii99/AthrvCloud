//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: beginner-friendly
#include <stdio.h>

int main() {
    float initialInvestment, monthlyInvestment;
    int year, numberOfYears;
    float annualInterestRate, futureValue;

    // Get input from user
    printf("Enter your initial investment: $");
    scanf("%f", &initialInvestment);

    printf("Enter your monthly investment: $");
    scanf("%f", &monthlyInvestment);

    printf("Enter the number of years you want to invest: ");
    scanf("%d", &numberOfYears);

    printf("Enter the annual interest rate: ");
    scanf("%f", &annualInterestRate);

    // Print table header
    printf("\nYear \t Initial Investment \t Monthly Investment \t Total Investment \t Future Value\n");

    // Calculate and print data for each year
    for (year = 1; year <= numberOfYears; year++) {
        float totalInvestment = initialInvestment + (monthlyInvestment * 12 * year);
        futureValue = totalInvestment * pow(1 + (annualInterestRate / 12.0), 12 * year);

        printf("%d \t $%.2f \t\t\t $%.2f \t\t\t $%.2f \t\t\t $%.2f\n", year, initialInvestment, monthlyInvestment * 12 * year, totalInvestment, futureValue);
    }

    return 0;
}
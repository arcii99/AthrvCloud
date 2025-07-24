//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

int main() {
    int initialAmount, monthlyDeposit, years;
    float interest;

    printf("Enter your initial amount in your savings account:\n");
    scanf("%d", &initialAmount);

    printf("Enter your monthly deposit:\n");
    scanf("%d", &monthlyDeposit);

    printf("Enter the number of years you plan to save:\n");
    scanf("%d", &years);

    printf("Enter the annual interest rate:\n");
    scanf("%f", &interest);

    float monthlyInterestRate = interest/12;
    float totalSavings = initialAmount;
    int totalMonths = years*12;

    for(int i=1; i<=totalMonths; i++) {
        float monthlyInterest = (totalSavings*monthlyInterestRate)/100;
        totalSavings += monthlyDeposit + monthlyInterest;
        printf("Month %d: Savings: $%.2f\n", i, totalSavings);
    }

    printf("After %d years, you will have a total of $%.2f in your savings account!\n", years, totalSavings);

    return 0;
}
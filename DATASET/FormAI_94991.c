//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: interoperable
#include<stdio.h>
#include<stdlib.h>

//structure to store the user's financial data
struct finance {
    float income;
    float expenses;
    float savings;
};

//function to calculate the user's savings based on income and expenses
float calcSavings(float inc, float exp) {
    float sav = inc - exp;
    return sav;
}

//function to display the user's financial data
void displayData(struct finance f) {
    printf("\nIncome: $%.2f", f.income);
    printf("\nExpenses: $%.2f", f.expenses);
    printf("\nSavings: $%.2f", f.savings);
}

int main() {
    struct finance f;
    printf("Enter your monthly income: ");
    scanf("%f", &f.income);
    printf("Enter your monthly expenses: ");
    scanf("%f", &f.expenses);
    f.savings = calcSavings(f.income, f.expenses);
    displayData(f);
    return 0;
}
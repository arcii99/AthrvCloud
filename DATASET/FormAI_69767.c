//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: thoughtful
#include <stdio.h>

int main() {
    float salary, rent, utilities, groceries, transportation, savings;
    
    printf("Welcome to Personal Finance Planner\n");
    printf("----------------------------------\n");
    
    printf("\nEnter your monthly salary: ");
    scanf("%f", &salary);
    
    printf("\nEnter your monthly rent: ");
    scanf("%f", &rent);
    
    printf("\nEnter your monthly utilities: ");
    scanf("%f", &utilities);
    
    printf("\nEnter your monthly groceries: ");
    scanf("%f", &groceries);
    
    printf("\nEnter your monthly transportation expenses: ");
    scanf("%f", &transportation);
    
    printf("\nEnter your monthly savings goal: ");
    scanf("%f", &savings);
    
    float totalExpenses = rent + utilities + groceries + transportation;
    float moneyLeft = salary - totalExpenses - savings;
    
    printf("\n\nMonthly Financial Report:\n");
    printf("----------------------------\n");
    
    printf("\nTotal expenses: $%.2f", totalExpenses);
    printf("\nMoney left after expenses: $%.2f", moneyLeft);
    
    if (moneyLeft > 0) {
        printf("\n\nCongratulations! You have leftover money! Consider putting it towards investments or increasing your savings.\n");
    } else if (moneyLeft < 0) {
        printf("\n\nUh oh, it looks like you're in the negative. Consider reassessing your expenses or finding ways to increase your income.\n");
    } else {
        printf("\n\nYou've just broken even. Consider looking for ways to cut down on expenses or increasing your income for a more comfortable financial situation.\n");
    }
    
    return 0;
}
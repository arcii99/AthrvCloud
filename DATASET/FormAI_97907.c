//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: happy
#include <stdio.h>

int main() {
    printf("Welcome to your Personal Finance Planner! Let's get started on your financial journey.\n");
    float income, housing, food, transportation, entertainment, savings, total_expenses;
    
    printf("Enter your monthly income: $");
    scanf("%f", &income);
    
    printf("\nHow much do you spend on housing each month?: $");
    scanf("%f", &housing);
    
    printf("\nHow much do you spend on food each month?: $");
    scanf("%f", &food);
    
    printf("\nHow much do you spend on transportation each month?: $");
    scanf("%f", &transportation);
    
    printf("\nHow much do you spend on entertainment each month?: $");
    scanf("%f", &entertainment);
    
    total_expenses = housing + food + transportation + entertainment;
    
    printf("\nBased on your expenses, you spend a total of $%.2f each month.\n", total_expenses);
    
    savings = income - total_expenses;
    
    if (savings > 0) {
        printf("\nGreat job! You have a monthly savings of $%.2f.\n", savings);
    } else if (savings < 0) {
        printf("\nUh-oh! You are spending more than you earn. You need to cut down on your expenses.\n");
    } else {
        printf("\nYou are breaking even each month. Consider saving more to reach your financial goals.\n");
    }
    
    return 0;
}
//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: careful
#include <stdio.h>

int main() {
    float salary, rent, groceries, transportation, savings;
    
    printf("Enter your monthly salary: ");
    scanf("%f", &salary);
    printf("Enter your monthly rent amount: ");
    scanf("%f", &rent);
    printf("Enter your monthly groceries budget: ");
    scanf("%f", &groceries);
    printf("Enter your monthly transportation costs: ");
    scanf("%f", &transportation);
    
    savings = salary - rent - groceries - transportation;
    
    printf("\n***** PERSONAL FINANCE PLANNER *****\n\n");
    printf("Monthly Salary: $%.2f\n", salary);
    printf("Monthly Rent: $%.2f\n", rent);
    printf("Monthly Groceries Budget: $%.2f\n", groceries);
    printf("Monthly Transportation Costs: $%.2f\n", transportation);
    printf("Monthly Savings: $%.2f\n", savings);
    
    if (savings < 0) {
        printf("\nWARNING: You are spending more than you are earning!\n");
    }
    else if (savings == 0) {
        printf("\nCAUTION: You are breaking even. Plan your expenses carefully.\n");
    }
    else {
        printf("\nCongratulations! You are saving more than you are spending.\n");
    }
    
    return 0;
}
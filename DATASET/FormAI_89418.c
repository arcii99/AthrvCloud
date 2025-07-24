//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: ultraprecise
#include <stdio.h>

int main() {
    float monthly_income, rent, utilities, groceries, transportation, entertainment, savings;
    
    printf("Enter your monthly income: ");
    scanf("%f", &monthly_income);
    
    printf("Enter your rent/mortgage cost: ");
    scanf("%f", &rent);
    
    printf("Enter your monthly utilities cost: ");
    scanf("%f", &utilities);
    
    printf("Enter your monthly grocery cost: ");
    scanf("%f", &groceries);
    
    printf("Enter your monthly transportation cost: ");
    scanf("%f", &transportation);
    
    printf("Enter your monthly entertainment cost: ");
    scanf("%f", &entertainment);
    
    savings = monthly_income - rent - utilities - groceries - transportation - entertainment;
    
    printf("\n======= Personal Finance Planner =======\n");
    printf("Monthly Income: %.2f\n", monthly_income);
    printf("Monthly Rent/Mortgage Cost: %.2f\n", rent);
    printf("Monthly Utilities Cost: %.2f\n", utilities);
    printf("Monthly Grocery Cost: %.2f\n", groceries);
    printf("Monthly Transportation Cost: %.2f\n", transportation);
    printf("Monthly Entertainment Cost: %.2f\n", entertainment);
    printf("Monthly Savings: %.2f\n", savings);
    printf("=======================================\n");
    
    return 0;
}
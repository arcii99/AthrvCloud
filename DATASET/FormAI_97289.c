//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: light-weight
#include<stdio.h>

int main(){

    float monthly_income, rent, food, utilities, transportation, savings, remaining_money;

    printf("-------Personal Finance Planner-------\n\n");

    printf("Enter your monthly income: ");
    scanf("%f", &monthly_income);

    printf("Enter your monthly rent expense: ");
    scanf("%f", &rent);

    printf("Enter your monthly food expense: ");
    scanf("%f", &food);

    printf("Enter your monthly utilities expense: ");
    scanf("%f", &utilities);

    printf("Enter your monthly transportation expense: ");
    scanf("%f", &transportation);

    printf("Enter your desired monthly savings amount: ");
    scanf("%f", &savings);
    
    remaining_money = monthly_income - rent - food - utilities - transportation - savings;

    printf("\n-----------------RESULTS----------------\n\n");

    printf("Your monthly income: $%.2f\n", monthly_income);
    printf("Your monthly rent expense: $%.2f\n", rent);
    printf("Your monthly food expense: $%.2f\n", food);
    printf("Your monthly utilities expense: $%.2f\n", utilities);
    printf("Your monthly transportation expense: $%.2f\n", transportation);
    printf("Your desired monthly savings amount: $%.2f\n", savings);
    printf("Your remaining monthly money after all expenses and savings have been considered: $%.2f\n", remaining_money);

    return 0;
}
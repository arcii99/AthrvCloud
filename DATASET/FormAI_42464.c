//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: real-life
#include <stdio.h>

// Function to calculate total income
float calculate_income(float salary, float rental_income, float other_income){
    return salary + rental_income + other_income;
}

// Function to calculate total expenses
float calculate_expenses(float rent, float utilities, float groceries, float transportation, float entertainment, float other_expenses){
    return rent + utilities + groceries + transportation + entertainment + other_expenses;
}

// Function to calculate total savings
float calculate_savings(float income, float expenses){
    return income - expenses;
}

int main(){
    
    float salary, rental_income, other_income;
    printf("Enter your monthly salary: ");
    scanf("%f", &salary);

    printf("Enter your monthly rental income: ");
    scanf("%f", &rental_income);

    printf("Enter your other monthly income: ");
    scanf("%f", &other_income);
    
    printf("\n");
    
    float rent, utilities, groceries, transportation, entertainment, other_expenses;
    printf("Enter your monthly rent: ");
    scanf("%f", &rent);

    printf("Enter your monthly utilities: ");
    scanf("%f", &utilities);

    printf("Enter your monthly groceries: ");
    scanf("%f", &groceries);

    printf("Enter your monthly transportation: ");
    scanf("%f", &transportation);

    printf("Enter your monthly entertainment: ");
    scanf("%f", &entertainment);

    printf("Enter your other monthly expenses: ");
    scanf("%f", &other_expenses);
    
    printf("\n");
    
    float income = calculate_income(salary, rental_income, other_income);
    printf("Your monthly income is: $%.2f\n", income);

    float expenses = calculate_expenses(rent, utilities, groceries, transportation, entertainment, other_expenses);
    printf("Your monthly expenses are: $%.2f\n", expenses);

    float savings = calculate_savings(income, expenses);
    printf("Your monthly savings are: $%.2f\n", savings);

    return 0;
}
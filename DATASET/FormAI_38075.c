//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: beginner-friendly
#include<stdio.h>

int main(){
    
    // Gathering user input
    float salary, rent, food, utilities, transportation, health, entertainment;
    printf("Welcome to Personal Finance Planner!\n\n");
    printf("Please enter your monthly salary: ");
    scanf("%f", &salary);
    printf("Please enter your monthly rent amount: ");
    scanf("%f", &rent);
    printf("Please enter your monthly food expenses: ");
    scanf("%f", &food);
    printf("Please enter your monthly utilities expenses: ");
    scanf("%f", &utilities);
    printf("Please enter your monthly transportation expenses: ");
    scanf("%f", &transportation);
    printf("Please enter your monthly health expenses: ");
    scanf("%f", &health);
    printf("Please enter your monthly entertainment expenses: ");
    scanf("%f", &entertainment);
    
    // Calculating monthly expenses and savings
    float expenses = rent + food + utilities + transportation + health + entertainment;
    float savings = salary - expenses;
    
    // Displaying the results
    printf("\n\n*******************************\n");
    printf("Your Monthly Expenses:\n\n");
    printf("Rent\t\t\t%.2f\n", rent);
    printf("Food\t\t\t%.2f\n", food);
    printf("Utilities\t\t%.2f\n", utilities);
    printf("Transportation\t\t%.2f\n", transportation);
    printf("Health\t\t\t%.2f\n", health);
    printf("Entertainment\t\t%.2f\n", entertainment);
    printf("*******************************\n");
    printf("Total Expenses\t\t%.2f\n", expenses);
    printf("Total Savings\t\t%.2f\n", savings);
    printf("*******************************\n");
    
    return 0;
}
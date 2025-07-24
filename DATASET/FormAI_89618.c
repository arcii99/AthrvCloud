//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: enthusiastic
#include<stdio.h>

int main(){
    float income, expenses, savings;
    int age, years_to_retire;

    printf("Welcome to the Personal Finance Planner!\n");
    printf("Let's get started...\n\n");

    printf("Enter your age: ");
    scanf("%d", &age);

    printf("Enter your monthly income: $");
    scanf("%f", &income);

    printf("Enter your monthly expenses: $");
    scanf("%f", &expenses);

    savings = income - expenses;

    if (savings < 0){
        printf("Uh oh! Looks like you're spending more than you earn.\n");
        printf("You need to cut down on some expenses or find ways to increase your income.\n\n");
    }else{
        printf("Great job! Looks like your monthly savings are $%.2f\n\n", savings);
    }

    years_to_retire = 65 - age;

    printf("Assuming you want to retire at 65, you have %d years left to save.\n", years_to_retire);
    printf("How much money do you want to have saved up for retirement?\n");

    float retirement_savings_goal;

    scanf("%f", &retirement_savings_goal);

    float monthly_savings_goal = retirement_savings_goal / (years_to_retire*12);
    float surplus = savings - monthly_savings_goal;

    if (surplus < 0){
        printf("Uh oh! Looks like you need to save more to reach your retirement savings goal.\n");
    }else{
        printf("Great job! Looks like you're on track to reach your retirement savings goal!\n");
    }

    printf("\nThank you for using the Personal Finance Planner. Happy savings!\n");

    return 0;
}
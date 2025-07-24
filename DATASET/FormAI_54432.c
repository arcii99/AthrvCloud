//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: happy
#include <stdio.h>

int main() {
    printf("Welcome to the Happy Personal Finance Planner!\n");
    
    float income, expenses, savings;
    
    printf("What is your monthly income?\n");
    scanf("%f", &income);
    
    printf("What are your monthly expenses?\n");
    scanf("%f", &expenses);
    
    savings = income - expenses;
    
    if (savings < 0) {
        printf("Oh no! You're spending more than you're earning. Let's try again.\n");
        main(); // restart program
    } else {
        printf("Great job! You're spending less than you're earning and saving $%.2f each month.\n", savings);
    }
    
    float savings_goal, months_to_goal;
    
    printf("What is your savings goal?\n");
    scanf("%f", &savings_goal);
    
    months_to_goal = savings_goal / savings;
    
    if (months_to_goal <= 0) {
        printf("Congratulations! You've already reached your savings goal.\n");
    } else {
        printf("At your current savings rate, it will take you %.1f months to reach your savings goal.\n", months_to_goal);
    }
    
    return 0;
}
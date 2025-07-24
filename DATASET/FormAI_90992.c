//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: Linus Torvalds
#include<stdio.h>
#include<stdlib.h>

int main() {
    int income, expenses, savings;
    printf("Welcome to Personal Finance Planner!\n");
    printf("Enter your monthly income: ");
    scanf("%d", &income);
    printf("Enter your monthly expenses: ");
    scanf("%d", &expenses);
    savings = income - expenses;
    if(savings < 0) {
        printf("You're spending more than you're earning. Better start budgeting!\n");
    }
    else {
        printf("Your savings this month: %d\n", savings);
        printf("Breakdown of your expenses:\n");
        printf("Housing: $%d\n", expenses*0.3);
        printf("Food: $%d\n", expenses*0.2);
        printf("Transportation: $%d\n", expenses*0.1);
        printf("Entertainment: $%d\n", expenses*0.15);
        printf("Other: $%d\n", expenses*0.25);
    }
    return 0;
}
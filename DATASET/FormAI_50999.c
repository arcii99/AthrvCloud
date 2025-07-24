//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

int main() {
    int income, expenses, savings, investments;
    char mood[30];
    
    printf("Welcome to the Surrealist Personal Finance Planner!\n");
    printf("Please enter your monthly income: ");
    scanf("%d", &income);
    printf("Please enter your monthly expenses: ");
    scanf("%d", &expenses);
    
    savings = income - expenses;
    printf("Your monthly savings are: %d\n", savings);
    
    printf("On a scale of 1-10, how would you rate your current mood? ");
    scanf("%s", mood);
    
    if (mood[0] == 's') {
        printf("Wow, you're feeling super surreal today! Let's take a look at your investments...\n");
        investments = rand() % savings + 1;
        printf("Your recommended monthly investment amount is: %d\n", investments);
    } else if (mood[0] == 'm') {
        printf("You're feeling pretty mellow today. Let's stick to saving for now...\n");
        printf("Your recommended monthly savings goal is: %d\n", savings);
    } else {
        printf("Uh oh, sounds like you're feeling a bit down. Remember to take care of yourself first and foremost.\n");
    }
    
    printf("Thanks for using the Surrealist Personal Finance Planner. Keep on dreaming!\n");
    
    return 0;
}
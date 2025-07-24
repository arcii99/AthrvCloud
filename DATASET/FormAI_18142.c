//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: multiplayer
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    struct User {
        char name[30];
        float monthly_income;
        float monthly_expenses;
        float monthly_savings;
    };

    int number_of_players;

    printf("Welcome to Personal Finance Planner!\n\n");

    do {
        printf("How many players will be using the program? ");
        scanf("%d", &number_of_players);
    } while (number_of_players < 1 || number_of_players > 4);

    struct User users[number_of_players];

    for (int i = 0; i < number_of_players; i++) {
        printf("\n*** Enter details for Player %d ***\n", i + 1);
        printf("Enter name: ");
        fgets(users[i].name, 30, stdin);
        printf("Enter monthly income: ");
        scanf("%f", &users[i].monthly_income);
        printf("Enter monthly expenses: ");
        scanf("%f", &users[i].monthly_expenses);
        users[i].monthly_savings = users[i].monthly_income - users[i].monthly_expenses;
    }

    printf("\n\n*** Personal Finance Planner Report ***\n");
    for (int i = 0; i < number_of_players; i++) {
        printf("\nPlayer %d\n", i + 1);
        printf("Name: %s", users[i].name);
        printf("Monthly income: $%.2f\n", users[i].monthly_income);
        printf("Monthly expenses: $%.2f\n", users[i].monthly_expenses);
        printf("Monthly savings: $%.2f\n", users[i].monthly_savings);
    }

    return 0;
}
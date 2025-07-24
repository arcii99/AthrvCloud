//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int income = 0;
    int expenses = 0;
    int savings = 0;
    int debt = 0;

    printf("Welcome to the Personal Finance Planner!\n");
    printf("Please enter your monthly income: ");
    scanf("%d", &income);

    printf("Please enter your monthly expenses: ");
    scanf("%d", &expenses);

    printf("Please enter your current debt: ");
    scanf("%d", &debt);

    savings = rand() % (income - expenses);
    debt += rand() % (expenses - savings);

    printf("\nCongratulations! Your monthly savings are $%d!\n", savings);
    printf("Unfortunately, your debt has increased and is now $%d...\n", debt);
    printf("But don't worry! Life is a surreal journey and we're all just lucky to be along for the ride...\n");

    return 0;
}
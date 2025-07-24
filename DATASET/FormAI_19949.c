//FormAI DATASET v1.0 Category: Expense Tracker ; Style: enthusiastic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* This program is an Expense Tracker.
   It helps users keep track of their daily expenses
   and shows them the total expense at the end of the week.*/

int main()
{
    int day, i;
    float expense, weekly_total = 0;

    printf("----------------------------------------------\n");
    printf("\tWelcome to Your Expense Tracker\n");
    printf("----------------------------------------------\n\n");

    for(day = 1; day <= 7; day++)
    {
        printf("Enter your expenses for Day %d : ", day);
        scanf("%f", &expense);
        weekly_total += expense;
    }

    printf("\nTotal Expenses for the week: $%.2f\n", weekly_total);

    return 0;
}
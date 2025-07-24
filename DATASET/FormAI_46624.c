//FormAI DATASET v1.0 Category: Expense Tracker ; Style: funny
/* This is a silly expense tracker program. It's called "Where Did My Money Go?" */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    printf("Welcome to Where Did My Money Go?\n");
    printf("The most useless expense tracker out there!\n");

    int numExpenses = 0;
    float totalSpent = 0.0f;
    char expenseName[50];

    printf("\n");

    while (1){

        printf("Enter the name of your expense (or type 'exit' to quit): ");
        scanf("%s", expenseName);

        if (strcmp(expenseName, "exit") == 0){
            break;
        }

        float expenseAmount;
        printf("Enter the amount of money you spent: $");
        scanf("%f", &expenseAmount);

        printf("Ah, %s. A classic.\n", expenseName);
        printf("Another $%.2f out the window. Congrats.\n", expenseAmount);

        numExpenses++;
        totalSpent += expenseAmount;

        printf("\n");
    }

    printf("Thanks for tracking your expenses with Where Did My Money Go?!\n");
    printf("In total, you spent $%.2f on %d useless purchases.\n", totalSpent, numExpenses);

    return 0;
}
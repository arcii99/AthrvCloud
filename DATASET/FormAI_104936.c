//FormAI DATASET v1.0 Category: Expense Tracker ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Expense {
    char category[20];
    float amount;
    char date[20];
};

int main() {
    int choice, i = 0, j = 0, k = 0;
    float totalExpense = 0.0;
    struct Expense* expenses = (struct Expense*)malloc(sizeof(struct Expense));
    printf("Enter your expense tracker:\n");
    while (1) {
        printf("\n1. Add an Expense \n2. Display All Expenses \n3. Show Total Expenses \n4. Quit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                expenses = (struct Expense*)realloc(expenses, (i+1)*sizeof(struct Expense));
                printf("Enter category of expense: \n");
                scanf("%s", expenses[i].category);
                printf("Enter amount spent: \n");
                scanf("%f", &expenses[i].amount);
                totalExpense += expenses[i].amount;
                printf("Enter date of expense: \n");
                scanf("%s", expenses[i].date);
                i++;
                break;
            case 2:
                printf("%-15s %-10s %s\n", "CATEGORY", "AMOUNT", "DATE");
                for (j = 0; j < i; j++) {
                    printf("%-15s %-10.2f %s\n", expenses[j].category, expenses[j].amount, expenses[j].date);
                }
                break;
            case 3:
                printf("Total expenses made: %-.2f\n", totalExpense);
                break;
            case 4:
                printf("Thanks for using the Expense Tracker.\nGoodbye!\n");
                free(expenses);
                return 0;
            default:
                printf("Invalid input. Please try again.\n");
        }   
    }
    return 0;
}
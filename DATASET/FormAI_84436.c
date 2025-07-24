//FormAI DATASET v1.0 Category: Expense Tracker ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 1000
#define MAX_DESCRIPTION_LENGTH 50

int main() {
    int expensesCount = 0;
    int maxExpenses = MAX_EXPENSES;
    char *description[MAX_EXPENSES];
    double amount[MAX_EXPENSES];
    int year[MAX_EXPENSES], month[MAX_EXPENSES], day[MAX_EXPENSES];
    char line[2048];

    printf("Welcome to My Expense Tracker!\n");
    printf("Enter your expenses (or 'quit' to exit).\n");

    while(1) {

        printf("\n");

        // Check if we reached the maximum number of expenses
        if(expensesCount == maxExpenses) {
            printf("Maximum number of expenses reached.\n");
            break;
        }

        // Read input from user
        printf("Description: ");
        fgets(line, sizeof(line), stdin);

        // Remove newline character
        if(line[strlen(line) - 1] == '\n') {
            line[strlen(line) - 1] = '\0';
        }

        // Check if user wants to quit
        if(strcmp(line, "quit") == 0) {
            break;
        }

        // Validate description length
        if(strlen(line) > MAX_DESCRIPTION_LENGTH) {
            printf("Description is too long (maximum length is %d).\n", MAX_DESCRIPTION_LENGTH);
            continue;
        }

        // Save description
        description[expensesCount] = malloc(strlen(line) + 1);
        strcpy(description[expensesCount], line);

        // Read amount
        printf("Amount: ");
        fgets(line, sizeof(line), stdin);
        if(sscanf(line, "%lf", &amount[expensesCount]) != 1) {
            printf("Invalid amount.\n");
            free(description[expensesCount]);
            continue;
        }

        printf("Date (YYYY-MM-DD): ");
        if(scanf("%d-%d-%d", &year[expensesCount], &month[expensesCount], &day[expensesCount]) != 3) {
            printf("Invalid date format.\n");
            free(description[expensesCount]);
            continue;
        }

        expensesCount++;
    }

    printf("\n");

    // Print expenses
    printf("%-20s %-20s %-20s %-20s\n", "Description", "Amount", "Date", "Time");
    for(int i = 0; i < expensesCount; i++) {
        printf("%-20s %-20.2lf %-20d-%02d-%02d %-20s\n", description[i], amount[i], year[i], month[i], day[i], "18:00:00");
    }

    // Free memory
    for(int i = 0; i < expensesCount; i++) {
        free(description[i]);
    }

    return 0;
}
//FormAI DATASET v1.0 Category: Expense Tracker ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_EXPENSES 1000

struct Expense {
    char category[20];
    float amount;
    char date[11];
    char note[100];
};

int main() {
    int num_expenses = 0;
    struct Expense expenses[MAX_EXPENSES];
    char input[100];

    printf("Welcome to the Expense Tracker!\n");

    while (1) {
        printf("\nPlease select an option:\n"
               "1. Add an expense\n"
               "2. View all expenses\n"
               "3. View expenses by category\n"
               "4. View expenses by date range\n"
               "5. Quit\n");

        fgets(input, 100, stdin);

        if (strcmp(input, "1\n") == 0) {
            if (num_expenses < MAX_EXPENSES) {
                printf("\nEnter category (max 20 characters): ");
                fgets(expenses[num_expenses].category, 20, stdin);
                expenses[num_expenses].category[strcspn(expenses[num_expenses].category, "\n")] = 0;

                printf("Enter amount: ");
                fgets(input, 100, stdin);
                expenses[num_expenses].amount = atof(input);

                printf("Enter date (MM/DD/YYYY): ");
                fgets(expenses[num_expenses].date, 11, stdin);
                expenses[num_expenses].date[strcspn(expenses[num_expenses].date, "\n")] = 0;

                printf("Enter note (max 100 characters): ");
                fgets(expenses[num_expenses].note, 100, stdin);
                expenses[num_expenses].note[strcspn(expenses[num_expenses].note, "\n")] = 0;

                num_expenses++;
                printf("\nExpense added!\n");
            } else {
                printf("\nMaximum number of expenses reached!\n");
            }
        } else if (strcmp(input, "2\n") == 0) {
            if (num_expenses > 0) {
                printf("\nAll Expenses:\n");
                for (int i = 0; i < num_expenses; i++) {
                    printf("%d. %s - $%.2f - %s - %s\n", i+1, expenses[i].category, expenses[i].amount,
                           expenses[i].date, expenses[i].note);
                }
            } else {
                printf("\nNo expenses added yet!\n");
            }
        } else if (strcmp(input, "3\n") == 0) {
            printf("\nEnter category to view: ");
            fgets(input, 100, stdin);
            input[strcspn(input, "\n")] = 0;

            int found_expenses = 0;
            printf("\nExpenses in category \"%s\":\n", input);
            for (int i = 0; i < num_expenses; i++) {
                if (strcmp(expenses[i].category, input) == 0) {
                    printf("%d. $%.2f - %s - %s\n", found_expenses+1, expenses[i].amount,
                           expenses[i].date, expenses[i].note);
                    found_expenses++;
                }
            }
            if (found_expenses == 0) {
                printf("No expenses found in category \"%s\"\n", input);
            }
        } else if (strcmp(input, "4\n") == 0) {
            char start_date[11], end_date[11];
            printf("\nEnter start date (MM/DD/YYYY): ");
            fgets(start_date, 11, stdin);
            start_date[strcspn(start_date, "\n")] = 0;
            printf("Enter end date (MM/DD/YYYY): ");
            fgets(end_date, 11, stdin);
            end_date[strcspn(end_date, "\n")] = 0;

            int found_expenses = 0;
            printf("\nExpenses from %s to %s:\n", start_date, end_date);
            for (int i = 0; i < num_expenses; i++) {
                if (strcmp(expenses[i].date, start_date) >= 0 && strcmp(expenses[i].date, end_date) <= 0) {
                    printf("%d. %s - $%.2f - %s\n", found_expenses+1, expenses[i].category,
                           expenses[i].amount, expenses[i].note);
                    found_expenses++;
                }
            }
            if (found_expenses == 0) {
                printf("No expenses found in date range %s to %s\n", start_date, end_date);
            }
        } else if (strcmp(input, "5\n") == 0) {
            printf("\nQuitting...\n");
            break;
        } else {
          printf("\nInvalid input! Please enter a number 1-5.\n");
        }
    }

    printf("\nThank you for using the Expense Tracker!\n");

    return 0;
}
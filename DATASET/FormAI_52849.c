//FormAI DATASET v1.0 Category: Expense Tracker ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Expenses {
    char date[11];
    char category[50];
    double amount;
};

int main() {
    struct Expenses expense[100];
    int option, count = 0;

    while(1) {
        // Menu for user to select an action
        printf("\nExpense Tracker Menu\n");
        printf("1. Add an expense\n");
        printf("2. View all expenses\n");
        printf("3. View expenses by category\n");
        printf("4. Quit\n");
        printf("Enter an option: ");
        scanf("%d", &option);

        switch(option) {
            case 1: // Add an expense
                printf("\nEnter the date (YYYY-MM-DD): ");
                scanf("%s", expense[count].date);
                printf("Enter the category: ");
                scanf("%s", expense[count].category);
                printf("Enter the amount: ");
                scanf("%lf", &expense[count].amount);
                count++;
                break;

            case 2: // View all expenses
                printf("\nAll Expenses:\n\n");
                for(int i = 0; i < count; i++) {
                    printf("Date: %s\n", expense[i].date);
                    printf("Category: %s\n", expense[i].category);
                    printf("Amount: $%.2lf\n\n", expense[i].amount);
                }
                break;

            case 3: // View expenses by category
                char searchCategory[50];
                double total = 0.0;

                printf("\nEnter the category to search for: ");
                scanf("%s", searchCategory);

                for(int i = 0; i < count; i++) {
                    if(strcmp(expense[i].category, searchCategory) == 0) {
                        printf("Date: %s\n", expense[i].date);
                        printf("Category: %s\n", expense[i].category);
                        printf("Amount: $%.2lf\n\n", expense[i].amount);
                        total += expense[i].amount;
                    }
                }
                printf("Total amount spent on %s: $%.2lf\n\n", searchCategory, total);
                break;

            case 4: // Exit program
                printf("\nExiting the program...\n\n");
                exit(0);
                break;

            default: // Invalid option selected
                printf("\nInvalid option selected. Please try again.\n");
                break;
        }
    }

    return 0;
}
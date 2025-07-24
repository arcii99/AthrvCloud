//FormAI DATASET v1.0 Category: Expense Tracker ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// The structure to hold the expense information
typedef struct Expense {
    char category[20];
    double amount;
    char date[20];
} Expense;

// Function to get expense details from user
void getExpenseDetails(Expense *expense) {
    printf("Enter the category of expense: ");
    scanf("%s", expense->category);
    printf("Enter the amount spent: ");
    scanf("%lf", &expense->amount);
    printf("Enter the date of expense (dd/mm/yyyy): ");
    scanf("%s", expense->date);
}

int main() {

    FILE *file = fopen("expenses.txt", "a+");

    if(file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    Expense expense;

    // Menu for user to choose what they want to do
    int choice;
    do {
        printf("\nExpense Tracker\n");
        printf("1. Add an expense\n");
        printf("2. View all expenses\n");
        printf("3. Search expenses by category\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                getExpenseDetails(&expense);
                fwrite(&expense, sizeof(Expense), 1, file);
                printf("\nExpense added successfully!\n");
                break;
            case 2:
                rewind(file);
                printf("\n%-20s %-10s %-20s\n", "Category", "Amount", "Date");
                printf("---------------------------------------------------\n");
                while(fread(&expense, sizeof(Expense), 1, file)) {
                    printf("%-20s %-10.2lf %-20s\n", expense.category, expense.amount, expense.date);
                }
                break;
            case 3:
                char search[20];
                printf("\nEnter the category to search for: ");
                scanf("%s", search);
                rewind(file);
                printf("\n%-20s %-10s %-20s\n", "Category", "Amount", "Date");
                printf("---------------------------------------------------\n");
                while(fread(&expense, sizeof(Expense), 1, file)) {
                    if(strcmp(search, expense.category) == 0) {
                        printf("%-20s %-10.2lf %-20s\n", expense.category, expense.amount, expense.date);
                    }
                }
                break;
            case 4:
                printf("\nExiting Expense Tracker. Goodbye!\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }

    } while(choice != 4);

    fclose(file);

    return 0;
}
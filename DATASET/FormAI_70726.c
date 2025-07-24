//FormAI DATASET v1.0 Category: Expense Tracker ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Defining the expense structure
struct Expense {
    char name[50];
    float amount;
    char category[50];
    char date[50];
};

int main() {
    int choice, num_of_expenses = 0, i;
    float total_expenses = 0;
    char category_input[50], date_input[50];
    struct Expense expenses[100]; // Maximum of 100 expenses can be tracked

    // Welcome message
    printf("Welcome to the Expense Tracker!\n");

    // Displaying menu options
    while(1) {
        printf("\nWhat would you like to do? Please enter your choice:\n");
        printf("1. Add an expense\n");
        printf("2. View all expenses\n");
        printf("3. View expenses by category\n");
        printf("4. View expenses by date\n");
        printf("5. Exit\n");

        scanf("%d", &choice);

        switch(choice) {
            case 1:
                // Adding a new expense
                struct Expense new_expense;

                printf("\nEnter the name of expense: ");
                scanf("%s", new_expense.name);

                printf("Enter the amount: ");
                scanf("%f", &new_expense.amount);

                printf("Enter the category: ");
                scanf("%s", new_expense.category);

                printf("Enter the date (dd/mm/yyyy): ");
                scanf("%s", new_expense.date);

                total_expenses += new_expense.amount;
                expenses[num_of_expenses] = new_expense;
                num_of_expenses++;

                printf("\nExpense added successfully.\n");
                break;

            case 2:
                // Viewing all expenses
                if(num_of_expenses == 0) {
                    printf("\nNo expenses added yet.\n");
                    break;
                }

                printf("\nAll expenses:\n");
                for(i = 0; i < num_of_expenses; i++) {
                    printf("%d. Name: %s | Amount: $%.02f | Category: %s | Date: %s\n",
                            i+1, expenses[i].name, expenses[i].amount, expenses[i].category, expenses[i].date);
                }
                printf("Total expenses: $%.02f\n", total_expenses);
                break;

            case 3:
                // Viewing expenses by category
                if(num_of_expenses == 0) {
                    printf("\nNo expenses added yet.\n");
                    break;
                }

                printf("\nEnter the category: ");
                scanf("%s", category_input);

                printf("\nExpenses in the category %s:\n", category_input);

                float total_category_expenses = 0;
                int cat_expenses = 0;

                for(i = 0; i < num_of_expenses; i++) {
                    if(strcmp(expenses[i].category, category_input) == 0) {
                        printf("%d. Name: %s | Amount: $%.02f | Date: %s\n",
                                cat_expenses+1, expenses[i].name, expenses[i].amount, expenses[i].date);
                        total_category_expenses += expenses[i].amount;
                        cat_expenses++;
                    }
                }

                if(cat_expenses == 0) {
                    printf("No expenses found in the category %s.", category_input);
                } else {
                    printf("Total expenses in the category %s: $%.02f", category_input, total_category_expenses);
                }
                break;

            case 4:
                // Viewing expenses by date
                if(num_of_expenses == 0) {
                    printf("\nNo expenses added yet.\n");
                    break;
                }

                printf("\nEnter the date (dd/mm/yyyy): ");
                scanf("%s", date_input);

                printf("\nExpenses on %s:\n", date_input);

                float total_date_expenses = 0;
                int date_expenses = 0;

                for(i = 0; i < num_of_expenses; i++) {
                    if(strcmp(expenses[i].date, date_input) == 0) {
                        printf("%d. Name: %s | Amount: $%.02f | Category: %s\n",
                                date_expenses+1, expenses[i].name, expenses[i].amount, expenses[i].category);
                        total_date_expenses += expenses[i].amount;
                        date_expenses++;
                    }
                }

                if(date_expenses == 0) {
                    printf("No expenses found on %s.", date_input);
                } else {
                    printf("Total expenses on %s: $%.02f", date_input, total_date_expenses);
                }
                break;

            case 5:
                // Exiting the program
                printf("\nThank you for using the Expense Tracker. Goodbye!\n");
                exit(0);

            default:
                // Invalid choice
                printf("\nInvalid choice. Please enter a valid choice.\n");
        }
    }

    return 0;
}
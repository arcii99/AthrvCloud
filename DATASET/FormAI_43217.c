//FormAI DATASET v1.0 Category: Expense Tracker ; Style: complete
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Expense {
    char date[30];
    char type[30];
    char description[100];
    float amount;
};

typedef struct Expense expense;

int main() {
    expense expenses[100]; // assumes maximum of 100 expenses
    int numExpenses = 0;
    float totalExpenses = 0;

    // print menu
    int choice;
    do {
        printf("Expense Tracker Menu\n");
        printf("1. Add Expense\n");
        printf("2. View All Expenses\n");
        printf("3. View Expenses By Type\n");
        printf("4. View Total Expenses\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: // add expense
                printf("Enter the date (mm/dd/yyyy): ");
                scanf("%s", expenses[numExpenses].date);
                printf("Enter the expense type: ");
                scanf("%s", expenses[numExpenses].type);
                printf("Enter the expense description: ");
                scanf("%s", expenses[numExpenses].description);
                printf("Enter the expense amount: ");
                scanf("%f", &expenses[numExpenses].amount);
                totalExpenses += expenses[numExpenses].amount;
                numExpenses++;
                break;
            case 2: // view all expenses
                printf("\nAll Expenses:\n");
                for(int i = 0; i < numExpenses; i++) {
                    printf("Expense %d:\n", i+1);
                    printf(" Date: %s\n", expenses[i].date);
                    printf(" Type: %s\n", expenses[i].type);
                    printf(" Description: %s\n", expenses[i].description);
                    printf(" Amount: $%.2f\n", expenses[i].amount);
                }
                printf("\n");
                break;
            case 3: // view expenses by type
                char searchType[30];
                printf("Enter the expense type to search for: ");
                scanf("%s", searchType);
                printf("\nExpenses for Type '%s':\n", searchType);
                for(int i = 0; i < numExpenses; i++) {
                    if(strcmp(expenses[i].type, searchType) == 0) {
                        printf("Expense %d:\n", i+1);
                        printf(" Date: %s\n", expenses[i].date);
                        printf(" Description: %s\n", expenses[i].description);
                        printf(" Amount: $%.2f\n", expenses[i].amount);
                    }
                }
                printf("\n");
                break;
            case 4: // view total expenses
                printf("Total Expenses: $%.2f\n\n", totalExpenses);
                break;
            case 5: // exit
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n\n");
        }
    } while(choice != 5);

    return 0;
}
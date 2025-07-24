//FormAI DATASET v1.0 Category: Expense Tracker ; Style: Cyberpunk
#include <stdio.h>
#include <string.h>

struct Expense {
    char name[50];
    float amount;
    char category[20];
};

int main() {
    printf("Welcome to the Cyber Expense Tracker!\n");

    int option;
    int expenses_size = 0;
    struct Expense expenses[100];

    do {
        printf("\nSelect an option:\n");
        printf("1. Add an expense\n");
        printf("2. View all expenses\n");
        printf("3. View expenses by category\n");
        printf("4. Exit\n");

        scanf("%d", &option);

        switch(option) {
            case 1:
                printf("\nEnter expense name: ");
                scanf("%s", expenses[expenses_size].name);

                printf("Enter expense amount: ");
                scanf("%f", &expenses[expenses_size].amount);

                printf("Enter expense category: ");
                scanf("%s", expenses[expenses_size].category);

                expenses_size++;

                printf("\nExpense added successfully!\n");
                break;
            case 2:
                if (expenses_size == 0) {
                    printf("\nNo expenses added yet.\n");
                } else {
                    printf("\nAll expenses:\n");
                    for (int i = 0; i < expenses_size; i++) {
                        printf("Name: %s\tAmount: %f\tCategory: %s\n", expenses[i].name, expenses[i].amount, expenses[i].category);
                    }
                }
                break;
            case 3:
                char category[20];
                printf("\nEnter category to view expenses: ");
                scanf("%s", category);

                printf("\nExpenses under category %s:\n", category);
                for (int i = 0; i < expenses_size; i++) {
                    if (strcmp(expenses[i].category, category) == 0) {
                        printf("Name: %s\tAmount: %f\n", expenses[i].name, expenses[i].amount);
                    }
                }
                break;
            case 4:
                printf("\nThank you for using the Cyber Expense Tracker!\n");
                break;
            default:
                printf("\nInvalid option selected. Please try again.\n");
        }
    } while(option != 4);

    return 0;
}
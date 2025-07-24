//FormAI DATASET v1.0 Category: Expense Tracker ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

// Struct to hold transactions
struct Transaction {
    char* description;
    double amount;
    struct Transaction* next;
};

// Helper function to recursively print transactions
void printTransactions(struct Transaction* curr) {
    if (curr == NULL) {
        return;
    }

    printf("Description: %s\n", curr->description);
    printf("Amount: $%.2f\n", curr->amount);
    printf("--------------------\n");

    printTransactions(curr->next);
}

// Recursively free all transactions and their descriptions
void freeTransactions(struct Transaction* curr) {
    if (curr == NULL) {
        return;
    }

    freeTransactions(curr->next);
    free(curr->description);
    free(curr);
}

// Recursively calculate the total expenses
double calculateTotal(struct Transaction* curr, double total) {
    if (curr == NULL) {
        return total;
    }

    total += curr->amount;
    return calculateTotal(curr->next, total);
}

int main() {
    struct Transaction* head = NULL;
    int choice = 0;

    // Main menu
    while (1) {
        printf("1. Add transaction\n");
        printf("2. Print transactions\n");
        printf("3. Calculate total expenses\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Add transaction
                printf("Enter transaction description: ");
                char* desc = malloc(sizeof(char) * 100);
                scanf(" %[^\n]%*c", desc);

                double amount;
                printf("Enter transaction amount: $");
                scanf("%lf", &amount);

                struct Transaction* newTransaction = malloc(sizeof(struct Transaction));
                newTransaction->description = desc;
                newTransaction->amount = amount;
                newTransaction->next = NULL;

                if (head == NULL) {
                    head = newTransaction;
                } else {
                    struct Transaction* curr = head;
                    while (curr->next != NULL) {
                        curr = curr->next;
                    }
                    curr->next = newTransaction;
                }
                printf("Transaction added successfully!\n");
                break;

            case 2:
                // Print transactions
                printf("Transactions:\n");
                printTransactions(head);
                break;

            case 3:
                // Calculate total expenses
                double total = calculateTotal(head, 0);
                printf("Total expenses: $%.2f\n", total);
                break;

            case 4:
                // Exit
                freeTransactions(head);
                exit(0);
                break;

            default:
                printf("Invalid choice, try again.\n");
        }
    }

    return 0;
}
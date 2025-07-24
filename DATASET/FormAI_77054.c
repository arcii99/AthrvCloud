//FormAI DATASET v1.0 Category: Expense Tracker ; Style: protected
#include <stdio.h>
#include <stdlib.h>

/* Structure to hold details of an expense entry */
struct ExpenseEntry {
    char category[20];
    float amount;
    char date[11];
    char description[100];
};

/* Function to add a new expense entry */
void addExpenseEntry(struct ExpenseEntry *entries, int *numOfEntries) {
    printf("\nEnter the details of the new expense entry:\n");
    printf("Category: ");
    scanf("%s", entries[*numOfEntries].category);
    printf("Amount: ");
    scanf("%f", &entries[*numOfEntries].amount);
    printf("Date (dd/mm/yyyy): ");
    scanf("%s", entries[*numOfEntries].date);
    printf("Description: ");
    scanf("%s", entries[*numOfEntries].description);
    (*numOfEntries)++;
    printf("\nExpense entry added successfully!\n");
}

/* Function to display all expense entries */
void displayExpenseEntries(struct ExpenseEntry *entries, int numOfEntries) {
    printf("\nAll expense entries:\n");
    printf("Category\tAmount\t\tDate\t\tDescription\n");
    for(int i=0; i<numOfEntries; i++) {
        printf("%s\t\t%.2f\t\t%s\t\t%s\n", entries[i].category, entries[i].amount, entries[i].date, entries[i].description);
    }
}

/* Function to display expense details for a given category */
void displayExpenseByCategory(struct ExpenseEntry *entries, int numOfEntries, char category[20]) {
    printf("\nExpense details for category '%s':\n", category);
    printf("Amount\t\tDate\t\tDescription\n");
    for(int i=0; i<numOfEntries; i++) {
        if(strcmp(entries[i].category, category) == 0) {
            printf("%.2f\t\t%s\t\t%s\n", entries[i].amount, entries[i].date, entries[i].description);
        }
    }
}

/* Main function */
int main() {
    int choice, numOfEntries=0;
    struct ExpenseEntry entries[100];
    while(1) {
        printf("\nPlease choose an option:\n");
        printf("1. Add a new expense entry\n");
        printf("2. Display all expense entries\n");
        printf("3. Display expense details for a given category\n");
        printf("4. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                addExpenseEntry(entries, &numOfEntries);
                break;
            case 2:
                displayExpenseEntries(entries, numOfEntries);
                break;
            case 3:
                char category[20];
                printf("\nEnter the category for which you want to display expense details: ");
                scanf("%s", category);
                displayExpenseByCategory(entries, numOfEntries, category);
                break;
            case 4:
                printf("\nExiting Expense Tracker.\n");
                exit(0);
            default:
                printf("\nInvalid choice. Please choose again.\n");
        }
    }
    return 0;
}
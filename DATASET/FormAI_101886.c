//FormAI DATASET v1.0 Category: Expense Tracker ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100

// Define a structure for expense
struct Expense {
    int id;
    char item[50];
    int cost;
};

// Declare an array of expenses
struct Expense expenses[MAX_EXPENSES];

// Declare a function to display menu options
void displayMenuOptions() {
    printf("\nExpense Tracker");
    printf("\n1. Add Expense");
    printf("\n2. View Expenses");
    printf("\n3. Exit");
    printf("\nSelect an option: ");
}

// Declare a function to add a new expense
void addExpense() {
    int id, cost, i = 0;
    char item[50];

    printf("\nEnter Expense Details:\n");

    // Get expense id
    printf("\nExpense ID: ");
    scanf("%d", &id);

    // Check if expense id already exists
    while(i < MAX_EXPENSES) {
        if(expenses[i].id == id) {
            printf("\nExpense ID already exists!");
            return;
        }
        i++;
    }

    // Get expense item
    printf("\nItem: ");
    scanf("%s", item);

    // Get expense cost
    printf("\nCost: ");
    scanf("%d", &cost);

    // Create new expense object and add it to the array
    struct Expense newExpense;
    newExpense.id = id;
    strcpy(newExpense.item, item);
    newExpense.cost = cost;

    // Add new expense to the end of the array
    int index = 0;
    while (expenses[index].id != -1) {
        index++;
    }

    expenses[index] = newExpense;

    // Print success message
    printf("\nExpense added successfully!");
}

// Declare a function to view all expenses
void viewExpenses() {
    printf("\nExpense List\n");

    int i = 0, total = 0;
    printf("\nID\tItem\t\tCost");
    printf("\n---------------------------------------------------");
    while(i < MAX_EXPENSES) {
        if(expenses[i].id != -1) {
            printf("\n%d\t%s\t\t%d", expenses[i].id, expenses[i].item, expenses[i].cost);
            total += expenses[i].cost;
        }
        i++;
    }

    printf("\n---------------------------------------------------");
    printf("\nTotal Expenses: %d", total);
}

int main() {
    // Initialize all expenses to -1 (indicating empty)
    int i = 0;
    while(i < MAX_EXPENSES) {
        expenses[i].id = -1;
        i++;
    }

    // Start the loop for the expense tracker
    int choice = 0;
    do {
        displayMenuOptions();
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addExpense();
                break;
            case 2:
                viewExpenses();
                break;
            case 3:
                printf("\nGoodbye!");
                break;
            default:
                printf("\nInvalid choice!");
        }
    } while(choice != 3);

    return 0;
}
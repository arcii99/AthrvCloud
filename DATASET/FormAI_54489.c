//FormAI DATASET v1.0 Category: Expense Tracker ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 1000 // maximum number of expenses that can be stored

struct Expense {
    char date[11]; // date in the format of dd/mm/yyyy
    char category[50]; // category of the expense
    float amount; // amount of the expense
};

struct Expense tracker[MAX_EXPENSES]; // array of expense structures to store the expenses

int numExpenses = 0; // variable to keep track of the number of expenses stored

void addExpense() {
    // function to add a new expense to the tracker

    if (numExpenses == MAX_EXPENSES) {
        // if the tracker is already full, display an error message and return
        printf("Error: Tracker is full. Cannot add any more expenses.\n");
        return;
    }
    
    // ask the user for the details of the new expense
    printf("Enter the date of the expense (dd/mm/yyyy): ");
    scanf("%s", tracker[numExpenses].date);
    printf("Enter the category of the expense: ");
    scanf("%s", tracker[numExpenses].category);
    printf("Enter the amount of the expense: ");
    scanf("%f", &tracker[numExpenses].amount);
    
    numExpenses++; // increment the number of expenses stored
}

void viewExpenses() {
    // function to display all the expenses in the tracker

    if (numExpenses == 0) {
        // if there are no expenses stored, display an error message and return
        printf("Error: No expenses stored in the tracker.\n");
        return;
    }
    
    // display the header row for the expenses table
    printf("Date\t\tCategory\tAmount\n");
    
    // loop through all the expenses and display them
    int i;
    for (i = 0; i < numExpenses; i++) {
        printf("%s\t%s\t%.2f\n", tracker[i].date, tracker[i].category, tracker[i].amount);
    }
}

void viewCategory() {
    // function to display the expenses for a particular category

    if (numExpenses == 0) {
        // if there are no expenses stored, display an error message and return
        printf("Error: No expenses stored in the tracker.\n");
        return;
    }
    
    // ask the user for the category to view expenses for
    char cat[50];
    printf("Enter the category to view expenses for: ");
    scanf("%s", cat);
    
    // display the header row for the expenses table
    printf("Date\t\tAmount\n");
    
    // loop through all the expenses and display the ones that match the category
    int i;
    for (i = 0; i < numExpenses; i++) {
        if (strcmp(tracker[i].category, cat) == 0) {
            printf("%s\t%.2f\n", tracker[i].date, tracker[i].amount);
        }
    }
}

void viewMonthly() {
    // function to display the total expenses for each month

    if (numExpenses == 0) {
        // if there are no expenses stored, display an error message and return
        printf("Error: No expenses stored in the tracker.\n");
        return;
    }
    
    // array to keep track of the total expenses for each month
    float months[12] = {0};
    
    // loop through all the expenses and add up the amounts for each month
    int i;
    for (i = 0; i < numExpenses; i++) {
        char date[11];
        strncpy(date, tracker[i].date, 2);
        date[2] = '\0';
        int month = atoi(date) - 1;
        months[month] += tracker[i].amount;
    }
    
    // display the header row for the monthly expenses table
    printf("Month\t\tTotal Expenses\n");
    
    // loop through the months and display the total expenses for each one
    char monthNames[12][10] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    for (i = 0; i < 12; i++) {
        printf("%s\t\t%.2f\n", monthNames[i], months[i]);
    }
}

int main() {
    // main function to run the expense tracker program
    
    int choice;
    do {
        // display the menu of options
        printf("\nExpense Tracker\n");
        printf("===============\n");
        printf("1. Add expense\n");
        printf("2. View all expenses\n");
        printf("3. View expenses by category\n");
        printf("4. View monthly expenses\n");
        printf("5. Exit\n");
        
        // ask the user for their choice
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addExpense();
                break;
            case 2:
                viewExpenses();
                break;
            case 3:
                viewCategory();
                break;
            case 4:
                viewMonthly();
                break;
            case 5:
                // exit the program
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                // if an invalid choice is entered, display an error message
                printf("Error: Invalid choice. Please enter a number between 1 and 5.\n");
        }
    } while (choice != 5);
    
    return 0;
}
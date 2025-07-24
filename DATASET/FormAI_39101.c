//FormAI DATASET v1.0 Category: Expense Tracker ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 1000
#define MAX_DESC_LEN 50

// This struct represents a single expense entry in the tracker
typedef struct {
    char description[MAX_DESC_LEN];
    double amount;
    int day;
    int month;
    int year;
} Expense;

// This array will store all of the expenses entered by the user
Expense expenses[MAX_EXPENSES];

// This variable keeps track of how many expenses have been entered so far
int numExpenses = 0;

// Our main function
int main() {

    // Greet the user and explain the program's purpose
    printf("Welcome to the Expense Tracker! This program will help you keep track of your spending.\n\n");

    // Loop until the user chooses to quit
    while (1) {

        // Print the menu of options
        printf("Choose an option:\n");
        printf("1. Add expense\n");
        printf("2. View expenses\n");
        printf("3. Quit\n");
        printf("> ");

        // Read the user's choice
        int choice;
        scanf("%d", &choice);

        // Handle the user's choice
        switch (choice) {
            case 1:
                addExpense();
                break;
            case 2:
                viewExpenses();
                break;
            case 3:
                printf("Thank you for using the Expense Tracker! Goodbye.\n");
                return 0;
            default:
                printf("Invalid input.\n");
        }

        // Add some space for readability
        printf("\n");

    }

    return 0;
}

// This function allows the user to add a new expense to the tracker
void addExpense() {

    // Check if we've reached the maximum number of expenses already
    if (numExpenses >= MAX_EXPENSES) {
        printf("Sorry, you have reached the maximum number of expenses!\n");
        return;
    }

    // Ask the user to enter a description for the expense
    printf("Enter a brief description of the expense (up to %d characters):\n", MAX_DESC_LEN);
    printf("> ");

    // Read the user's description
    char description[MAX_DESC_LEN];
    scanf("%s", &description);

    // Ask the user to enter the expense amount
    printf("Enter the amount of the expense:\n");
    printf("> $");

    // Read the user's expense amount
    double amount;
    scanf("%lf", &amount);

    // Ask the user to enter the date of the expense
    printf("Enter the date of the expense (in the format YYYY/MM/DD):\n");
    printf("> ");

    // Read the user's date, splitting it into year, month, and day
    int year, month, day;
    scanf("%d/%d/%d", &year, &month, &day);

    // Create a new Expense struct with the user's data
    Expense newExpense;
    strcpy(newExpense.description, description);
    newExpense.amount = amount;
    newExpense.day = day;
    newExpense.month = month;
    newExpense.year = year;

    // Add the new expense to the array and update the counter
    expenses[numExpenses] = newExpense;
    numExpenses++;

    // Print a success message
    printf("Expense added successfully!\n");
}

// This function displays all of the expenses in the tracker
void viewExpenses() {

    // Check if there are any expenses to show
    if (numExpenses == 0) {
        printf("You haven't entered any expenses yet!\n");
        return;
    }

    // Print a header for the expense table
    printf("%-20s %-10s %-10s %-10s %-10s\n", "Description", "Amount", "Day", "Month", "Year");
    printf("--------------------------------------------------------------\n");

    // Loop through all the expenses and print them
    for (int i = 0; i < numExpenses; i++) {
        printf("%-20s $%-9.2lf %-10d %-10d %-10d\n", expenses[i].description, expenses[i].amount, expenses[i].day, expenses[i].month, expenses[i].year);
    }
}

// This function doesn't actually do anything, but it makes the program more fun :)
void mindBend() {

    // You thought this was just a boring Expense Tracker...
    printf("\n\nYou never know what's around the corner with this program. You could be tracking your expenses one minute and then suddenly find yourself transported to a different dimension the next.\n");
    printf("So go ahead, tracking your expenses. What could possibly go wrong?\n");

    // But little do you know...
    printf("\n\nBeware of the hidden Easter eggs in this program. There are strange things lurking in its code...\n");
}
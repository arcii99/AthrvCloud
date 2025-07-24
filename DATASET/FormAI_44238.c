//FormAI DATASET v1.0 Category: Expense Tracker ; Style: paranoid
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Define sizes and limits
#define MAX_AMOUNT 99999999.99
#define MAX_LINE_LENGTH 80
#define MAX_FILENAME_LENGTH 20

// Structure to hold expenses
typedef struct {
    char date[11];
    char category[16];
    float amount;
} Expense;

// Function to validate user input for amount
float getAmount() {
    char input[10];
    float amount = 0;
    int valid = 0;

    // Continuously read input until valid amount is given
    while (!valid) {
        printf("\nEnter expense amount: $");
        fgets(input, 10, stdin);
        amount = atof(input);

        // Check if amount is within limits
        if (amount > 0 && amount < MAX_AMOUNT) {
            valid = 1;
        } else {
            printf("Invalid amount entered. Please enter an amount between 0 and $99,999,999.99.\n");
        }
    }

    return amount;
}

// Function to validate user input for date
void getDate(char *date) {
    int valid = 0;

    // Continuously read input until a valid date is given
    while (!valid) {
        printf("\nEnter date (mm/dd/yyyy): ");
        fgets(date, 11, stdin);

        // Check if date is in valid format
        if (date[2] == '/' && date[5] == '/' && strlen(date) == 11) {
            valid = 1;
        } else {
            printf("Invalid date entered. Please enter in format mm/dd/yyyy.\n");
        }
    }
}

// Function to validate user input for category
void getCategory(char *category) {
    int valid = 0;
    char input[MAX_LINE_LENGTH];

    // Continuously read input until a valid category is given
    while (!valid) {
        printf("\nEnter expense category: ");
        fgets(input, MAX_LINE_LENGTH, stdin);

        // Remove trailing newline character
        input[strcspn(input, "\n")] = 0;

        // Check if category is within limits
        if (strlen(input) <= 15) {
            strcpy(category, input);
            valid = 1;
        } else {
            printf("Invalid category entered. Please enter a category with length less than or equal to 15.\n");
        }
    }
}

int main() {
    char filename[MAX_FILENAME_LENGTH];
    FILE *file = NULL;

    // Prompt user to enter filename and open file
    printf("Enter filename for expense tracker: ");
    fgets(filename, MAX_FILENAME_LENGTH, stdin);
    filename[strcspn(filename, "\n")] = 0;
    file = fopen(filename, "a+");

    // Check if file was successfully opened
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    // Prompt user for expense details
    char response[4] = "y";
    float total = 0;
    while (strcmp(response, "n\n") != 0 && strcmp(response, "N\n") != 0) {
        Expense expense;

        getDate(expense.date);
        getCategory(expense.category);
        expense.amount = getAmount();

        // Add expense to file and update total
        fprintf(file, "%s %s $%.2f\n", expense.date, expense.category, expense.amount);
        total += expense.amount;

        // Prompt user to enter another expense
        printf("Would you like to enter another expense (y/n)? ");
        fgets(response, 4, stdin);
    }

    // Close file and print total of expenses
    fclose(file);
    printf("Total expenses: $%.2f\n", total);

    return 0;
}
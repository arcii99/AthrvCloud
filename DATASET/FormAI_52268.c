//FormAI DATASET v1.0 Category: Expense Tracker ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define structure to store expenses information
struct Expense {
    char category[20];
    float amount;
    int day;
    int month;
    int year;
    char description[50];
};

// Function declarations
void get_expense(struct Expense *exp);
void save_expense(struct Expense *exp, char *filename);
void read_expense(char *filename);
void print_expense(struct Expense exp);

int main() {

    // Declare variables
    char choice;
    char filename[20];
    FILE *fp;

    // Ensure paranoid mode is on
    printf("Enable paranoid mode (Y/N)? ");
    scanf(" %c", &choice);

    if (tolower(choice) == 'y') {
        // Prompt the user to enter the filename to save expenses
        printf("\nEnter expense filename: ");
        scanf("%s", filename);

        // Check for malicious characters in the filename
        if (strpbrk(filename, "/\\:*?\"<>|") != NULL) {
            printf("Invalid filename! Please try again.\n");
            return 1;
        }

        // Check if file exists and create if it doesn't
        fp = fopen(filename, "a");
        if (fp == NULL) {
            printf("Error: Cannot create file %s\n", filename);
            return 1;
        }
        fclose(fp);
    }

    // Display menu
    printf("\nExpense Tracker Menu\n");
    printf("1. Add expense\n");
    printf("2. Read expenses\n");
    printf("3. Quit\n");

    // Loop until user chooses to quit
    while (1) {
        printf("\nEnter choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                // Declare an expense variable
                struct Expense ex;

                // Prompt the user to enter an expense record
                get_expense(&ex);

                // Save expense record to file
                if (tolower(choice) == 'y') {
                    save_expense(&ex, filename);
                }

                // Print the expense record
                print_expense(ex);
                break;

            case '2':
                // Read expenses from file
                read_expense(filename);
                break;

            case '3':
                // Quit the program
                printf("\nGoodbye!\n");
                return 0;

            default:
                // Invalid choice
                printf("\nInvalid choice! Please try again.\n");
                break;
        }
    }
}

void get_expense(struct Expense *exp) {

    // Prompt the user to enter an expense category
    printf("\nEnter expense category: ");
    scanf("%s", exp->category);

    // Prompt the user to enter an expense amount
    printf("Enter expense amount: ");
    scanf("%f", &exp->amount);

    // Prompt the user to enter an expense date
    printf("Enter expense date (DD/MM/YYYY): ");
    scanf("%d/%d/%d", &exp->day, &exp->month, &exp->year);

    // Prompt the user to enter an expense description
    printf("Enter expense description: ");
    scanf("%s", exp->description);
}

void save_expense(struct Expense *exp, char *filename) {

    // Open file
    FILE *fp = fopen(filename, "a");

    // Write expense record to file
    fprintf(fp, "%s,%.2f,%02d/%02d/%04d,%s\n", exp->category, exp->amount, exp->day, exp->month, exp->year, exp->description);

    // Close file
    fclose(fp);
}

void read_expense(char *filename) {

    // Declare variables
    FILE *fp;
    char line[100];

    // Open file
    fp = fopen(filename, "r");

    // Read file line by line
    while (fgets(line, 100, fp) != NULL) {
        printf("%s", line);
    }

    // Close file
    fclose(fp);
}

void print_expense(struct Expense exp) {

    // Display expense information
    printf("\nExpense Category: %s\n", exp.category);
    printf("Expense Amount: $%.2f\n", exp.amount);
    printf("Expense Date: %02d/%02d/%04d\n", exp.day, exp.month, exp.year);
    printf("Expense Description: %s\n", exp.description);
}
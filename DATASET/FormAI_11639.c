//FormAI DATASET v1.0 Category: Expense Tracker ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to get the current date and time
void getDateTime(char datetime[]) {
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    strftime(datetime, 20, "%Y-%m-%d %H:%M:%S", tm);
}

// Function to add a new transaction
void addTransaction(char filename[]) {
    FILE *file = fopen(filename, "a+");
    if (file == NULL) {
        printf("Error opening file\n");
        return;
    }

    char datetime[20];
    getDateTime(datetime);

    float amount;
    char description[100];

    printf("Enter amount: ");
    scanf("%f", &amount);
    printf("Enter description: ");
    scanf(" %[^\n]s", description);

    fprintf(file, "%s,%.2f,%s\n", datetime, amount, description);
    fclose(file);
}

// Function to display all transactions
void showTransactions(char filename[]) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return;
    }

    printf("+-----------------------------+\n");
    printf("|       Expense Tracker       |\n");
    printf("+-----------------------------+\n");
    printf("| Date/Time        | Amount   |\n");
    printf("+-----------------------------+\n");

    char line[200];
    while (fgets(line, 200, file)) {
        char *datetime = strtok(line, ",");
        float amount = atof(strtok(NULL, ","));
        char *description = strtok(NULL, ",");
        printf("| %-16s| $ %-7.2f |\n", datetime, amount);
    }

    fclose(file);
}

int main() {
    char filename[] = "expenses.csv";
    int choice;

    while (1) {
        printf("\n--------Expense Tracker--------\n");
        printf("1. Add Transaction\n");
        printf("2. Show Transactions\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addTransaction(filename);
                break;
            case 2:
                showTransactions(filename);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
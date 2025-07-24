//FormAI DATASET v1.0 Category: Expense Tracker ; Style: grateful
#include <stdio.h>

struct Expense {
    char date[10];
    float amount;
    char description[50];
};

int main() {
    struct Expense expenses[100];
    int count = 0;
    char choice;

    do {
        printf("Enter date (DD/MM/YYYY): ");
        scanf("%s", expenses[count].date);

        printf("Enter amount spent: ");
        scanf("%f", &expenses[count].amount);

        printf("Enter brief description: ");
        scanf("%s", expenses[count].description);

        count++;

        printf("Do you want to enter another expense? (y/n): ");
        scanf("%s", &choice);

    } while (choice == 'y' || choice == 'Y');
}
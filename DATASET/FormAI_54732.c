//FormAI DATASET v1.0 Category: Expense Tracker ; Style: ephemeral
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 1000

struct Expense {
    char date[15];
    char item[30];
    float amount;
};

int totalExpenses = 0;

void addExpense(struct Expense []);
void listExpenses(struct Expense []);
void deleteExpense(struct Expense []);

int main() {
    struct Expense expenses[MAX];
    int input;
    printf("*** WELCOME TO EXPENSE TRACKER ***\n\n");
    do {
        printf("Select an option:\n");
        printf("1. Add an expense\n");
        printf("2. List all expenses\n");
        printf("3. Delete an expense\n");
        printf("4. Quit\n");

        scanf("%d", &input);
        switch(input) {
            case 1:
                addExpense(expenses);
                break;
            case 2:
                listExpenses(expenses);
                break;
            case 3:
                deleteExpense(expenses);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid input, please enter a valid option.\n");
                break;
        }
    } while(input != 4);

    return 0;
}

void addExpense(struct Expense expenses[]) {
    printf("Enter expense date (mm/dd/yyyy): ");
    scanf("%s", expenses[totalExpenses].date);

    printf("Enter expense item: ");
    scanf("%s", expenses[totalExpenses].item);

    printf("Enter expense amount: $");
    scanf("%f", &expenses[totalExpenses].amount);

    printf("Expense added successfully!\n\n");

    totalExpenses++;
}

void listExpenses(struct Expense expenses[]) {
    printf("List of all expenses:\n");
    if(totalExpenses == 0) {
        printf("No expenses found.\n");
    } else {
        printf("Date\tItem\tAmount\n");
        for(int i=0; i<totalExpenses; i++) {
            printf("%s\t%s\t$%.2f\n", expenses[i].date, expenses[i].item, expenses[i].amount);
        }
    }
    printf("\n");
}

void deleteExpense(struct Expense expenses[]) {
    int deleteIndex;
    printf("Enter the index of the expense you want to delete: ");
    scanf("%d", &deleteIndex);

    if(deleteIndex>=totalExpenses || deleteIndex<0) {
        printf("Invalid index entered. Please select a valid index.\n\n");
    } else {
        for(int i=deleteIndex; i<totalExpenses; i++) {
            strcpy(expenses[i].date, expenses[i+1].date);
            strcpy(expenses[i].item, expenses[i+1].item);
            expenses[i].amount = expenses[i+1].amount;
        }
        totalExpenses--;
        printf("Expense deleted successfully!\n\n");
    }
}
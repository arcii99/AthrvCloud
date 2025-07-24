//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: paranoid
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define MAX_CATEGORIES 50
#define MAX_TRANSACTIONS 100

typedef struct {
    char name[30];
    double balance;
} Account;

typedef struct {
    char name[30];
    double amount;
    int day, month, year;
} Transaction;

typedef struct {
    char name[30];
    Transaction transactions[MAX_TRANSACTIONS];
    int count;
} Category;

int numAccounts = 0;
Account accounts[MAX_CATEGORIES];

int numCategories = 0;
Category categories[MAX_CATEGORIES];

int numTransactions = 0;
Transaction transactions[MAX_TRANSACTIONS];

void welcome() {
    printf("Welcome to the Personal Finance Planner!\n\n");
}

void start() {
    welcome();
    printf("How many accounts do you want to create? ");
    scanf("%d", &numAccounts);
    for(int i=0; i<numAccounts; i++) {
        printf("Enter the name of account %d: ", i+1);
        scanf("%s", accounts[i].name);
        printf("Enter the balance of account %d: ", i+1);
        scanf("%lf", &accounts[i].balance);
    }
    printf("How many categories do you want to create? ");
    scanf("%d", &numCategories);
    for(int i=0; i<numCategories; i++) {
        printf("Enter the name of category %d: ", i+1);
        scanf("%s", categories[i].name);
        categories[i].count = 0;
    }
}

void printAccounts() {
    printf("Accounts:\n");
    for(int i=0; i<numAccounts; i++) {
        printf("%d. %s - %.2lf\n", i+1, accounts[i].name, accounts[i].balance);
    }
    printf("\n");
}

void printCategories() {
    printf("Categories:\n");
    for(int i=0; i<numCategories; i++) {
        printf("%d. %s\n", i+1, categories[i].name);
    }
    printf("\n");
}

void printTransactions(int n) {
    printf("Transactions:\n");
    for(int i=0; i<n; i++) {
        printf("%d. %s - %.2lf - %d/%d/%d\n", i+1, transactions[i].name, transactions[i].amount, transactions[i].day, transactions[i].month, transactions[i].year);
    }
    printf("\n");
}

void addTransaction() {
    char name[30];
    double amount;
    int day, month, year;
    int accountIndex, categoryIndex;

    printf("Enter the name of the transaction: ");
    scanf("%s", name);
    printf("Enter the amount of the transaction: ");
    scanf("%lf", &amount);
    printf("Enter the date of the transaction (DD/MM/YYYY): ");
    scanf("%d/%d/%d", &day, &month, &year);

    printAccounts();
    printf("Select the account that will be used for this transaction: ");
    scanf("%d", &accountIndex);
    accountIndex--;

    printCategories();
    printf("Select the category for this transaction: ");
    scanf("%d", &categoryIndex);
    categoryIndex--;

    accounts[accountIndex].balance -= amount;
    categories[categoryIndex].transactions[categories[categoryIndex].count].amount = amount;
    categories[categoryIndex].transactions[categories[categoryIndex].count].day = day;
    categories[categoryIndex].transactions[categories[categoryIndex].count].month = month;
    categories[categoryIndex].transactions[categories[categoryIndex].count].year = year;
    strcpy(categories[categoryIndex].transactions[categories[categoryIndex].count].name, name);
    categories[categoryIndex].count++;
    transactions[numTransactions] = categories[categoryIndex].transactions[categories[categoryIndex].count-1];
    numTransactions++;
}

void viewTransactions() {
    printTransactions(numTransactions);
}

void viewTransactionsByAccount() {
    printAccounts();
    int accountIndex;
    printf("Select the account to view transactions for: ");
    scanf("%d", &accountIndex);
    accountIndex--;

    for(int i=0; i<numTransactions; i++) {
        if(strcmp(transactions[i].name, accounts[accountIndex].name) == 0) {
            printf("%d. %s - %.2lf - %d/%d/%d\n", i+1, transactions[i].name, transactions[i].amount, transactions[i].day, transactions[i].month, transactions[i].year);
        }
    }
    printf("\n");
}

void viewTransactionsByCategory() {
    printCategories();
    int categoryIndex;
    printf("Select the category to view transactions for: ");
    scanf("%d", &categoryIndex);
    categoryIndex--;

    printTransactions(categories[categoryIndex].count);
}

int main() {

    start();

    while(1) {
        printf("Enter operation: ");

        char input[100];
        scanf("%s", input);

        if(strcmp(input, "add") == 0) {
            addTransaction();
        }
        else if(strcmp(input, "view-all") == 0) {
            viewTransactions();
        }
        else if(strcmp(input, "view-account") == 0) {
            viewTransactionsByAccount();
        }
        else if(strcmp(input, "view-category") == 0) {
            viewTransactionsByCategory();
        }
        else if(strcmp(input, "quit") == 0) {
            break;
        }
        else {
            printf("Invalid operation. Try again.\n");
        }
    }

    return 0;
}
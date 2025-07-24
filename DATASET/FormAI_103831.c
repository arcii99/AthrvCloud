//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_TRANSACTIONS 1000

typedef struct{
    char description[50];
    float amount;
    char date[11];
    bool isIncome;
} Transaction;

typedef struct{
    float totalIncome;
    float totalExpenses;
    float totalSavings;
    Transaction transactions[MAX_TRANSACTIONS];
    int totalTransactions;
} FinancePlanner;

void addTransaction(FinancePlanner *fp){
    Transaction t;

    printf("\nEnter transaction description: ");
    scanf("%s", t.description);

    printf("\nEnter transaction amount: ");
    scanf("%f", &t.amount);

    printf("\nEnter transaction date (Format: dd/mm/yyyy): ");
    scanf("%s", t.date);

    printf("\nSelect transaction type (1-Income, 0-Expense): ");
    int typeChoice;
    scanf("%d", &typeChoice);

    t.isIncome = typeChoice == 1 ? true : false;

    fp->transactions[fp->totalTransactions++] = t;

    if(t.isIncome){
        fp->totalIncome += t.amount;
        fp->totalSavings += t.amount;
    } else {
        fp->totalExpenses += t.amount;
        fp->totalSavings -= t.amount;
    }

    printf("\nTransaction Added Successfully!\n\n");
}

void viewAllTransactions(FinancePlanner *fp){
    if(fp->totalTransactions == 0){
        printf("\nNo transactions found!\n\n");
        return;
    }

    printf("\n\nID    | TYPE     | DESCRIPTON        | AMOUNT    | DATE\n");
    printf("-------------------------------------------------------\n");

    for(int i = 0;i < fp->totalTransactions;i++){
        Transaction t = fp->transactions[i];
        printf("%d     | %s | %s | %.2f | %s\n", i+1, t.isIncome ? "Income  " : "Expense", t.description, t.amount, t.date);
    }

    printf("\n\nNet Income: %.2f      |    Total Expenses: %.2f        |   Total Savings: %.2f\n\n", fp->totalIncome, fp->totalExpenses, fp->totalSavings);
}

void viewIncomeTransactions(FinancePlanner *fp){
    bool incomeFound = false;
    printf("\n\nID    | DESCRIPTON        | AMOUNT    | DATE\n");
    printf("-----------------------------------------------\n");

    for(int i = 0;i < fp->totalTransactions;i++){
        Transaction t = fp->transactions[i];
        if(t.isIncome){
            printf("%d     | %s | %.2f | %s\n", i+1, t.description, t.amount, t.date);
            incomeFound = true;
        }
    }

    if(!incomeFound){
        printf("\nNo income transactions found!\n\n");
    } else {
        printf("\n\nTotal Income: %.2f\n\n", fp->totalIncome);
    }
}

void viewExpenseTransactions(FinancePlanner *fp){
    bool expenseFound = false;
    printf("\n\nID    | DESCRIPTON        | AMOUNT    | DATE\n");
    printf("-----------------------------------------------\n");

    for(int i = 0;i < fp->totalTransactions;i++){
        Transaction t = fp->transactions[i];
        if(!t.isIncome){
            printf("%d     | %s | %.2f | %s\n", i+1, t.description, t.amount, t.date);
            expenseFound = true;
        }
    }

    if(!expenseFound){
        printf("\nNo expense transactions found!\n\n");
    } else {
        printf("\n\nTotal Expenses: %.2f\n\n", fp->totalExpenses);
    }
}

int main() {
    FinancePlanner fp;
    fp.totalTransactions = 0;
    fp.totalIncome = 0;
    fp.totalExpenses = 0;
    fp.totalSavings = 0;

    while(1){
        printf("MAIN MENU\n");
        printf("1. Add Transaction\n");
        printf("2. View All Transactions\n");
        printf("3. View Income Transactions\n");
        printf("4. View Expense Transactions\n");
        printf("5. Exit\n");

        printf("\nEnter choice 1-5: ");
        int choice;
        scanf("%d", &choice);

        switch(choice){
            case 1:
                addTransaction(&fp);
                break;
            case 2:
                viewAllTransactions(&fp);
                break;
            case 3:
                viewIncomeTransactions(&fp);
                break;
            case 4:
                viewExpenseTransactions(&fp);
                break;
            case 5:
                printf("\nExiting...\n");
                exit(0);
            default:
                printf("\nInvalid Choice!\n\n");
        }
    }

    return 0;
}
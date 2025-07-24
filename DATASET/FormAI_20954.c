//FormAI DATASET v1.0 Category: Expense Tracker ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define MAX_TRANSACTIONS 1000
#define MAX_CATEGORY_LENGTH 20

typedef struct{
    float amount;
    char date[11];
    char category[MAX_CATEGORY_LENGTH];
} Transaction;

Transaction transactions[MAX_TRANSACTIONS];
int transaction_count = 0;

void add_transaction(float amount, char* date, char* category){
    Transaction new_transaction = {amount, "", ""};
    sprintf(new_transaction.date, "%s", date);
    sprintf(new_transaction.category, "%s", category);
    transactions[transaction_count++] = new_transaction;
}

float calculate_total_expenses(){
    float total = 0.0;
    for(int i=0; i<transaction_count; i++){
        total += transactions[i].amount;
    }
    return total;
}

bool is_valid_category(char* category){
    // Hardcoded valid categories for this example program
    const char* valid_categories[] = {"Food", "Transportation", "Housing", "Entertainment", "Shopping", "Other"};
    const int num_valid_categories = 6;

    for(int i=0; i<num_valid_categories; i++){
        if(strcmp(category, valid_categories[i]) == 0){
            return true;
        }
    }
    return false;
}

void print_transactions(char* category){
    bool filter_by_category = (category != NULL && strlen(category) > 0);

    printf("\nTransaction History:\n");
    for(int i=0; i<transaction_count; i++){
        if(filter_by_category && strcmp(transactions[i].category, category) != 0){
            continue;
        }
        printf("%s\t%s\t%.2f\n", transactions[i].date, transactions[i].category, transactions[i].amount);
    }
}

void print_summary(char* category){
    bool filter_by_category = (category != NULL && strlen(category) > 0);

    float total_expenses = 0.0;
    int num_transactions = 0;

    printf("\nExpense Summary ");
    if(filter_by_category){
        printf("for %s", category);
    }
    printf(":\n");

    for(int i=0; i<transaction_count; i++){
        if(filter_by_category && strcmp(transactions[i].category, category) != 0){
            continue;
        }
        total_expenses += transactions[i].amount;
        num_transactions++;
    }

    printf("Total Expenses: %.2f\n", total_expenses);
    printf("Number of Transactions: %d\n", num_transactions);
    printf("Average Expense per Transaction: %.2f\n", total_expenses / num_transactions);
}

int main(int argc, char** argv){
    add_transaction(4.99, "2021-10-05", "Food");
    add_transaction(9.87, "2021-09-30", "Housing");
    add_transaction(12.73, "2021-09-28", "Transportation");
    add_transaction(5.00, "2021-09-25", "Other");

    printf("Total Expenses: %.2f\n", calculate_total_expenses());

    print_transactions(NULL);
    print_transactions("Food");

    print_summary(NULL);
    print_summary("Housing");

    return 0;
}
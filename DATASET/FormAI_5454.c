//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CATEGORIES 10
#define MAX_TRANSACTIONS 100

typedef struct {
    char name[50];
    double budget;
} category;

typedef struct {
    char category_name[50];
    double amount;
} transaction;

category categories[MAX_CATEGORIES];
transaction transactions[MAX_TRANSACTIONS];

int num_categories = 0;
int num_transactions = 0;

void add_category(char name[], double budget) {
    if (num_categories == MAX_CATEGORIES) {
        printf("Error: Maximum number of categories reached.\n");
        return;
    }
    category new_category;
    strcpy(new_category.name, name);
    new_category.budget = budget;
    categories[num_categories] = new_category;
    num_categories++;
}

void add_transaction(char category_name[], double amount) {
    if (num_transactions == MAX_TRANSACTIONS) {
        printf("Error: Maximum number of transactions reached.\n");
        return;
    }
    transaction new_transaction;
    strcpy(new_transaction.category_name, category_name);
    new_transaction.amount = amount;
    transactions[num_transactions] = new_transaction;
    num_transactions++;
}

double get_total_spent(char category_name[]) {
    double total = 0;
    for (int i = 0; i < num_transactions; i++) {
        if (strcmp(transactions[i].category_name, category_name) == 0) {
            total += transactions[i].amount;
        }
    }
    return total;
}

double get_total_budget() {
    double total = 0;
    for (int i = 0; i < num_categories; i++) {
        total += categories[i].budget;
    }
    return total;
}

double get_remaining_budget(char category_name[]) {
    for (int i = 0; i < num_categories; i++) {
        if (strcmp(categories[i].name, category_name) == 0) {
            return categories[i].budget - get_total_spent(category_name);
        }
    }
    return -1;
}

int main() {
    add_category("Food", 500.0);
    add_category("Entertainment", 200.0);
    add_category("Transportation", 100.0);

    add_transaction("Food", 50.0);
    add_transaction("Food", 75.0);
    add_transaction("Entertainment", 20.0);
    add_transaction("Transportation", 10.0);

    double total_spent = 0;
    for (int i = 0; i < num_categories; i++) {
        total_spent += get_total_spent(categories[i].name);
        printf("%s - Budget: $%.2f, Spent: $%.2f, Remaining: $%.2f\n", categories[i].name, 
                categories[i].budget, get_total_spent(categories[i].name), get_remaining_budget(categories[i].name));
    }
    printf("Total Budget: $%.2f, Total Spent: $%.2f, Total Remaining: $%.2f\n", 
            get_total_budget(), total_spent, get_total_budget() - total_spent);
    return 0;
}
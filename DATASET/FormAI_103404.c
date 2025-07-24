//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

#define MAX_DESC_LENGTH 50
#define MAX_CATEGORIES 10

struct Expense {
    char description[MAX_DESC_LENGTH];
    float amount;
};

struct Category {
    char name[MAX_DESC_LENGTH];
    struct Expense expenses[10];
    int num_expenses;
};

struct Budget {
    float total_budget;
    struct Category categories[MAX_CATEGORIES];
    int num_categories;    
};

int main() {
    struct Budget budget;
    budget.total_budget = 5000.0;
    budget.num_categories = 0;
    
    // Add categories
    struct Category housing = {"Housing"};
    struct Category food = {"Food"};
    
    // Add expenses to categories
    struct Expense rent = {"Rent", 1000.0};
    struct Expense utilities = {"Utilities", 200.0};
    housing.expenses[0] = rent;
    housing.expenses[1] = utilities;
    housing.num_expenses = 2;
    
    struct Expense groceries = {"Groceries", 300.0};
    struct Expense dining_out = {"Dining Out", 100.0};
    food.expenses[0] = groceries;
    food.expenses[1] = dining_out;
    food.num_expenses = 2;
    
    // Add categories to budget
    budget.categories[0] = housing;
    budget.categories[1] = food;
    budget.num_categories = 2;
    
    // Calculate total spent in each category
    float category_total = 0.0;
    for (int i = 0; i < budget.num_categories; i++) {
        category_total = 0.0;
        printf("%s expenses: \n", budget.categories[i].name);
        for (int j = 0; j < budget.categories[i].num_expenses; j++) {
            category_total += budget.categories[i].expenses[j].amount;
            printf("%s - $%.2f \n", budget.categories[i].expenses[j].description, budget.categories[i].expenses[j].amount);
        }
        printf("Total %s expenses: $%.2f\n\n", budget.categories[i].name, category_total);
    }
    
    // Calculate total remaining budget
    float budget_total_spent = 0.0;
    for (int i = 0; i < budget.num_categories; i++) {
        for (int j = 0; j < budget.categories[i].num_expenses; j++) {
            budget_total_spent += budget.categories[i].expenses[j].amount;
        }
    }
    float budget_total_remaining = budget.total_budget - budget_total_spent;
    printf("Remaining budget: $%.2f\n\n", budget_total_remaining);
    
    return 0;
}
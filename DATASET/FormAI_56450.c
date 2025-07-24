//FormAI DATASET v1.0 Category: Expense Tracker ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100

struct Expense {
    float amount;
    char category[20];
};

struct ExpenseTracker {
    struct Expense expenses[MAX_EXPENSES];
    int num_expenses;
};

// function prototypes
float get_total_expenses(struct ExpenseTracker* tracker, char* category);
void add_expense(struct ExpenseTracker* tracker, float amount, char* category);
void print_expenses(struct ExpenseTracker* tracker);

int main() {
    struct ExpenseTracker tracker;
    tracker.num_expenses = 0;

    // add some expenses
    add_expense(&tracker, 10.5, "Food");
    add_expense(&tracker, 20.0, "Transportation");
    add_expense(&tracker, 50.0, "Entertainment");
    add_expense(&tracker, 30.0, "Food");

    // print expenses
    printf("All expenses:\n");
    print_expenses(&tracker);

    // get total expenses in Food category
    float total_food_expenses = get_total_expenses(&tracker, "Food");
    printf("Total expenses in Food category: %.2f\n", total_food_expenses);

    return 0;
}

float get_total_expenses(struct ExpenseTracker* tracker, char* category) {
    float total = 0.0;
    for (int i = 0; i < tracker->num_expenses; i++) {
        if (strcmp(tracker->expenses[i].category, category) == 0) {
            total += tracker->expenses[i].amount;
        }
    }
    return total;
}

void add_expense(struct ExpenseTracker* tracker, float amount, char* category) {
    if (tracker->num_expenses < MAX_EXPENSES) {
        struct Expense new_expense = {amount, category};
        tracker->expenses[tracker->num_expenses] = new_expense;
        tracker->num_expenses++;
    } else {
        printf("Error: maximum number of expenses reached\n");
    }
}

void print_expenses(struct ExpenseTracker* tracker) {
    for (int i = 0; i < tracker->num_expenses; i++) {
        printf("Amount: %.2f, Category: %s\n", tracker->expenses[i].amount, tracker->expenses[i].category);
    }
}
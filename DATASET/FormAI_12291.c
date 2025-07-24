//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

// Define a struct to store user's financial information
struct finance {
    double current_savings;
    double salary;
    double expenses;
    double expected_inheritance;
    int num_years;
};

// Function to calculate user's net worth after a certain number of years
double calculate_net_worth(struct finance f) {
    double future_value_savings = f.current_savings;
    for (int i=0; i<f.num_years; i++) {
        future_value_savings *= 1.05; // Assume a 5% annual interest rate
        future_value_savings += f.salary - f.expenses;
        if (i == 25) {
            // On the 25th year, user receives an expected inheritance
            future_value_savings += f.expected_inheritance;
        }
    }
    return future_value_savings;
}

// Function to prompt user to input their financial information
struct finance get_user_finance_info() {
    struct finance f;
    printf("Enter your current savings: ");
    scanf("%lf", &f.current_savings);
    printf("Enter your annual salary: ");
    scanf("%lf", &f.salary);
    printf("Enter your monthly expenses: ");
    scanf("%lf", &f.expenses);
    f.expenses *= 12; // Convert monthly expenses to annual expenses
    printf("Enter the expected inheritance (0 if none expected): ");
    scanf("%lf", &f.expected_inheritance);
    printf("Enter the number of years to plan for: ");
    scanf("%d", &f.num_years);
    return f;
}

int main() {
    struct finance user_finance = get_user_finance_info();
    double net_worth = calculate_net_worth(user_finance);
    printf("Your net worth after %d years is $%.2lf.\n", user_finance.num_years, net_worth);
    return 0;
}
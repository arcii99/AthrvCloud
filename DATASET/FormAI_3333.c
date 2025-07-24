//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

// Define constants for tax and inflation rates
#define TAX_RATE 0.25
#define INFLATION_RATE 0.03

// Define struct to hold financial details
typedef struct {
    float salary;
    float expenses;
    float savings;
    float investments;
    float tax_paid;
    float retirement_savings;
    float net_worth;
} FinancialDetails;

// Function declaration
void print_details(FinancialDetails details);

int main() {
    // Declare and initialize variables
    FinancialDetails my_details = {70000, 55000, 15000, 5000, 0, 0, 0};

    // Calculate tax paid and update financial details
    my_details.tax_paid = my_details.salary * TAX_RATE;
    my_details.savings -= my_details.tax_paid;

    // Calculate inflation and update financial details
    float inflation_amount = my_details.savings * INFLATION_RATE;
    my_details.savings -= inflation_amount;

    // Calculate retirement savings and update financial details
    my_details.retirement_savings = my_details.salary * 0.15;
    my_details.savings -= my_details.retirement_savings;

    // Calculate net worth and update financial details
    my_details.net_worth = my_details.savings + my_details.investments;

    // Print financial details
    print_details(my_details);

    return 0;
}

void print_details(FinancialDetails details) {
    // Print financial details
    printf("Salary: %.2f\n", details.salary);
    printf("Expenses: %.2f\n", details.expenses);
    printf("Savings: %.2f\n", details.savings);
    printf("Investments: %.2f\n", details.investments);
    printf("Tax Paid: %.2f\n", details.tax_paid);
    printf("Retirement Savings: %.2f\n", details.retirement_savings);
    printf("Net Worth: %.2f\n", details.net_worth);
}
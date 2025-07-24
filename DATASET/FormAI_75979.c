//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: peaceful
#include <stdio.h>

float calcSavings(float salary, float expenses) {
    return salary - expenses;
}

float calcNetIncome(float salary, float taxes) {
    return salary - taxes;
}

float calcTax(float salary) {
    if (salary <= 10000) {
        return 0;
    } else if (salary <= 50000) {
        return (salary - 10000) * 0.1;
    } else {
        return 4000 + (salary - 50000) * 0.2;
    }
}

int main() {

    // Declare variables
    float salary, expenses, tax, netIncome, savings;
    
    // Get user input
    printf("Enter your monthly salary: ");
    scanf("%f", &salary);
    printf("Enter your monthly expenses: ");
    scanf("%f", &expenses);
    
    // Calculate tax
    tax = calcTax(salary);
    
    // Calculate net income
    netIncome = calcNetIncome(salary, tax);
    
    // Calculate savings
    savings = calcSavings(netIncome, expenses);
    
    // Output results
    printf("Your monthly salary is: $%.2f\n", salary);
    printf("Your monthly expenses are: $%.2f\n", expenses);
    printf("Your monthly tax is: $%.2f\n", tax);
    printf("Your monthly net income is: $%.2f\n", netIncome);
    printf("Your monthly savings is: $%.2f\n", savings);
    
    return 0;
}
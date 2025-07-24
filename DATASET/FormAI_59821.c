//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: Donald Knuth
#include <stdio.h>

// Structures to hold financial data
typedef struct {
    double income;
    double expenses;
} FinancialData;

typedef struct {
    char name[50];
    FinancialData finance;
} Person;

// Calculate total income and expenses
void calculateTotal(FinancialData data[], int size, double *totalIncome, double *totalExpenses) {
    for (int i = 0; i < size; i++) {
        *totalIncome += data[i].income;
        *totalExpenses += data[i].expenses;
    }
}

int main() {
    // Initialize person variables
    Person person1, person2;
    strcpy(person1.name, "John Smith");
    person1.finance.income = 70000.00;
    person1.finance.expenses = 50000.00;
    
    strcpy(person2.name, "Jane Doe");
    person2.finance.income = 75000.00;
    person2.finance.expenses = 55000.00;
    
    // Calculate total income and expenses for both individuals
    double totalIncome = 0.0;
    double totalExpenses = 0.0;
    FinancialData data[] = {person1.finance, person2.finance};
    calculateTotal(data, sizeof(data)/sizeof(data[0]), &totalIncome, &totalExpenses);
    
    // Print results
    printf("Total Income: $%.2f\n", totalIncome);
    printf("Total Expenses: $%.2f\n", totalExpenses);
    printf("Net Income: $%.2f\n", totalIncome - totalExpenses);
    
    // Check if net income is positive or negative
    if (totalIncome - totalExpenses > 0) {
        printf("Congratulations, you have a positive net income!\n");
    } else if (totalIncome - totalExpenses == 0) {
        printf("Your net income is 0. Consider finding ways to increase your income or reduce your expenses.\n");
    } else {
        printf("Your net income is negative. Consider finding ways to increase your income or reduce your expenses.\n");
    }
    
    return 0;
}
//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

int main() {
    float salary, rent, groceries, bills, savings;
    
    printf("Please enter your monthly salary: ");
    scanf("%f", &salary);
    
    printf("Please enter your monthly rent or mortgage payment: ");
    scanf("%f", &rent);
    
    printf("Please enter your monthly grocery expense: ");
    scanf("%f", &groceries);
    
    printf("Please enter your monthly bills (utilities, phone, etc.): ");
    scanf("%f", &bills);
    
    printf("Please enter the percentage of your salary you want to save each month: ");
    scanf("%f", &savings);
    savings = savings / 100;
    
    // Calculate the remaining balance
    float remaining_balance = salary - rent - groceries - bills - (salary * savings);
    
    printf("\n\n");
    printf("##############################\n");
    printf("Monthly Personal Finance Report\n");
    printf("##############################\n\n");
    printf("Monthly Salary: %.2f\n\n", salary);
    printf("Monthly Expenses:\n");
    printf("Rent/Mortgage: %.2f\nGroceries: %.2f\nBills: %.2f\n\n", rent, groceries, bills);
    printf("Monthly Savings: %.2f%% of salary, which is %.2f\n\n", savings * 100, salary * savings);
    printf("Remaining Balance: %.2f\n", remaining_balance);
    
    if (remaining_balance < 0) {
        printf("Warning: You are spending more than you earn. Consider reducing expenses or increasing income.\n");
    }
    
    return 0;
}
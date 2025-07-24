//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: recursive
#include <stdio.h>

//Function signature for recursive calls
float calculate_savings(int current_month, float total_income, float total_expense, float savings);

int main() {
    int current_month = 1;
    float total_income, total_expense, savings;

    printf("Enter your total income for this month: ");
    scanf("%f", &total_income);

    printf("Enter your total expense for this month: ");
    scanf("%f", &total_expense);

    savings = total_income - total_expense;

    printf("\nYour savings for this month is: Rs. %.2f\n", savings);

    savings = calculate_savings(current_month+1, total_income, total_expense, savings);

    return 0;
}

float calculate_savings(int current_month, float total_income, float total_expense, float savings) {
    float new_income, new_expense, new_savings;

    printf("Enter your total income for month %d (-1 to stop): ", current_month);
    scanf("%f", &new_income);

    if(new_income == -1) {
        printf("Thank you for using Personal Finance Planner!\n");
        return savings;
    }

    printf("Enter your total expenses for month %d: ", current_month);
    scanf("%f", &new_expense);

    new_savings = new_income - new_expense + savings;

    printf("\nYour savings for month %d is: Rs. %.2f\n", current_month, new_savings);

    //Recursive call to calculate savings for next month
    return calculate_savings(current_month+1, total_income + new_income, total_expense + new_expense, new_savings);
}
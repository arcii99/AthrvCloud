//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: sophisticated
#include <stdio.h>

int main() {
    float salary;
    printf("Please enter your monthly salary: ");
    scanf("%f", &salary);

    float expenses[12];
    float sum = 0;

    for(int i = 0; i < 12; i++) {
        printf("Please enter your expenses for month %d: ", i+1);
        scanf("%f", &expenses[i]);
        sum += expenses[i];
    }

    float avg_exp = sum/12;
    float saved = salary - sum;

    printf("\n");
    printf("*********************************\n");
    printf("**********FINANCIAL PLAN*********\n");
    printf("Monthly Salary: %.2f\n", salary);
    printf("Total Expenses: %.2f\n", sum);
    printf("Average Monthly Expense: %.2f\n", avg_exp);
    printf("Total Amount Saved: %.2f\n", saved);
    printf("*********************************\n");

    if(saved < 0) {
        printf("WARNING: You are spending more than your monthly salary!!\n");
    } else if(saved == 0) {
        printf("WARNING: You are not saving any money this year.\n");
    } else {
        printf("Congratulations! You are saving money each month.\n");
    }

    return 0;
}
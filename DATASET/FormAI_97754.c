//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: light-weight
#include <stdio.h>

int main()
{
    float salary, expenses, savings;
    printf("Enter your monthly salary: ");
    scanf("%f", &salary);
    printf("Enter your monthly expenses: ");
    scanf("%f", &expenses);

    savings = salary - expenses;

    if (savings > 0) {
        printf("You have a positive savings of $%.2f\n", savings);
    } else if (savings == 0) {
        printf("You have no savings\n");
    } else {
        printf("You are spending more than you earn\n");
    }

    return 0;
}
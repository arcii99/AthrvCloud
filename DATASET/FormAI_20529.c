//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: inquisitive
#include <stdio.h>

int main() {
    double salary, taxes, net_income;
    printf("Enter your monthly salary: ");
    scanf("%lf", &salary);

    printf("Enter your monthly taxes: ");
    scanf("%lf", &taxes);

    net_income = salary - taxes;

    printf("Your monthly net income is: %.2lf\n", net_income);

    return 0;
}
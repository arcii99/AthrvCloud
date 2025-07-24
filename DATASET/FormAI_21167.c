//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: detailed
#include <stdio.h>

int main() {
    double salary, rent, food, transportation, savings, totalExpenses;
    int month;

    printf("Enter your monthly salary: ");
    scanf("%lf", &salary);

    printf("Enter your monthly rent: ");
    scanf("%lf", &rent);

    printf("Enter your monthly food expenses: ");
    scanf("%lf", &food);

    printf("Enter your monthly transportation expenses: ");
    scanf("%lf", &transportation);

    printf("Enter your desired monthly savings: ");
    scanf("%lf", &savings);

    totalExpenses = rent + food + transportation;

    if (salary <= totalExpenses) {
        printf("Your expenses are greater than your income. You need to cut down on your expenses.\n");
    } else {
        for (month = 1; month <= 12; month++) {
            double remainingMoney = salary - totalExpenses - savings;
            printf("\nMonth %d\n", month);
            printf("Remaining Money: %.2lf\n", remainingMoney);

            if (remainingMoney < 0) {
                printf("Warning! You are spending more than your income in Month %d.\n", month);
            }

            printf("Savings: %.2lf\n", savings);
            printf("Total Expenses: %.2lf\n", totalExpenses);
        }
    }

    return 0;
}
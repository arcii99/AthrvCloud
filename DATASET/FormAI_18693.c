//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: invasive
#include <stdio.h>

int main() {
    int income, rent, food, utilities, transportation, entertainment, savings;
    printf("Welcome to your Personal Finance Planner!\n");
    printf("Let's get started.\n");

    printf("Enter your monthly income: ");
    scanf("%d", &income);

    printf("Enter your monthly rent/mortgage payments: ");
    scanf("%d", &rent);

    printf("Enter your monthly food expenses: ");
    scanf("%d", &food);

    printf("Enter your monthly utilities bill: ");
    scanf("%d", &utilities);

    printf("Enter your monthly transportation expenses: ");
    scanf("%d", &transportation);

    printf("Enter your monthly entertainment expenses: ");
    scanf("%d", &entertainment);

    printf("Enter the amount you want to save each month: ");
    scanf("%d", &savings);

    int total_expenses = rent + food + utilities + transportation + entertainment;
    int remaining_income = income - total_expenses - savings;

    printf("\nYour total monthly expenses are: %d\n", total_expenses);
    
    if (remaining_income < 0) {
        printf("Uh oh, it looks like you are spending more than you earn each month. ");
        printf("You need to reduce your expenses or increase your income.\n");
    } else if (remaining_income == 0) {
        printf("You are breaking even each month. ");
        printf("Consider allocating some funds towards savings or reducing expenses if possible.\n");
    } else {
        printf("You have %d leftover every month.\n", remaining_income);
        printf("Consider allocating some of this towards savings or investments.\n");
    }

    printf("\nThanks for using your Personal Finance Planner! Good luck achieving your financial goals!\n");

    return 0;
}
//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: Romeo and Juliet
#include <stdio.h>

int main() {
    float monthly_income, rent, utilities, groceries, other_expenses, savings;
    printf("O Romeo, how much is thine monthly income?\n");
    scanf("%f", &monthly_income);
    printf("And tell me, Juliet, what do you pay for thy rent each month?\n");
    scanf("%f", &rent);
    printf("Thou art charged for utilities as well. How much do they cost per month?\n");
    scanf("%f", &utilities);
    printf("And for thy nourishment, what be thine monthly expense for groceries?\n");
    scanf("%f", &groceries);
    printf("But soft, what other expenses doth thou possess? Please tell me the amount thereof.\n");
    scanf("%f", &other_expenses);
    printf("Oh sweetest of maidens, what percentage of thy monthly income dost thou reserve for thy savings?\n");
    scanf("%f", &savings);
    float total_expenses = rent + utilities + groceries + other_expenses;
    float saved = monthly_income * savings / 100;
    float remaining_balance = monthly_income - total_expenses - saved;
    printf("Therefore, Juliet, thy total monthly expenses amount to %0.2f coins.\n", total_expenses);
    printf("And lo! With a savings percentage of %0.2f%%, thou shalt save %0.2f coins per month.\n", savings, saved);
    printf("Thine remaining monthly balance after all expenses and savings art accounted for is %0.2f coins.\n", remaining_balance);
    return 0;
}
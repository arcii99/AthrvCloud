//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: surprised
#include <stdio.h>

int main() {
    printf("Welcome to Personal Finance Planner! Let's get started! \n");

    float salary, rent, utilities, groceries, entertainment, savings;
    // variable to store user's input
    
    printf("Please enter your monthly salary: ");
    scanf("%f", &salary);

    printf("How much do you spend on rent per month?: ");
    scanf("%f", &rent);

    printf("How much do you spend on utilities per month?: ");
    scanf("%f", &utilities);

    printf("How much do you spend on groceries per month?: ");
    scanf("%f", &groceries);

    printf("How much do you spend on entertainment per month?: ");
    scanf("%f", &entertainment);

    savings = salary - rent - utilities - groceries - entertainment;

    printf("\n");

    printf("Your monthly income: $%.2f \n", salary);
    printf("Your monthly expenses: $%.2f \n", rent + utilities + groceries + entertainment);
    printf("Your monthly savings: $%.2f \n", savings);

    if (savings < 0) {
        printf("Uh oh! You're spending more than you're making. You need to cut back on your expenses. \n");
    } else if (savings == 0) {
        printf("You're breaking even. Try to find ways to save money so you can start building your wealth. \n");
    } else {
        printf("Congratulations! It looks like you're able to save some money each month. Keep it up! \n");
    }

    return 0;
}
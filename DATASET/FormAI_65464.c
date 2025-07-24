//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

int main() {
    float salary, expenses, savings;
    int i;
    printf("Enter your monthly salary: ");
    scanf("%f", &salary);

    printf("Enter your monthly expenses: ");
    scanf("%f", &expenses);

    savings = salary - expenses;

    printf("\nWelcome to your Personal Finance Planner!\n\n");
    printf("Your Monthly Salary is $%.2f\n", salary);
    printf("Your Monthly Expenses are $%.2f\n", expenses);
    printf("Your Monthly Savings are $%.2f\n\n", savings);

    int option;

    while(1) {
        printf("Choose an Option:\n");
        printf("================\n");
        printf("1. Set a Savings Goal\n");
        printf("2. Calculate your Retirement amount\n");
        printf("3. Calculate your Loan EMI\n");
        printf("4. Exit\n\n");

        printf("Enter your choice: ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                printf("\nEnter your Savings Goal: ");
                float goal;
                scanf("%f", &goal);

                float num_months = goal / savings;

                printf("You need to save for %.2f months to reach your goal of $%.2f\n\n", num_months, goal);
                break;

            case 2:
                printf("\nEnter the amount you have saved for retirement: ");
                float current_amt;
                scanf("%f", &current_amt);

                float retired_amt = (current_amt * 1.1) * 12;

                printf("You will have $%.2f upon retirement.\n\n", retired_amt);
                break;

            case 3:
                printf("\nEnter the Loan Amount: ");
                float loan_amt;
                scanf("%f", &loan_amt);

                printf("Enter the Interest rate: ");
                float interest_rate;
                scanf("%f", &interest_rate);

                printf("Enter the number of years: ");
                int years;
                scanf("%d", &years);

                float emi_amt = (loan_amt * interest_rate * pow((1+interest_rate), (float)years))/(pow((1+interest_rate), (float)years)-1);

                printf("The EMI amount for your loan is $%.2f\n\n", emi_amt);

                break;

            case 4:
                printf("\nThank you for using the Personal Finance Planner!\n");
                exit(0);

            default:
                printf("Invalid option. Please choose again.\n\n");
                break;
        }
    }
    return 0;
}
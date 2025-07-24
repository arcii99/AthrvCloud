//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: relaxed
#include <stdio.h>

int main() {
    float salary, expenses, savings;
    printf("Welcome to the Personal Finance Planner!\n");
    printf("Please enter your monthly salary: $");
    scanf("%f", &salary);
    printf("Please enter your monthly expenses: $");
    scanf("%f", &expenses);
    savings = salary - expenses;

    if (savings < 0) {
        printf("\nUh oh! It looks like you are spending more than you are earning!\n");
        printf("You need to re-evaluate your expenses and find ways to save more money.\n");
    } else if (savings == 0) {
        printf("\nYou are breaking even every month. You should aim to save some money each month for unexpected expenses.\n");
    } else {
        printf("\nCongratulations on saving $%.2f this month!\n", savings);
        printf("You should consider investing some of your savings in stocks, mutual funds, or other investment options.\n");
    }

    return 0;
}
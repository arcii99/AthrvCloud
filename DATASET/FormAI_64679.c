//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: recursive
#include<stdio.h>
#include<stdlib.h>

int calculateSavings(int, int, int); // function prototype

int main() {
    int income, expenditure, savings;
    printf("Enter your monthly income: ");
    scanf("%d", &income);
    printf("Enter your monthly expenditure: ");
    scanf("%d", &expenditure);
    savings = calculateSavings(income, expenditure, 0); // recursive function call
    printf("Your monthly savings is: %d\n", savings);
    return 0;
}

int calculateSavings(int income, int expenditure, int savings) {
    if(expenditure >= income) { // base case: when expenditure exceeds income
        printf("Your expenditure exceeds income!\n");
        return 0;
    }
    else { // recursive case: when expenditure is less than income
        savings += income - expenditure;
        printf("Enter the number of months to calculate savings for: ");
        int months;
        scanf("%d", &months);
        if(months == 0) { // base case: when the user enters 0 months
            return savings;
        }
        else { // recursive case: when the user enters number of months greater than 0
            printf("Enter income for this month: ");
            int currentIncome;
            scanf("%d", &currentIncome);
            printf("Enter expenditure for this month: ");
            int currentExpenditure;
            scanf("%d", &currentExpenditure);
            return calculateSavings(currentIncome, currentExpenditure, savings) + calculateSavings(income, expenditure, savings); // recursive function call
        }
    }
}
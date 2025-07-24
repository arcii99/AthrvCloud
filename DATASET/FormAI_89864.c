//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: complete
#include<stdio.h>
#include<stdlib.h>

int main(){
    //declaring variables
    float income, expenses, savings, remainingBalance;
    int months;
    //getting user input
    printf("Enter your monthly income: $");
    scanf("%f", &income);
    printf("Enter your monthly expenses: $");
    scanf("%f", &expenses);
    printf("Enter the number of months you want to plan for: ");
    scanf("%d", &months);
    //calculating savings and remaining balance for each month
    for(int i=1; i<=months; i++){
        savings = income - expenses;
        remainingBalance += savings;
        printf("\nMonth %d:\n", i);
        printf("Your savings for the month is $%.2f\n", savings);
        printf("Your remaining balance after this month is $%.2f\n", remainingBalance);
        //checking if remaining balance is below $0
        if(remainingBalance<0){
            printf("Warning: Your balance is below $0\n");
        }
    }
    printf("\nTotal savings for %d months is $%.2f\n", months, remainingBalance);
    return 0;
}
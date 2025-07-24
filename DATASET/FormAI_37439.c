//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: recursive
#include <stdio.h>

int calculate_savings(int month, int goal, int current_savings){

    if(current_savings >= goal){
        return month;
    }

    current_savings += 1000; //Assuming a monthly salary of $1000
    int expenses = (month%2 == 0) ? 800 : 600; //Expenses are $800 in even months and $600 in odd months

    current_savings -= expenses;

    return calculate_savings(month+1, goal, current_savings);
}

int main(){

    int goal = 10000; //The savings goal is $10,000
    int current_savings = 0;

    int months = calculate_savings(1, goal, current_savings);

    printf("It will take %d months to reach your savings goal of $%d.\n", months, goal);

    return 0;
}
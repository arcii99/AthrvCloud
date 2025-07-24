//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: calm
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Struct to hold user financial information
struct finance{
    float monthly_income;
    float monthly_expenses;
    float savings_goal;
    float current_savings;
};

//Function to get user inputs for financial information
void get_user_info(struct finance *user){
    printf("Please enter your monthly income: $");
    scanf("%f",&user->monthly_income);

    printf("Please enter your monthly expenses: $");
    scanf("%f",&user->monthly_expenses);

    printf("Please enter your savings goal: $");
    scanf("%f",&user->savings_goal);

    printf("Please enter your current savings: $");
    scanf("%f",&user->current_savings);
}

//Function to calculate and display user financial status
void display_user_status(struct finance *user){
    float net_income = user->monthly_income - user->monthly_expenses;
    float months_to_goal = (user->savings_goal - user->current_savings)/(net_income);
    int years_to_goal = (int)(months_to_goal/12);
    int months_remaining = (int)months_to_goal%12;

    //Display financial status to user
    printf("\nYour net income per month is: $%.2f\n",net_income);
    printf("At this rate, it will take you approximately %d years and %d months to reach your savings goal.\n",years_to_goal,months_remaining);
}

int main(){
    struct finance user;
    get_user_info(&user);
    display_user_status(&user);

    return 0;
}
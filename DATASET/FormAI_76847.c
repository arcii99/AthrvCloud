//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: immersive
#include<stdio.h>

int main(){
    float income, expenses, saving, rent, utilities, food, transportation, entertainment, extra;
    //input
    printf("Welcome to the Personal Finance Planner Program!\n");
    printf("Please enter your monthly income: ");
    scanf("%f", &income);
    printf("Please enter your monthly expenses:\n");
    printf("Rent: ");
    scanf("%f", &rent);
    printf("Utilities: ");
    scanf("%f", &utilities);
    printf("Food: ");
    scanf("%f", &food);
    printf("Transportation: ");
    scanf("%f", &transportation);
    printf("Entertainment: ");
    scanf("%f", &entertainment);
    printf("Extra expenses: ");
    scanf("%f", &extra);
    
    //calculate
    expenses = rent + utilities + food + transportation + entertainment + extra;
    saving = income - expenses;
    
    //output
    printf("\n===Personal Finance Planner Result===\n");
    printf("Monthly Income: $%.2f\n", income);
    printf("Monthly Expenses: $%.2f\n", expenses);
    printf("Monthly Saving: $%.2f\n", saving);

    if(saving > 0){
        printf("You are doing great! You have saved $%.2f this month\n", saving);
    }else if(saving == 0){
        printf("You have spent exactly what you earned. Try to save something next month\n");
    }else{
        printf("You have spent more than you earned this month. Try to cut some expenses\n");
    }
    return 0;
}
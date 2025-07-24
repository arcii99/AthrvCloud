//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: post-apocalyptic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct person{
    int age;
    int income;
    int debt;
    int savings;
};

int main() {
    struct person user;
    srand(time(0));
    user.age = rand() % 50 + 20;
    user.income = rand() % 50000 + 10000;
    user.debt = rand() % 20000;
    user.savings = rand() % 5000;
    int totalMoney = user.income - user.debt;
    if(totalMoney < 0){
        printf("We are sorry! Your debt is more than your income. You cannot save money.");
    }
    else{
        if(totalMoney >= 20000){
            printf("Congrats! You can invest $5000 in stocks, $10000 in real estate and keep $5000 as emergency fund.\n");
            user.savings = user.savings + 5000;
        }
        else if(totalMoney >= 10000){
            printf("You should invest $2000 in stocks, $5000 in real estate and keep $3000 as emergency fund.\n");
            user.savings = user.savings + 3000;
        }
        else if(totalMoney >= 5000){
            printf("Invest $1000 in stocks, $2500 in real estate and keep $1500 as emergency fund.\n");
            user.savings = user.savings + 1500;
        }
        else{
            printf("It's important to pay off your debt first. Keep $1000 as emergency fund and pay off the rest of the debt.\n");
            user.savings = user.savings + 1000;
            user.debt = 0;
        }
        printf("Your savings account now has $%d\n", user.savings);
        printf("You owe $%d in debt\n", user.debt);
        printf("You are %d years old with an annual income of $%d\n", user.age, user.income);
    }    
    return 0;
}
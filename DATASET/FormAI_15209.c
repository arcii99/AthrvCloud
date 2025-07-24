//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: recursive
#include<stdio.h>

void financePlanner(int years, float balance, float interestRate, float annualSavings);

int main()
{
    int years = 5;              // number of years in the plan
    float balance = 10000;      // starting balance
    float interestRate = 0.05;  // annual interest rate
    float annualSavings = 5000; // annual savings

    financePlanner(years, balance, interestRate, annualSavings);

    return 0;
}

void financePlanner(int years, float balance, float interestRate, float annualSavings)
{
    // Print the year, balance, and savings for the current year
    printf("Year %d : Balance: $%.2f | Savings: $%.2f\n", years, balance, annualSavings);

    // Base case: the plan has ended
    if(years == 0)
    {
        return;
    }

    // Recursively call the financePlanner function for the next year
    float interest = balance * interestRate;
    balance += interest + annualSavings;
    financePlanner(years-1, balance, interestRate, annualSavings);
}
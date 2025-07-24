//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: surprised
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    printf("Welcome to Personal Finance Planner App!\n");
    printf("Please enter your monthly income: ");
    float income;
    scanf("%f",&income);
    if(income<=0)
    {
        printf("Invalid Income! Program will terminate.\n");
        exit(0);
    }
    
    printf("Please enter your monthly expenses: ");
    float expenses;
    scanf("%f",&expenses);
    if(expenses<=0)
    {
        printf("Invalid Expenses! Program will terminate.\n");
        exit(0);
    }
    
    float savings=income-expenses;
    printf("Your savings every month: $%.2f\n",savings);
    if(savings<=0)
    {
        printf("You are spending more than you earn! Consider reducing your expenses.\n");
    }
    else if(savings<income/2)
    {
        printf("Good job on saving, but there's room for improvement. Try saving at least 50%% of your income.\n");
    }
    else if(savings<income)
    {
        printf("Excellent job on saving! You are saving more than 50%% of your income.\n");
    }
    else
    {
        printf("Wow! You are saving more than you earn! Please recheck your inputs.\n");
    }
    
    printf("Please enter your credit card balance: ");
    float card_balance;
    scanf("%f",&card_balance);
    if(card_balance<0)
    {
        printf("Invalid Balance! Program will terminate.\n");
        exit(0);
    }
    
    printf("Please enter the annual interest rate on the card: ");
    float card_rate;
    scanf("%f",&card_rate);
    if(card_rate<0)
    {
        printf("Invalid Interest Rate! Program will terminate.\n");
        exit(0);
    }
    
    float monthly_interest=card_rate/12.0/100.0;
    float months_left=ceil((-log(1-(card_balance*monthly_interest)/savings))/log(1+monthly_interest));
    printf("You will be able to pay off your credit card in %d months.\n",(int)months_left);
    
    float loan_balance, loan_rate;
    printf("Please enter your loan balance: ");
    scanf("%f",&loan_balance);
    if(loan_balance<0)
    {
        printf("Invalid Balance! Program will terminate.\n");
        exit(0);
    }
    printf("Please enter the annual interest rate on the loan: ");
    scanf("%f",&loan_rate);
    if(loan_rate<0)
    {
        printf("Invalid Interest Rate! Program will terminate.\n");
        exit(0);
    }
    
    float loan_monthly=loan_balance*(loan_rate/12.0/100.0)/(1-pow(1+(loan_rate/12.0/100.0),-36));
    printf("Your monthly loan payment is: $%.2f\n",loan_monthly);
    
    float investment_rate;
    printf("Please enter the expected annual rate of return on your investment: ");
    scanf("%f",&investment_rate);
    if(investment_rate<0)
    {
        printf("Invalid Rate! Program will terminate.\n");
        exit(0);
    }
    
    float years_to_reach_goal=log(1+(loan_balance/loan_monthly)*(investment_rate/100.0)/12.0)/log(1+(investment_rate/100.0)/12.0);
    printf("It will take %.2f years to reach your investment goal.\n",years_to_reach_goal);
    
    printf("Thank you for using Personal Finance Planner App. Happy Saving and Investing!\n");
    
    return 0;
}
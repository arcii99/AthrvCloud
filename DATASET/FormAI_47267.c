//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: excited
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct expense
{
    char category[100];
    float amount;
};

int main()
{
    int n;
    printf("Welcome to Personal Finance Planner!\n");
    printf("Enter the number of expenses: ");
    scanf("%d",&n);
    struct expense e[n];
    float total_expenses=0.0;

    for(int i=0;i<n;i++)
    {
        printf("Enter the category of expense%d: ",i+1);
        scanf("%s",e[i].category);
        printf("Enter the amount of expense%d: $",i+1);
        scanf("%f",&e[i].amount);
        total_expenses+=e[i].amount;
    }

    printf("\n------------------------\n");
    printf("YOUR EXPENSES OVERVIEW\n");
    printf("------------------------\n");
    for(int i=0;i<n;i++)
    {
        printf("%s\t\t$%.2f\n",e[i].category,e[i].amount);
    }

    printf("Total Expenses\t\t$%.2f\n",total_expenses);

    //calculating savings
    float income, savings;
    printf("\nEnter your total income: $");
    scanf("%f",&income);
    savings=income-total_expenses;
    printf("Your savings: $%.2f\n",savings);

    //budget planning
    int m;
    printf("\nHow many more categories would you like to add? ");
    scanf("%d",&m);
    struct expense b[m];
    float total_budget=0.0;

    for(int i=0;i<m;i++)
    {
        printf("Enter the category of expense%d: ",n+1+i);
        scanf("%s",b[i].category);
        printf("Enter the amount of expense%d: $",n+1+i);
        scanf("%f",&b[i].amount);
        total_budget+=b[i].amount;
    }

    printf("\n------------------------\n");
    printf("YOUR BUDGET\n");
    printf("------------------------\n");
    for(int i=0;i<n;i++)
    {
        printf("%s\t\t$%.2f\n",e[i].category,e[i].amount);
    }
    for(int i=0;i<m;i++)
    {
        printf("%s\t\t$%.2f\n",b[i].category,b[i].amount);
    }

    printf("Total Budget\t\t$%.2f\n",total_budget);
    float remaining_budget=total_budget-total_expenses;
    printf("Remaining Budget\t$%.2f\n",remaining_budget);

    if(savings>0)
    {
        printf("\nCongratulations! You are able to save $%.2f this month.",savings);
        if(remaining_budget>0)
        {
            printf("\nAlso, you have $%.2f remaining in your budget. You're doing great!",remaining_budget);
        }
        else if(remaining_budget==0)
        {
            printf("\nYou have used all of your budget. Spend wisely next time!");
        }
        else
        {
            printf("\nOops! You have exceeded your budget by $%.2f. Try to control your expenses next time.",-remaining_budget);
        }
    }
    else if(savings==0)
    {
        printf("\nYou have just been able to meet your expenses this month. Keep working on your budget!");
    }
    else
    {
        printf("\nOops! You have exceeded your income by $%.2f. Work on minimizing your expenses.",-savings);
    }

    printf("\n\nThank you for using Personal Finance Planner. Have a great day!");

    return 0;
}
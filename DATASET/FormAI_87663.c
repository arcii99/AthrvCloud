//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: Romeo and Juliet
#include <stdio.h>

int main()
{
    float income, expenses, savings;
    
    printf("Please enter your monthly income: ");
    scanf("%f", &income);
    
    printf("Please enter your monthly expenses: ");
    scanf("%f", &expenses);
    
    savings = income - expenses;
    
    printf("\n\n\n\n\n*********************************************\n");
    
    if(savings > 0)
    {
        printf("* Congratulations! You have saved %.2f this month! *\n", savings);
    }
    else if(savings < 0)
    {
        printf("* Oops! You have overspent by %.2f this month! *\n", savings * -1);
    }
    else
    {
        printf("* You have neither saved nor overspent this month! *\n");
    }
    
    printf("*********************************************\n");
    
    return 0;
}
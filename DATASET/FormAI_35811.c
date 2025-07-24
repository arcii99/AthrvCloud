//FormAI DATASET v1.0 Category: Expense Tracker ; Style: statistical
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct expense{
    char name[20];
    float amount;
};
int main()
{
    int n,i,j;
    float total_exp=0,avg;
    printf("Enter the number of expenses: ");
    scanf("%d",&n);
    struct expense e[n];
    for(i=0;i<n;i++)
    {
        printf("Enter expense name: ");
        scanf("%s",e[i].name);
        printf("Enter expense amount: ");
        scanf("%f",&e[i].amount);
        total_exp+=e[i].amount;
    }
    avg=total_exp/n;
    printf("\nExpenses Entered:\n");
    printf("SNo  Expense Name   Amount\n");
    for(i=0;i<n;i++)
    {
        printf("%2d    %-13s%.2f\n",i+1,e[i].name,e[i].amount);
    }
    printf("\nTotal Expenses: %.2f\n",total_exp);
    printf("Average Expense: %.2f\n",avg);
    printf("\nExpenses Above Average:");
    for(i=0;i<n;i++)
    {
        if(e[i].amount>avg)
            printf("\n%s: %.2f",e[i].name,e[i].amount);
    }
    return 0;
}
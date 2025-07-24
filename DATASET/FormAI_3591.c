//FormAI DATASET v1.0 Category: Expense Tracker ; Style: ultraprecise
#include<stdio.h>
#include<string.h>

struct expense //Structure for storing Expenses
{
    char category[20];
    float amount;
    char date[20];
};

int main()
{
    int n; //Number of expenses
    float total_spent = 0; //Total Spent money
    printf("Enter number of expenses: ");
    scanf("%d",&n);

    struct expense expenses[n]; //Array of expenses

    for(int i=0; i<n; i++) //Taking input of expenses
    {
        printf("\nEnter category of expense %d: ",i+1);
        scanf("%s",expenses[i].category);

        printf("Enter amount of expense %d: ",i+1);
        scanf("%f",&expenses[i].amount);

        printf("Enter date of expense (dd/mm/yyyy) %d: ",i+1);
        scanf("%s",expenses[i].date);

        total_spent += expenses[i].amount; //Calculate total_spent
    }

    printf("\n\n###############################################\n");
    printf("#           EXPENSE TRACKING SYSTEM            #\n");
    printf("###############################################\n\n");

    //Print the expenses
    printf("%-10s %-10s %-10s\n\n","Category","Amount","Date");
    for(int i=0; i<n; i++)
    {
        printf("%-10s %-10.2f %-10s\n",expenses[i].category,expenses[i].amount,expenses[i].date);
    }
    printf("Total spent: %.2f\n",total_spent);

    return 0;
}
//FormAI DATASET v1.0 Category: Expense Tracker ; Style: beginner-friendly
#include <stdio.h>

int main()
{
    int numExpenses;
    float expenseAmount, totalExpenses = 0;
    printf("Enter the total number of expenses: ");
    scanf("%d", &numExpenses);

    for(int i = 1; i <= numExpenses; i++)
    {
        printf("\nEnter expense amount %d: ", i);
        scanf("%f", &expenseAmount);

        if(expenseAmount < 0)
        {
            printf("Invalid expense amount entered. Please try again.\n");
            i--;
        }
        else
        {
            totalExpenses += expenseAmount;
        }
    }

    printf("\nTotal expenses entered: $%.2f\n", totalExpenses);

    return 0;
}
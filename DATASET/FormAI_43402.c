//FormAI DATASET v1.0 Category: Expense Tracker ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>

int main()
{
    /* Initialize variables */
    float expense[10];
    float total = 0, average = 0;
    int count = 0, i;

    /* Loop to get user input */
    for(i=0; i<10; i++)
    {
        printf("Enter expense #%d: ", i+1);
        scanf("%f", &expense[i]);

        /* Check for negative values */
        if(expense[i] < 0)
        {
            printf("Invalid input! Expense must be a positive number.\n");
            i--;
        }
        else
        {
            count++;
            total += expense[i];
        }

        /* Check if user wants to exit */
        if(expense[i] == 0)
        {
            break;
        }
    }

    /* Calculate average */
    if(count > 0)
    {
        average = total / count;
    }

    /* Output summary */
    printf("\nTotal expenses: $%.2f\n", total);
    printf("Average expense: $%.2f\n", average);

    return 0;
}
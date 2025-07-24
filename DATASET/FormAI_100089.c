//FormAI DATASET v1.0 Category: Expense Tracker ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

int main()
{
    float expenses[31]; // Array to hold expenses for each day of the month
    float total = 0; // Variable to hold the total expenses for the month

    // Loop to input expenses for each day of the month
    for(int i = 0; i < 31; i++)
    {
        printf("Enter expenses for day %d: ", i+1);
        scanf("%f", &expenses[i]);

        total += expenses[i]; // Add the expense to the total
    }

    printf("\nTotal expenses for the month: $%.2f\n", total);

    return 0;
}
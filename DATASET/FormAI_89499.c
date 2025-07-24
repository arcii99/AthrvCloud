//FormAI DATASET v1.0 Category: Expense Tracker ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, n;
    float total = 0, expense;

    printf("Enter the number of expenses: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter expense amount %d: ", i+1);
        scanf("%f", &expense);
        total += expense;
    }

    printf("Total expense: %.2f\n", total);

    return 0;
}
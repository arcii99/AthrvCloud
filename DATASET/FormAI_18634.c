//FormAI DATASET v1.0 Category: Expense Tracker ; Style: excited
#include<stdio.h>
#include<stdlib.h>

int main()
{
    printf("\n********** WELCOME TO EXPENSE TRACKER **********\n\n");
    int n, i;
    float total = 0.0, expense;
    printf("Enter the number of days you want to track your expenses for: ");
    scanf("%d", &n);
    float *list = (float*) malloc(n * sizeof(float));
    for (i = 0; i < n; i++)
    {
        printf("\nEnter the expenses for day %d: ", i+1);
        scanf("%f", &expense);
        *(list + i) = expense;
        total += expense;
    }
    printf("\n\nHere's the summary of your expenses:\n");
    printf("-------------------------------------------\n");
    printf("Day\t\tExpense\n");
    printf("-------------------------------------------\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t\t%.2f\n", i+1, *(list + i));
    }
    printf("-------------------------------------------\n");
    printf("Total\t\t%.2f\n", total);
    printf("\nYou spent an average of %.2f per day.\n", total/n);
    printf("\nThank you for using Expense Tracker!\n");
    free(list);
    return 0;
}
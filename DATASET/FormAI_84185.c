//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: innovative
#include <stdio.h>

#define SIZE 10

int jobSelect(int profit[], int deadline[]);
void swap(int *x, int *y);
void sortByProfit(int profit[], int deadline[]);

int main()
{
    int profit[SIZE] = {15, 35, 10, 30, 5, 25, 40, 20, 12, 18};
    int deadline[SIZE] = {4, 3, 5, 2, 7, 3, 4, 6, 2, 6};
    int maxProfit;

    maxProfit = jobSelect(profit, deadline);

    printf("Max Profit Possible: %d\n", maxProfit);

    return 0;
}

int jobSelect(int profit[], int deadline[])
{
    int jobsDone = 0;
    int maxProfit = 0;
    int slot = 0;

    sortByProfit(profit, deadline);

    for(int i = 0; i < SIZE; i++)
    {
        if(jobsDone < deadline[i])
        {
            maxProfit += profit[i];
            jobsDone++;
        }
    }

    return maxProfit;
}

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void sortByProfit(int profit[], int deadline[])
{
    for(int i = 0; i < SIZE; i++)
    {
        for(int j = 0; j < SIZE-i-1; j++)
        {
            if(profit[j] < profit[j+1])
            {
                swap(&profit[j], &profit[j+1]);
                swap(&deadline[j], &deadline[j+1]);
            }
        }
    }
}
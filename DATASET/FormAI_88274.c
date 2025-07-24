//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

void sortByQuantity(int *quantities, int *values, int n)
{
    int i, j, temp;

    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (quantities[i] < quantities[j]) {
                temp = quantities[i];
                quantities[i] = quantities[j];
                quantities[j] = temp;

                temp = values[i];
                values[i] = values[j];
                values[j] = temp;
            }
        }
    }
}

int knapsack(int capacity, int *quantities, int *values, int n)
{
    int currentCapacity = 0;
    int currentProfit = 0;
    int i;

    for (i = 0; i < n; i++) {
        if (currentCapacity + quantities[i] <= capacity) {
            currentCapacity += quantities[i];
            currentProfit += values[i];
        } else {
            int remain = capacity - currentCapacity;
            currentProfit += remain * (values[i] / quantities[i]);
            break;
        }
    }

    return currentProfit;
}

int main()
{
    int n = 5;
    int quantities[] = {14, 26, 12, 5, 17};
    int values[] = {75, 140, 60, 22, 85};

    int capacity = 30;

    sortByQuantity(quantities, values, n);

    int maxProfit = knapsack(capacity, quantities, values, n);

    printf("Max profit: %d\n", maxProfit);
    return 0;
}
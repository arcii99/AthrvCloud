//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

typedef struct Item {
    int value;
    int weight;
} Item;

int cmpfunc(const void* a, const void* b)
{
    double ratio1 = ((double)((Item*)a)->value) / ((double)((Item*)a)->weight);
    double ratio2 = ((double)((Item*)b)->value) / ((double)((Item*)b)->weight);
    if (ratio1 < ratio2)
        return 1;
    else if (ratio1 > ratio2)
        return -1;
    else
        return 0;
}

int scale(double ratio, int weight)
{
    return (int)(ratio * weight);
}

int getOptimalValue(Item* items, int capacity, int n)
{
    int i;
    double ratio;
    int weightSum = 0;
    int valueSum = 0;

    qsort(items, n, sizeof(Item), cmpfunc);

    for (i = 0; i < n; i++)
    {
        if (weightSum + items[i].weight <= capacity)
        {
            weightSum += items[i].weight;
            valueSum += items[i].value;
        }
        else
        {
            ratio = ((double)(capacity - weightSum)) / ((double)items[i].weight);
            valueSum += scale(ratio, items[i].value);
            break;
        }
    }

    return valueSum;
}

int main()
{
    Item items[] = { {60,10} ,{100,20} ,{120,30} };
    int capacity = 50;
    int n = sizeof(items) / sizeof(items[0]);

    int optimalValue = getOptimalValue(items, capacity, n);

    printf("Optimal value is: %d\n", optimalValue);

    return 0;
}
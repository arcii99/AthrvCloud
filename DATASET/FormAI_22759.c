//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: peaceful
#include<stdio.h>
#include<stdlib.h>

// structure for storing item details
struct item{
    int value;
    int weight;
};

// function to compare items based on value-to-weight ratio
int compare(const void *a, const void *b)
{
    struct item *itemA = (struct item *)a;
    struct item *itemB = (struct item *)b;
    double ratioA = (double)itemA->value/itemA->weight;
    double ratioB = (double)itemB->value/itemB->weight;
    if(ratioA < ratioB)
        return 1;
    else if(ratioA > ratioB)
        return -1;
    else
        return 0;
}

// function to compute maximum value that can be attained by filling the knapsack
double knapsack(int capacity, struct item items[], int num_items)
{
    double max_val = 0.0;
    int i;
    // sort items based on their value-to-weight ratio
    qsort(items, num_items, sizeof(items[0]), compare);
    // fill knapsack until capacity is fully utilized or no more items are left
    for(i=0;i<num_items;i++)
    {
        if(capacity <= 0)
            break;
        if(items[i].weight <= capacity)
        {
            max_val += items[i].value;
            capacity -= items[i].weight;
        }
        else
        {
            double fraction = (double)capacity/items[i].weight;
            max_val += fraction*items[i].value;
            capacity -= (int)(fraction*items[i].weight);
        }
    }
    // return maximum value that can be attained
    return max_val;
}

int main()
{
    int capacity = 50;
    struct item items[] = {{60, 10}, {100, 20}, {120, 30}};
    int num_items = sizeof(items)/sizeof(items[0]);
    double max_val = knapsack(capacity, items, num_items);
    printf("Maximum value that can be attained by filling the knapsack is %.2lf\n", max_val);
    return 0;
}
//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

/* Define a struct to represent an item */
typedef struct
{
    int weight;
    int value;
} Item;

/* Function to sort the items by value per unit weight in non-ascending order */
int compare(const void *a, const void *b)
{
    Item *itemA = (Item *)a;
    Item *itemB = (Item *)b;
    double ratioA = (double)itemA->value / itemA->weight;
    double ratioB = (double)itemB->value / itemB->weight;
    return ratioB - ratioA > 0 ? 1 : -1;
}

/* Function to implement the greedy algorithm */
void greedy_knapsack(Item items[], int n, int capacity)
{
    /* Sort the items by value per unit weight */
    qsort(items, n, sizeof(Item), compare);
    
    /* Initialize the variables */
    int i, current_weight = 0;
    double maximum_value = 0;
    
    /* Loop through the items */
    for (i = 0; i < n; i++)
    {
        if (current_weight + items[i].weight <= capacity)
        {
            /* Add the item to the knapsack */
            current_weight += items[i].weight;
            maximum_value += items[i].value;
        }
        else
        {
            /* Take a fraction of the item to fill the knapsack */
            double fraction = (double)(capacity - current_weight) / items[i].weight;
            current_weight += fraction * items[i].weight;
            maximum_value += fraction * items[i].value;
            break;
        }
    }
    
    /* Print the maximum value obtained */
    printf("Maximum value: %lf\n", maximum_value);
}

int main()
{
    /* Define an array of items */
    Item items[] = {{10, 60}, {20, 100}, {30, 120}, {40, 150}, {50, 180}, {60, 200}, {70, 220}, {80, 240}, {90, 260}, {100, 280}};
    
    /* Define the capacity of the knapsack */
    int capacity = 350;
    
    /* Calculate the size of the array */
    int n = sizeof(items) / sizeof(Item);
    
    /* Call the greedy algorithm */
    greedy_knapsack(items, n, capacity);
    
    /* Return 0 to indicate success */
    return 0;
}
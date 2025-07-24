//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: secure
#include <stdio.h>

// define structure for item
typedef struct Item {
    int weight;
    int value;
} Item;

void printKnapsack(Item* items, int n, int capacity) {
    // print header
    printf("%7s%7s%7s\n", "Item", "Weight", "Value");
    printf("====================\n");

    // print item details
    for(int i=0; i<n; i++) {
        printf("%7d%7d%7d\n", i+1, items[i].weight, items[i].value);
    }

    // print knapsack capacity
    printf("\nKnapsack Capacity: %d\n", capacity);
}

void knapsack(Item* items, int n, int capacity) {
    // sort items by value per unit weight in descending order
    for(int i=0; i<n-1; i++) {
        for(int j=i+1; j<n; j++) {
            double vpw1 = (double)items[i].value / items[i].weight;
            double vpw2 = (double)items[j].value / items[j].weight;
            if(vpw1 < vpw2) {
                Item temp = items[i];
                items[i] = items[j];
                items[j] = temp;
            }
        }
    }

    // initialize variables
    int remaining = capacity;
    int index = 0;
    double value = 0;

    // fill knapsack with items while there is capacity remaining
    while(remaining > 0 && index < n) {
        if(items[index].weight <= remaining) {
            remaining -= items[index].weight;
            value += items[index].value;
        } else {
            double fraction = (double)remaining / items[index].weight;
            value += fraction * items[index].value;
            remaining = 0;
        }
        index++;
    }

    // print results
    printf("\n====================\n");
    printf("Optimal Solution:\n");
    printf("Total Value: %.2f\n", value);
    printf("Items in Knapsack:\n");

    printKnapsack(items, n, capacity);
}

int main() {
    // initialize items
    Item items[] = {
        {6, 10},
        {2, 20},
        {3, 30},
        {5, 40},
        {1, 50},
        {4, 60}
    };
    int n = sizeof(items) / sizeof(items[0]);
    int capacity = 10;

    // run knapsack algorithm
    knapsack(items, n, capacity);

    return 0;
}
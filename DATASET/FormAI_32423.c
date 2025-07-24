//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: Dennis Ritchie
#include <stdio.h>

#define MAX_ITEMS 10

typedef struct {
    int weight;
    int value;
} Item;

// Returns the maximum value that can be put in a knapsack of capacity W
int knapsack(int capacity, Item items[]) {
    int i, j, max;
    int knap[MAX_ITEMS+1][capacity+1];

    for (i = 0; i <= MAX_ITEMS; i++) {
        for (j = 0; j <= capacity; j++) {
            if (i == 0 || j == 0) {
                knap[i][j] = 0;
            }
            else if (items[i-1].weight <= j) {
                knap[i][j] = (items[i-1].value + knap[i-1][j-items[i-1].weight] > knap[i-1][j]) ?
                    items[i-1].value + knap[i-1][j-items[i-1].weight] : knap[i-1][j];
            }
            else {
                knap[i][j] = knap[i-1][j];
            }
        }
    }

    return knap[MAX_ITEMS][capacity];
}

int main() {
    Item items[MAX_ITEMS] = {
        {2, 10},
        {3, 5},
        {5, 15},
        {7, 7},
        {1, 6},
        {4, 18},
        {1, 3},
        {6, 8},
        {8, 25},
        {3, 12}
    };
    int capacity = 20;
    int max_value;

    max_value = knapsack(capacity, items);

    printf("The maximum value that can be put in the knapsack is %d.\n", max_value);

    return 0;
}
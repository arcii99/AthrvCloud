//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: ephemeral
#include <stdio.h>

typedef struct {
    double weight;
    double value;
    double ratio;
} Item;

void fractionalKnapsack(Item items[], int n, double capacity) {
    // calculate the ratio of value per weight for each item
    for (int i = 0; i < n; i++) {
        items[i].ratio = items[i].value / items[i].weight;
    }
    
    // sort items in descending order of their value-to-weight ratio
    for (int i = 0; i < n-1; i++) {
        int max_i = i;
        for (int j = i+1; j < n; j++) {
            if (items[j].ratio > items[max_i].ratio) {
                max_i = j;
            }
        }
        Item temp = items[i];
        items[i] = items[max_i];
        items[max_i] = temp;
    }
    
    // fill the knapsack with items greedily
    double totalValue = 0.0;
    for (int i = 0; i < n; i++) {
        if (capacity <= 0.0) {
            break;
        }
        if (items[i].weight <= capacity) {
            totalValue += items[i].value;
            capacity -= items[i].weight;
        } else {
            totalValue += (capacity / items[i].weight) * items[i].value;
            capacity = 0.0;
        }
    }
    
    // print the total value of items in the knapsack
    printf("Total value of items in the knapsack: $%.2f\n", totalValue);
}

int main() {
    Item items[] = {{10, 60, 0}, {20, 100, 0}, {30, 120, 0}};
    int n = sizeof(items) / sizeof(items[0]);
    double capacity = 50.0;
    fractionalKnapsack(items, n, capacity);
    return 0;
}
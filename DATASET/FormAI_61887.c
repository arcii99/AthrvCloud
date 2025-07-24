//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: realistic
#include <stdio.h>

// Define struct for item
typedef struct {
    int weight;
    int value;
} Item;

// Greedy algorithm function to determine optimal items
void GreedyKnapsack(int capacity, Item* items, int n) {
    // Sort items by value-to-weight ratio
    for(int i = 0; i < n - 1; i++) {
        int maxIndex = i;
        for(int j = i + 1; j < n; j++) {
            if(items[j].value/items[j].weight > items[maxIndex].value/items[maxIndex].weight) {
                maxIndex = j;
            }
        }
        Item temp = items[i];
        items[i] = items[maxIndex];
        items[maxIndex] = temp;
    }
    
    // Add items to knapsack until capacity is reached
    int currentWeight = 0;
    int currentValue = 0;
    for(int i = 0; i < n; i++) {
        if(currentWeight + items[i].weight <= capacity) {
            currentWeight += items[i].weight;
            currentValue += items[i].value;
            printf("Added item %d with weight %d and value %d.\n", i+1, items[i].weight, items[i].value);
        }
    }
    printf("Total weight: %d\n", currentWeight);
    printf("Total value: %d\n", currentValue);
}

int main() {
    // Define knapsack capacity
    int capacity = 50;
    
    // Define array of items
    Item items[5];
    items[0].weight = 10;
    items[0].value = 60;
    items[1].weight = 20;
    items[1].value = 100;
    items[2].weight = 30;
    items[2].value = 120;
    items[3].weight = 40;
    items[3].value = 150;
    items[4].weight = 50;
    items[4].value = 200;
    
    // Call GreedyKnapsack function
    GreedyKnapsack(capacity, items, 5);
    
    return 0;
}
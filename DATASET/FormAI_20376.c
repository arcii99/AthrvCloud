//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: surprised
#include <stdio.h>

#define MAX_ITEMS 100
#define MAX_WEIGHT 500

typedef struct {
    int weight;
    int value;
} Item;

// Function to implement the fractional knapsack algorithm
double fractionalKnapsack(int n, Item items[]) {
    // Calculate the ratio of value to weight for each item
    double ratio[MAX_ITEMS];
    for(int i = 0; i < n; i++) {
        ratio[i] = (double)items[i].value / items[i].weight;
    }

    // Sort the items based on their ratio in non-increasing order
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(ratio[i] < ratio[j]) {
                double temp = ratio[i];
                ratio[i] = ratio[j];
                ratio[j] = temp;

                int temp_weight = items[i].weight;
                items[i].weight = items[j].weight;
                items[j].weight = temp_weight;

                int temp_value = items[i].value;
                items[i].value = items[j].value;
                items[j].value = temp_value;
            }
        }
    }

    // Add items to the knapsack until it is full
    int current_weight = 0;
    double knapsack_value = 0.0;
    for(int i = 0; i < n; i++) {
        if(current_weight + items[i].weight <= MAX_WEIGHT) {
            current_weight += items[i].weight;
            knapsack_value += items[i].value;
        } else {
            int remaining_weight = MAX_WEIGHT - current_weight;
            knapsack_value += ratio[i] * remaining_weight;
            break;
        }
    }

    return knapsack_value;
}

int main() {
    Item items[] = {{10, 60}, {20, 100}, {30, 120}};
    int n = sizeof(items) / sizeof(items[0]);

    double result = fractionalKnapsack(n, items);

    printf("The maximum value that can be obtained from the knapsack is: %.2f", result);

    return 0;
}
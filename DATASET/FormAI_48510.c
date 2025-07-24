//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: Ada Lovelace
#include <stdio.h>

// Definition of an item structure
struct Item {
    int value;
    int weight;
};

// Function to sort the items based on their value per unit weight ratio
void sort(struct Item items[], int n) {
    int i, j;
    struct Item temp;
    double ratio1, ratio2;

    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            ratio1 = (double)items[j].value / items[j].weight;
            ratio2 = (double)items[j+1].value / items[j+1].weight;
            if (ratio1 < ratio2) {
                temp = items[j];
                items[j] = items[j+1];
                items[j+1] = temp;
            }
        }
    }
}

// Function to solve Fractional Knapsack Problem using the Greedy Algorithm
double fractionalKnapsack(struct Item items[], int n, int W) {
    sort(items, n); // sort the items based on value per unit weight ratio
    int i;
    double totalValue = 0.0;
    int remainingWeight = W;

    for (i = 0; i < n; i++) {
        if (items[i].weight <= remainingWeight) {
            // add the entire weight of the current item to the knapsack
            totalValue += items[i].value;
            remainingWeight -= items[i].weight;
        } else {
            // add a fraction of the weight of the current item to the knapsack
            totalValue += (double)remainingWeight / items[i].weight * items[i].value;
            break; // terminate the loop as the knapsack capacity is filled
        }
    }

    return totalValue;
}

// Driver function to test the program
int main() {
    struct Item items[] = {{60, 10}, {100, 20}, {120, 30}};
    int n = sizeof(items) / sizeof(items[0]);
    int W = 50;
    double totalValue = fractionalKnapsack(items, n, W);

    printf("Maximum total value that can be obtained: %.2lf\n", totalValue);

    return 0;
}
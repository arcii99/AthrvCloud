//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: future-proof
#include <stdio.h>

//Structure to hold item details
struct Item {
    int value;
    int weight;
};

//Function to sort items in decreasing order of value/weight ratio
void sortItems(struct Item items[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            float ratio1 = (float) items[j].value / items[j].weight;
            float ratio2 = (float) items[j + 1].value / items[j + 1].weight;
            if (ratio1 < ratio2) {
                struct Item temp = items[j];
                items[j] = items[j + 1];
                items[j + 1] = temp;
            }
        }
    }
}

//Function to find maximum value that can be obtained by a fraction of the items
float fractionalKnapsack(struct Item items[], int n, int capacity) {
    sortItems(items, n);  //Sort items in decreasing order of value/weight ratio

    float totalValue = 0, weightPacked = 0;
    int i;
    for (i = 0; i < n; i++) {
        if (weightPacked + items[i].weight <= capacity) {
            //Pack the whole item if there's still space in the knapsack
            totalValue += items[i].value;
            weightPacked += items[i].weight;
        } else {
            //Pack fractional amount of the item if space is limited
            int remainingCapacity = capacity - weightPacked;
            totalValue += remainingCapacity * ((float) items[i].value / items[i].weight);
            break;  //All space has been used, no need to continue loop
        }
    }

    return totalValue;
}

//Driver code to test program
int main() {
    struct Item items[] = {{10, 2}, {20, 3}, {30, 4}, {40, 5}};
    int n = sizeof(items) / sizeof(items[0]);
    int capacity = 8;
    float maxTotalValue = fractionalKnapsack(items, n, capacity);
    printf("Maximum total value that can be obtained using fractional knapsack is: %f", maxTotalValue);
    return 0;
}
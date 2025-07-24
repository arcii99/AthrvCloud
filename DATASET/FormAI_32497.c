//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: cheerful
#include <stdio.h>

// Define the struct for each item in the backpack
struct Item {
    int weight;
    int value;
};

// Function to compare two items based on their value/weight ratio
int compRatio(const void *a, const void *b) {
    struct Item *itemA = (struct Item *)a;
    struct Item *itemB = (struct Item *)b;
    float ratioA = (float)itemA->value / itemA->weight;
    float ratioB = (float)itemB->value / itemB->weight;
    if (ratioA > ratioB) {
        return -1;
    } else if (ratioA < ratioB) {
        return 1;
    } else {
        return 0;
    }
}

// Main function to find the maximum value of items that can fit in the backpack
int findMaxValue(struct Item items[], int backpackCapacity, int numItems) {
    int i, currWeight = 0, maxValue = 0;
    // Sort the items based on their value/weight ratio
    qsort(items, numItems, sizeof(items[0]), compRatio);
    for (i = 0; i < numItems; ++i) {
        if (currWeight + items[i].weight <= backpackCapacity) {
            currWeight += items[i].weight;
            maxValue += items[i].value;
        } else {
            int remainingWeight = backpackCapacity - currWeight;
            maxValue += items[i].value * ((float)remainingWeight / items[i].weight);
            break;
        }
    }
    return maxValue;
}

// Driver function to test the program
int main() {
    struct Item backpack[] = {{10, 60}, {20, 100}, {30, 120}};
    int backpackCapacity = 50, numItems = sizeof(backpack) / sizeof(backpack[0]);
    int maxValue = findMaxValue(backpack, backpackCapacity, numItems);
    printf("The maximum value of items that can be packed in the backpack is: %d\n", maxValue);
    return 0;
}
//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

// Define a structure for storing the item and its value and weight
typedef struct item {
    int value;
    int weight;
}Item;

// Function to compare two items based on the value/weight ratio
int cmpfunc(const void* a, const void* b) {
    Item* item1 = (Item*)a;
    Item* item2 = (Item*)b;
    double ratio1 = ((double)item1->value / item1->weight);
    double ratio2 = ((double)item2->value / item2->weight);
    if(ratio1 > ratio2) { 
        return -1;
    } else if (ratio1 < ratio2) {
        return 1;
    } else {
        return 0;
    }
}

// Function to find the maximum value that can be obtained with the given capacity
int knapsack(Item items[], int n, int capacity) {
    qsort(items, n, sizeof(Item), cmpfunc);  //Sort the items based on the value/weight ratio.
    int* solution = (int*)malloc((capacity+1)*sizeof(int));  //Create a solution array to store the maximum values for each capacity.
    for(int i=0; i<=capacity; i++) { 
        solution[i] = 0;
    }
    for(int i=0; i<n; i++) {
        for(int j=capacity; j>=items[i].weight; j--) {
            solution[j] = solution[j-items[i].weight] + items[i].value > solution[j] ? solution[j-items[i].weight] + items[i].value : solution[j];
        }
    }
    int result = solution[capacity];
    free(solution);
    return result;
}

int main() {
    Item items[] = {{60, 10}, {100, 20}, {120, 30}}; //Test items
    int n = sizeof(items)/sizeof(items[0]);
    int capacity = 50;  //Test capacity
    int max_value = knapsack(items, n, capacity);
    printf("The maximum value that can be obtained with capacity %d is %d.\n", capacity, max_value);
    return 0;
}
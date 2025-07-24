//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: grateful
#include <stdio.h>

// our struct for items
struct Item {
    int value;
    int weight;
};

// our function to return max of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// our main function
int main() {
    // our array of items
    struct Item items[] = {{60, 10}, {100, 20}, {120, 30}};

    // our capacity and size
    int capacity = 50;
    int numItems = sizeof(items) / sizeof(items[0]);

    // our array to store values
    int K[numItems + 1][capacity + 1];

    // for loop to build out our K array
    for (int i = 0; i <= numItems; i++) {
        for (int w = 0; w <= capacity; w++) {
            if (i == 0 || w == 0) {
                K[i][w] = 0;
            } else if (items[i - 1].weight <= w) {
                K[i][w] = max(items[i - 1].value + K[i - 1][w - items[i - 1].weight], K[i - 1][w]);
            } else {
                K[i][w] = K[i - 1][w];
            }
        }
    }

    // print out our results
    printf("The optimal value is: %d\n", K[numItems][capacity]);

    return 0;
}
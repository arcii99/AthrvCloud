//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: single-threaded
#include <stdio.h>

struct Item {
    int value;
    int weight;
};

int knapsack(int capacity, struct Item items[], int size) {
    int taken = 0;
    int current_size = 0;

    while (current_size < size && capacity > 0) {
        int max = 0;
        int max_index = -1;

        for (int i = 0; i < size; i++) {
            if (items[i].value > max && items[i].weight <= capacity) {
                max = items[i].value;
                max_index = i;
            }
        }

        if (max_index == -1) {
            break;
        }

        taken += max;
        capacity -= items[max_index].weight;
        current_size++;
    }

    return taken;
}

int main() {
    struct Item items[6] = {{10, 2}, {5, 3}, {15, 5}, {7, 7}, {6, 1}, {18, 4}};
    int capacity = 15;
    int size = 6;

    int result = knapsack(capacity, items, size);

    printf("Maximum value that can be taken = %d\n", result);

    return 0;
}
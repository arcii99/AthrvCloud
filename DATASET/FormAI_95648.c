//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: safe
#include <stdio.h>
#include <stdlib.h>

struct Item {
    int value;
    int weight;
};

int compare(const void* a, const void* b) {
    double ratio1 = ((struct Item*) a)->value / (double) ((struct Item*) a)->weight;
    double ratio2 = ((struct Item*) b)->value / (double) ((struct Item*) b)->weight;
    return ratio2 > ratio1 ? 1 : -1;
}

double knapsack(struct Item items[], int n, int W) {
    qsort(items, n, sizeof(struct Item), compare);
    int i;
    double current_weight = 0;
    double current_value = 0;
    for(i = 0; i < n; i++) {
        if(current_weight + items[i].weight <= W) {
            current_weight += items[i].weight;
            current_value += items[i].value;
        } else {
            double remaining_weight = W - current_weight;
            current_value += remaining_weight * (items[i].value / (double) items[i].weight);
            break;
        }
    }
    return current_value;
}

int main() {
    struct Item items[] = {{60, 10}, {100, 20}, {120, 30}};
    int n = sizeof(items) / sizeof(items[0]);
    int W = 50;
    printf("Maximum value that can be obtained = %.2f\n", knapsack(items, n, W));
    return 0;
}
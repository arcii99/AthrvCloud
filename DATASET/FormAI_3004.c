//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: genious
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int weight, value;
    float ratio;
} Item;

int cmp(const void *a, const void *b) {
    const Item *ia = (const Item *) a;
    const Item *ib = (const Item *) b;
    return (ib->ratio - ia->ratio) > 0 ? 1 : -1;
}

float fractional_knapsack(int n, Item *items, int capacity) {
    int i;
    float profit = 0.0;
    qsort(items, n, sizeof(Item), cmp);
    for (i = 0; i < n; i++) {
        if (items[i].weight <= capacity) { // take the whole item
            capacity -= items[i].weight;
            profit += items[i].value;
        } else { // take a fraction of the item
            profit += items[i].ratio * capacity;
            capacity = 0;
        }
        if (capacity == 0) break; // stop if the knapsack is full
    }
    return profit;
}

int main() {
    int n, capacity, i;
    printf("Enter the number of items and the capacity of the knapsack:\n");
    scanf("%d %d", &n, &capacity);
    Item items[n];
    printf("Enter the weight and value of each item:\n");
    for (i = 0; i < n; i++) {
        scanf("%d %d", &items[i].weight, &items[i].value);
        items[i].ratio = (float) items[i].value / items[i].weight;
    }
    float profit = fractional_knapsack(n, items, capacity);
    printf("The maximum profit is %f\n", profit);
    return 0;
}
//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 100

struct item {
    int weight;
    int value;
};

struct knapsack {
    int capacity;
    int weight;
    int value;
    struct item items[MAX_ITEMS];
};

void add_item(struct knapsack *k, struct item i) {
    if (k->weight + i.weight <= k->capacity) {
        k->items[k->weight] = i;
        k->weight += i.weight;
        k->value += i.value;
    }
}

struct item create_item(int weight, int value) {
    struct item i;
    i.weight = weight;
    i.value = value;
    return i;
}

struct knapsack create_knapsack(int capacity) {
    struct knapsack k;
    k.capacity = capacity;
    k.value = 0;
    k.weight = 0;
    return k;
}

void print_knapsack(struct knapsack *k) {
    printf("Knapsack (capacity: %d, weight: %d, value: %d):\n", k->capacity, k->weight, k->value);
    for (int i = 0; i < k->weight; i++) {
        printf(" - %d:%d\n", k->items[i].weight, k->items[i].value);
    }
}

int cmp(const void *a, const void *b) {
    struct item *ia = (struct item *)a;
    struct item *ib = (struct item *)b;
    return ia->value / ia->weight - ib->value / ib->weight;
}

int main() {
    struct knapsack k = create_knapsack(20);
    struct item items[] = {
        create_item(5, 10),
        create_item(7, 15),
        create_item(3, 8),
        create_item(4, 12),
        create_item(9, 22),
        create_item(6, 18),
        create_item(1, 2),
        create_item(2, 5),
        create_item(8, 21),
        create_item(10, 25),
        create_item(4, 11),
        create_item(5, 13),
        create_item(3, 7),
        create_item(9, 24),
        create_item(2, 6),
        create_item(6, 17)
    };
    int n = sizeof(items) / sizeof(struct item);
    qsort(items, n, sizeof(struct item), cmp);
    for (int i = n - 1; i >= 0; i--) {
        add_item(&k, items[i]);
    }
    print_knapsack(&k);
    return 0;
}
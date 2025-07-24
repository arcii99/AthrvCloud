//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: beginner-friendly
#include<stdio.h>
#include<stdlib.h>

struct item {
    int weight;
    int profit;
};

int cmpfunc(const void *a, const void *b) {
    struct item *ai = (struct item *) a;
    struct item *bi = (struct item *) b;
    return (bi->profit / bi->weight) - (ai->profit / ai->weight);
}

int main() {
    int n, capacity, i;
    printf("\nEnter the number of items: ");
    scanf("%d", &n);
    struct item items[n];
    printf("\nEnter the capacity of the knapsack: ");
    scanf("%d", &capacity);
    printf("\nEnter the weight and profit of each item: \n");

    for (i=0; i<n; i++) {
        scanf("%d%d",&items[i].weight,&items[i].profit);
    }

    qsort(items, n, sizeof(struct item), cmpfunc);

    int cur_weight = 0;
    double max_profit = 0.0;

    for (i=0; i<n; i++) {
        if (cur_weight + items[i].weight <= capacity) {
            cur_weight += items[i].weight;
            max_profit += items[i].profit;
        } else {
            int remaining = capacity - cur_weight;
            max_profit += items[i].profit * ((double) remaining / items[i].weight);
            break;
        }
    }

    printf("\nThe maximum profit is %.2lf\n", max_profit);
    return 0;
}
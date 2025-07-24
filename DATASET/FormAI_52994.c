//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100
#define MAX_WT 1000

struct item {
    int wt, val;
};

int cmp(const void *a, const void *b) {
    return ((struct item *)a)->val < ((struct item *)b)->val;
}

int main() {
    int n, W, wt_sum = 0, val_sum = 0, i;
    struct item items[MAX_N];
    double ratio[MAX_N];

    printf("Enter the number of items: ");
    scanf("%d", &n);

    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &W);

    printf("Enter the weight and value of each item:\n");
    for (i = 0; i < n; i++) {
        scanf("%d %d", &items[i].wt, &items[i].val);
        ratio[i] = items[i].val / (double)items[i].wt;
    }

    qsort(items, n, sizeof(struct item), cmp);

    for (i = 0; i < n && wt_sum + items[i].wt <= W; i++) {
        wt_sum += items[i].wt;
        val_sum += items[i].val;
    }

    if (i < n) {
        val_sum += (W - wt_sum) * ratio[i];
    }

    printf("Maximum value: %d\n", val_sum);

    return 0;
}
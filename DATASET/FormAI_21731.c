//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: active
#include<stdio.h>
#include<stdlib.h>

struct item {
    int id, weight, value;
};

int cmpfunc (const void * a, const void * b) {
   return (((struct item*)b)->value / (float)((struct item*)b)->weight) - (((struct item*)a)->value / (float)((struct item*)a)->weight);
}

void knapsack(struct item* items, int n, int capacity) {
    qsort(items, n, sizeof(struct item), cmpfunc);
    int i;
    float total_value = 0, loaded_weight = 0;
    for(i = 0 ; i < n && loaded_weight < capacity ; i++) {
        if(items[i].weight + loaded_weight <= capacity) {
            printf("Item %d loaded. Weight: %d. Value: %d.\n", items[i].id, items[i].weight, items[i].value);
            total_value += items[i].value;
            loaded_weight += items[i].weight;
        } else {
            int remaining = capacity - loaded_weight;
            total_value += items[i].value * ((float)remaining / items[i].weight);
            printf("Item %d partially loaded. Loaded weight: %d. Value: %.2f.\n", items[i].id, remaining, items[i].value * ((float)remaining / items[i].weight));
            loaded_weight += remaining;
        }
    }
    printf("Total value of the items loaded: %.2f\n", total_value);
}

int main() {
    int capacity, i, n;
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);
    printf("Enter the number of items to consider: ");
    scanf("%d", &n);
    struct item* items = malloc(sizeof(struct item)*n);
    printf("Enter the details of each item:\n");
    for(i = 0 ; i < n ; i++) {
        printf("Item %d:\n", i+1);
        items[i].id = i+1;
        printf("Weight: ");
        scanf("%d", &items[i].weight);
        printf("Value: ");
        scanf("%d", &items[i].value);
    }
    knapsack(items, n, capacity);
    return 0;
}
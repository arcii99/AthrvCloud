//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int weight;
    int value;
} item;

item *items;
int knapsack(int capacity, int n);

int main() {
    int capacity, n;
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);
    printf("Enter the number of items: ");
    scanf("%d", &n);
    items = malloc(n * sizeof(item));
    for (int i = 0; i < n; i++) {
        printf("Enter the weight and value of item %d: ", i + 1);
        scanf("%d %d", &items[i].weight, &items[i].value);
    }
    int max_value = knapsack(capacity, n);
    printf("The maximum value in the knapsack is: %d\n", max_value);
    free(items);
    return 0;
}

int knapsack(int capacity, int n) {
    int values[capacity + 1];
    for (int i = 0; i <= capacity; i++) {
        values[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        for (int j = capacity; j >= items[i].weight; j--) {
            values[j] = (values[j] > values[j - items[i].weight] + items[i].value) ? values[j] : values[j - items[i].weight] + items[i].value;
        }
    }
    return values[capacity];
}
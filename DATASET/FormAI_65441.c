//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

// define structure for each item in the knapsack
typedef struct {
    int value;
    int weight;
    double ratio;
} item;

// helper function to compare item ratios
int compare_ratios(const void* a, const void* b) {
    item ia = *(item*)a;
    item ib = *(item*)b;
    return (ia.ratio < ib.ratio) ? 1 : -1;
}

// main function
int main() {
    int n; // number of items
    printf("Enter the number of items: ");
    scanf("%d", &n);

    item knapsack[n]; // array of items

    // get user inputs for each item
    printf("Enter value and weight for each item:\n");
    for(int i=0; i<n; i++) {
        printf("Item %d: ", i+1);
        scanf("%d %d", &knapsack[i].value, &knapsack[i].weight);
        knapsack[i].ratio = (double)knapsack[i].value / knapsack[i].weight;
    }

    int capacity;
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);

    // sort items in descending order of their ratios
    qsort(knapsack, n, sizeof(item), compare_ratios);

    // fill the knapsack with items greedily
    int i=0;
    double total_value = 0;
    while(capacity > 0 && i<n) {
        int weight = knapsack[i].weight;
        if(weight > capacity)
            weight = capacity;

        total_value += weight * knapsack[i].ratio;
        capacity -= weight;
        i++;
    }

    printf("The total value of items in the knapsack is %.2f", total_value);

    return 0;
}
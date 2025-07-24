//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: beginner-friendly
#include <stdio.h> 

// Structure to hold information about each item
struct Item { 
    int value; 
    int weight; 
}; 

// Function to sort items by their value-to-weight ratio
int cmp(const void *a, const void *b) { 
    struct Item *a1 = (struct Item *)a; 
    struct Item *b1 = (struct Item *)b; 
    double ratio_a = (double)a1->value / a1->weight; 
    double ratio_b = (double)b1->value / b1->weight; 
    return ratio_b > ratio_a; 
} 

// Function to calculate maximum value using greedy approach
double fractionalKnapsack(int W, struct Item arr[], int n) { 
    // Sort items by their value-to-weight ratio
    qsort(arr, n, sizeof(struct Item), cmp); 

    int curr_weight = 0;
    double curr_value = 0.0;

    // Keep adding items until the knapsack is full
    for (int i = 0; i < n && curr_weight < W; i++) { 
        if (curr_weight + arr[i].weight <= W) { 
            curr_weight += arr[i].weight; 
            curr_value += arr[i].value; 
        } 
        else { 
            int remaining_weight = W - curr_weight; 
            curr_value += arr[i].value * ((double) remaining_weight / arr[i].weight); 
            curr_weight = W; 
        } 
    }

    return curr_value;
} 

int main() { 
    // Sample data
    struct Item arr[] = {{60, 10}, {100, 20}, {120, 30}}; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    int W = 50; 

    // Calculate maximum value using greedy approach
    double max_value = fractionalKnapsack(W, arr, n); 
    printf("Maximum value in the knapsack: %.2f", max_value);

    return 0;
}